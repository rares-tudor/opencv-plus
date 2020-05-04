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
private:
	std::string rpath, wpath;

private:
	cv::Ptr<cv::BackgroundSubtractor> p_bs = cv::createBackgroundSubtractorKNN();

public:
	int exec_bs_knn();

public:
	bs_knn(const std::string& rpath,  const std::string& wpath);
	~bs_knn();

};

