#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/tracking/tldDataset.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/core.hpp>
#include <iostream>

static const std::string OPENCV_WINDOW = "Image window";
bool flex = true;
cv::Rect trackingBox;
cv::Ptr<cv::Tracker> tracker = cv::TrackerCSRT::create();
cv::Mat frame;
int i = 0;

void initialie(cv::Mat framed)
{
    //cv::InputArray fur = framed;
    trackingBox = cv::selectROI(framed, false, false);
    tracker->init(framed, trackingBox);
}

class ImageConverter
{
    ros::NodeHandle nh_;
    image_transport::ImageTransport it_; // works only if wriiten inside a class
    image_transport::Subscriber image_sub_;

public:
    ImageConverter() : it_(nh_)
    {
        // Subscribe to input video feed and publish output video feed
        image_sub_ = it_.subscribe("firefly/camera_nadir/image_raw", 20, &ImageConverter::imageCb, this);
    }

    void imageCb(const sensor_msgs::ImageConstPtr &msg)
    {
        cv_bridge::CvImagePtr cv_ptr;
        try
        {
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        }
        catch (cv_bridge::Exception &e)
        {
            ROS_ERROR("cv_bridge exception: %s", e.what());
            return;
        }

        frame = cv_ptr->image;
        if (flex == true)
        {
            // initialie(frame);
            trackingBox = cv::selectROI(frame, false, false);
            tracker->init(frame, trackingBox);
            flex = false;
        }
        //Update the tracker and draw the rectangle around target if update was successful
        if (tracker->update(frame, trackingBox))
        {
            // std::cout<<"yay\n";
            cv::rectangle(frame, trackingBox, cv::Scalar(255, 0, 0), 2, 1, 0);
        }
        // Display the frame
        cv::imshow("Video feed", frame);
        cv::waitKey(3);
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_converter");
    ImageConverter ic;
    ros::spin();
    return 0;
}