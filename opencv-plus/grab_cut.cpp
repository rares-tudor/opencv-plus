#include "grab_cut.h"

grab_cut::grab_cut(std::string fpath) : path(fpath)
{
}

int grab_cut::exec_grc()
{
	// Initializing image
	cv::Mat image = cv::imread(cv::samples::findFile(path), cv::IMREAD_COLOR);
	if (image.empty())
	{
		std::cout << "Image couldn't be opened";
		return -1;
	}
	else
	{
		// Running algorithm
		//cv::grabCut(image,);
	}
};

grab_cut::~grab_cut()
{

}