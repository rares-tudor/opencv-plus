#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>

#pragma once
class bs_mog2
{
public:
	bs_mog2(std::string fpath);
	~bs_mog2();
	int exec_bs_mog2();

private:
	cv::Ptr<cv::BackgroundSubtractor> p_bs = cv::createBackgroundSubtractorMOG2();
	std::string path;
};

