#pragma once
#include <string>
#include <opencv2/core.hpp>

class sobel_edge_detection
{
private:
	std::string path;

public:
	sobel_edge_detection(const std::string& path);

public:
	void get_edges_and_display();
	void get_edges(cv::Mat& edges);
};

