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

// Global Variables
static const std::string OPENCV_WINDOW = "Image window";
bool flex = true;
cv::Rect trackingBox;
cv::Ptr<cv::Tracker> tracker = cv::TrackerCSRT::create();
cv::Mat frame;
int i = 0;

// Callback functions
void initialize(cv::Mat framed);

// Base Class
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
    void imageCb(const sensor_msgs::ImageConstPtr &msg);
};