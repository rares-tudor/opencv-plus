#include "bs_mog2.h"
#include <fstream>

bs_mog2::bs_mog2(const std::string& rpath, const std::string& wpath)
{
	this->rpath = rpath;
	this->wpath = wpath;
}

int bs_mog2::exec_bs_mog2()
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
		p_bs->apply(frame, fgMask);
		cv::imshow("Frame", frame);
		cv::imshow("FG Mask", fgMask);

		// Waiting for keyboard response
		if (sizeof(wpath) != 0)
		{
			std::ofstream outFile;
			outFile.open(wpath, std::ios::binary);
			outFile << "P3" << "\n"
				<< fgMask.cols << " "
				<< fgMask.rows << "\n"
				<< 255 << "\n";
			outFile << fgMask;
			return 0;
		}
		int keyboard = cv::waitKey(30);
		if (keyboard == 'q' || keyboard == 27) break;
	}
}

bs_mog2::~bs_mog2() { }