#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>

#pragma once
class bs_knn
{
public:
	bs_knn(std::string fpath);
	~bs_knn();
	int exec_bs_knn();
private:
	cv::Ptr<cv::BackgroundSubtractor> p_bs = cv::createBackgroundSubtractorKNN();
	std::string path;
};

