#include "canny_bgd_subtraction.h"
#include "canny_edge_detection.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <vector>

canny_bgd_separator::canny_bgd_separator(const std::string& rpath, const std::string& wpath)
{
	this->rpath = rpath;
}

void canny_bgd_separator::subtract_bgd() 
{
	canny_edge_detection edgeDetector(rpath);

	cv::Mat original = cv::imread(rpath, cv::IMREAD_COLOR); // read the original image

	cv::Mat edges;
	edgeDetector.get_edges(edges);

	cv::dilate(edges, edges, cv::Mat()); // smooth out the edges
	cv::erode(edges, edges, cv::Mat());

	std::vector<std::vector<cv::Point>> contours;

	cv::findContours(edges, contours, cv::RetrievalModes::RETR_LIST, cv::CHAIN_APPROX_NONE); // find contours in the edges img

	std::sort(contours.begin(), contours.end(), [](const std::vector<cv::Point>& c1, const std::vector<cv::Point>& c2) 
		{
			return cv::contourArea(c1, false) < cv::contourArea(c2, false);
		}); // sort all contours by area

	cv::Mat mask;
	mask.create(edges.size(), edges.type());
	mask = cv::Scalar::all(0.0); // set all pixels of mask to 0

	cv::fillConvexPoly(mask, contours[contours.size() - 1].data(), contours[contours.size() - 1].size(), (255)); // fill the largest contour

	cv::dilate(mask, mask, cv::Mat(), cv::Point(-1, -1), 10); // smooth out the mask
	cv::erode(mask, mask, cv::Mat(), cv::Point(-1, -1), 10);
	//cv::GaussianBlur(mask, mask, cv::Size(3, 3), 0, 0);

	cv::Mat result;
	result.create(original.size(), original.type());
	result = cv::Scalar::all(0.0); // set all pixels of result img to 0

	original.copyTo(result, mask); // apply mask to result img

	cv::imshow("Detected Edges", result); // display the result
	cv::waitKey(0);
}
