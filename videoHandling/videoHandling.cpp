#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

int main()
{
    cv::VideoCapture video(0);

    if (!video.isOpened())
        return -1;

    cv::Mat frame;

    // Get video resolution
    int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
    int frameHeigth = video.get(cv::CAP_PROP_FRAME_HEIGHT);

    cv::VideoWriter output("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, cv::Size(frameWidth, frameHeigth));

    // Loop through available frames
    while (video.read(frame))
    {

        cv::imshow("Video feed", frame);

        // Write video frame to output
        output.write(frame);
        int num = cvWaitKey(1);
        std::cout << num << " ";
        if (num > 0)
            break;

    } // end while (video.read(frame))

    output.release();
    video.release();

    // Destroy all windows
    cv::destroyAllWindows();

    return 0;
}