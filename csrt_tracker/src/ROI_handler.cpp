#include <csrt_tracker/ROI.hpp>

int main(int argc, char** argv) {
    ros::init(argc, argv, "ROI_handler");
    ImageConverter ic;
    ros::spin();
    return 0;
}