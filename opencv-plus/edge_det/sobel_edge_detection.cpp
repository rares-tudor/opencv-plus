#include "sobel_edge_detection.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "grab_cut.h"

sobel_edge_detection::sobel_edge_detection(const std::string& rpath, const std::string& wpath)
{
	this->rpath = rpath;
	this->wpath = wpath;
}

void sobel_edge_detection::get_edges(cv::Mat& edges)
{
	cv::Mat img = cv::imread(rpath, cv::IMREAD_COLOR);

	cv::GaussianBlur(img, img, cv::Size(5, 5), 0, 0);

	cv::cvtColor(img, img, cv::ColorConversionCodes::COLOR_BGR2GRAY);

	cv::Mat gradX, gradY;
	cv::Mat absGradX, absGradY;

	cv::Sobel(img, gradX, 3, 1, 0);
	cv::convertScaleAbs(gradX, absGradX);

	cv::Sobel(img, gradY, 3, 1, 0);
	cv::convertScaleAbs(gradY, absGradY);

	cv::addWeighted(absGradX, 0.5, absGradY, 0.5, 0, edges);
	cv::threshold(edges, edges, 25, 255, 3);
}

void sobel_edge_detection::get_edges_and_display()
{
	cv::Mat edges;
	get_edges(edges);

	grab_cut grabCut(rpath, wpath);
	grabCut.exec_grc();

	cv::imshow("Sobel Edge Detection", edges);
	cv::waitKey(0);
}