#pragma once
#include <string>
#include "opencv2/core/mat.hpp"

class canny_bgd_separator
{
private:
	std::string rpath, wpath;

public:
	canny_bgd_separator(const std::string& rpath, const std::string& wpath);

public:
	void subtract_bgd();
};

