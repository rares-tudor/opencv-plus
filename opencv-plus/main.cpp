#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main()
{

	cv::Mat image = cv::Mat::zeros(300, 600, CV_8UC3);
	cv::imshow("grab_cut", image);
	cv::waitKey(0);
	return 0;
}