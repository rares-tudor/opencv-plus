#include "sobel_bgd_subtraction.h"
#include "sobel_edge_detection.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

sobel_bgd_subtraction::sobel_bgd_subtraction(std::string path)
{
	this->path = path;
}

void sobel_bgd_subtraction::subtract_bgd()
{
	cv::Mat original = cv::imread(path, cv::IMREAD_COLOR);
	sobel_edge_detection sobel_edge(path);

	cv::Mat edges;

	sobel_edge.get_edges(edges);

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

	cv::imshow("Sobel Background Separation", result); // display the result
	cv::waitKey(0);
}