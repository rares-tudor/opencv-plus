#pragma once
#include <string>
#include <opencv2/core.hpp>

class sobel_edge_detection
{
private:
	std::string rpath, wpath;

public:
	sobel_edge_detection(const std::string& rpath, const std::string& wpath);

public:
	void get_edges_and_display();
	void get_edges(cv::Mat& edges);
};

