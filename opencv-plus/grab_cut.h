#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#pragma once

class grab_cut
{
	public:
		grab_cut(std::string fPath);
		~grab_cut();
		int exec_grc();

	protected: 

	private:
		std::string path;
};

