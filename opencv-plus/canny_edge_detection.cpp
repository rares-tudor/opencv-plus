#include "canny_edge_detection.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>


canny_edge_detection::canny_edge_detection(const std::string& rpath, const std::string& wpath)
{
	this->rpath = rpath;
	this->wpath = wpath;
}

void canny_edge_detection::canny_threshold(int, void*)
{
	double low_threshold = (double)low_thresh;
	cv::blur(img_gray, edges, cv::Size(3,3));
	cv::Canny(edges, edges, low_thresh, low_threshold* RATIO, KERNEL_SIZE);

	dst = cv::Scalar::all(0);
	img.copyTo(dst, edges);

	if (sizeof(wpath) != 0)
	{
		std::ofstream outFile;
		outFile.open(wpath, std::ios::binary);
		outFile << "P3" << "\n"
			<< img.cols << " "
			<< img.rows << "\n"
			<< 255 << "\n";
		outFile << img;
		return;
	}
}

void canny_edge_detection::get_edges()
{
	get_edges(edges);
	//cv::imshow("Detected Edges", edges); // display the result
	//cv::waitKey(0);
}


void canny_edge_detection::get_edges(cv::Mat& edges)
{
		img = cv::imread(cv::samples::findFile(rpath), cv::IMREAD_COLOR); // read img from file

		edges.create(img.size(), img.type());

		cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY); // convert img to grayscale

		//cv::blur(grayScale, grayScale, cv::Size(3, 3));
		cv::namedWindow("Test", cv::WINDOW_AUTOSIZE); // testing purposes

		canny_threshold(0, 0); // apply Canny edge detection with default parameters
}