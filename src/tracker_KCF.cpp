#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/core.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/tracking/tracking.hpp>
#include <opencv2/tracking/tldDataset.hpp>

// using namespace cv;
using namespace std;

int main() {

	// Create video capturing object
	// 0 opens default camera, otherwise filename as argument
	cv::VideoCapture video(0);

	// Check that video is opened
	if (!video.isOpened()) return -1;

	// For saving the frame
	cv::Mat frame;

	// Get video resolution
	int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
	int frameHeigth = video.get(cv::CAP_PROP_FRAME_HEIGHT);

	// Create video writer object
	// cv::VideoWriter output("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeigth));
	// if want to write video to output.. uncomment line 31, 52, 60.

	// Create tracker, select region-of-interest (ROI) and initialize the tracker
	cv::Ptr<cv::Tracker> tracker = cv::TrackerKCF::create();

	while (true) {
		video.read(frame);
		cv::imshow("ROI Selector", frame);
		int k = cv::waitKey(30) & 0xff;
		if (k == 27) 
			break;
	}
	cv::destroyWindow("ROI Selector");

	cv::Rect trackingBox = cv::selectROI(frame, true);
	tracker->init(frame, trackingBox);

	// Loop through available frames
	while (video.read(frame)) {

		// Update the tracker and draw the rectangle around target if update was successful
		if (tracker->update(frame, trackingBox)) {
			cv::rectangle(frame, trackingBox, cv::Scalar(255, 0, 0), 2, 8);
		}

		// Display the frame
		cv::imshow("Video feed", frame);

		// Write video frame to output
		// output.write(frame);

		// For breaking the loop
		if (cv::waitKey(25) >= 0) break;

	} // end while (video.read(frame))

	  // Release video capture and writer
	// output.release();
	video.release();

	// Destroy all windows
	cv::destroyAllWindows();

	return 0;

}
