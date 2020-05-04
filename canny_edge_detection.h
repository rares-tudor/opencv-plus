#pragma once
#include <opencv2/imgproc.hpp>
#include <string>

class canny_edge_detection
{
private:
	std::string path;
	const double MIN_THRESH = 0.0;
	const double MAX_THRESH = 300.0;
	const int KERNEL_SIZE = 3;

public:
	canny_edge_detection(const std::string& path);

public:
	void get_edges();
	void get_edges(cv::Mat& img);
};

