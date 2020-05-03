#include "canny_edge_detection.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

canny_edge_detection::canny_edge_detection(const std::string& path)
{
	this->path = path;
}

void canny_edge_detection::get_edges()
{
	cv::Mat edges;

	get_edges(edges);

	cv::imshow("Detected Edges", edges); // display the result
	cv::waitKey(0);
}

void canny_edge_detection::get_edges(cv::Mat& edges)
{
	cv::Mat img = cv::imread(cv::samples::findFile(path), cv::IMREAD_COLOR); // read img from file

	edges.create(img.size(), img.type());

	cv::Mat grayScale;
	cv::cvtColor(img, grayScale, cv::COLOR_BGR2GRAY); // convert img to grayscale

	//cv::blur(grayScale, grayScale, cv::Size(3, 3));

	cv::Canny(grayScale, edges, MIN_THRESH, MAX_THRESH, KERNEL_SIZE); // apply Canny edge detection with default parameters
}