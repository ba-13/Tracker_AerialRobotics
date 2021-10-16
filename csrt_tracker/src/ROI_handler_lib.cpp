#include <csrt_tracker/ROI.hpp>

void ImageConverter::imageCb(const sensor_msgs::ImageConstPtr& msg) {
    cv_bridge::CvImagePtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    frame = cv_ptr->image;
    if (!initiated_ROI) {
        trackingBox = cv::selectROI(frame, false, false);
        tracker->init(frame, trackingBox);
        initiated_ROI = true;
    }
    // Update the tracker and draw the rectangle around target if update was successful
    if (tracker->update(frame, trackingBox)) {
        cv::rectangle(frame, trackingBox, cv::Scalar(255, 0, 0), 2, 1, 0);
    }
    // Display the frame
    cv::imshow("Video feed", frame);
    cv::waitKey(3);
}