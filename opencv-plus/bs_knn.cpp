#include "bs_knn.h"

bs_knn::bs_knn(const std::string& rpath, const std::string& wpath)
{
	this->rpath = rpath;
}

int bs_knn::exec_bs_knn()
{
	cv::VideoCapture cap(cv::samples::findFile(rpath));
	if (!cap.isOpened())
	{
		std::cerr << "Unable to open." << std::endl;
		return -1;
	}

	cv::Mat frame, fgMask;
	while (true)
	{
		// Taking every frame
		cap >> frame;
		if (frame.empty()) break;

		// Executing the apply function
		p_bs->apply(frame,fgMask);
		cv::imshow("Frame", frame);
		cv::imshow("FG Mask", fgMask);
		
		// Waiting for keyboard response
		cv::waitKey(0);
		/*int keyboard = cv::waitKey(30);
		if (keyboard == 'q' || keyboard == 27) break;*/
	}
}

bs_knn::~bs_knn()
{

}