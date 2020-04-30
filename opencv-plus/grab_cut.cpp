#include "grab_cut.h"

grab_cut::grab_cut(std::string fpath) : path(fpath) {}

int grab_cut::exec_grc()
{

	cv::Mat image = cv::imread(cv::samples::findFile(path), cv::IMREAD_COLOR);

	// Initializing image
	if (image.empty())
	{
		std::cout << "Failed to open image";
		return -1;
	}
	else
	{
		cv::Mat1b markers(image.rows, image.cols);
		// all markers are set to background
		markers.setTo(cv::GC_PR_BGD);

		// keep 50% of the image in the center
		int rows = 0.5 * image.rows;
		int cols = 0.5 * image.cols;

		// select region of interest, in this case it's the middle of the image
		cv::Mat1b fgdMarkers = markers(cv::Range(image.rows / 2 - rows / 2, image.rows / 2 + rows / 2),
			cv::Range(image.cols / 2 - cols / 2, image.cols / 2 + cols / 2)); // TODO Implement Rect instead of Range

		// mark the seed as foreground
		fgdMarkers.setTo(cv::GC_FGD);

		// select first 5 rows of the image
		cv::Mat1b bgdMarkers = markers(cv::Range(0, 5), cv::Range::all());
		// set the rows as background
		bgdMarkers.setTo(cv::GC_BGD);

		cv::Mat bgd, fgd;

		int iterations = 1;
		// Running the algorithm
		cv::grabCut(image, markers, cv::Rect(), bgd, fgd, iterations, cv::GC_INIT_WITH_MASK);

		// gets all foreground pixels
		cv::Mat1b fgdMask = (markers == cv::GC_FGD) | (markers == cv::GC_PR_FGD);
		cv::Mat3b fgdImg = cv::Mat3b::zeros(image.rows, image.cols);
		// copy all valid foreground-pixels to a temporary image
		image.copyTo(fgdImg, fgdMask);

		cv::imshow("GrabCut Image", fgdImg);
		cv::waitKey(0);
	}
};

grab_cut::~grab_cut()
{

}