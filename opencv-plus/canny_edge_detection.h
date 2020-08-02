#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

class canny_edge_detection
{
private:
	std::string rpath, wpath;
	int low_thresh = 20;
	const double MIN_THRESH = 0.0, MAX_THRESH = 100.0;
	const int KERNEL_SIZE = 3, RATIO = 3;
	cv::Mat img, img_gray, dst, edges;

public:
	canny_edge_detection(const std::string& rpath, const std::string& wpath);
	void canny_threshold(int, void*);
	void get_edges();
	void get_edges(cv::Mat& img);
};

