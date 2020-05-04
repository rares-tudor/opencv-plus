#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#pragma once

class grab_cut
{
	public:
		grab_cut(const std::string& rpath, const std::string& wpath);
		~grab_cut();
		int exec_grc();

	private:
		std::string rpath, wpath;
};

