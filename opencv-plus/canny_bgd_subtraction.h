#pragma once
#include <string>
#include "opencv2/core/mat.hpp"

class canny_bgd_separator
{
private:
	std::string rpath, wpath;

public:

public:
	canny_bgd_separator(const std::string& rpath, const std::string& wpath);
	~canny_bgd_separator();
	void subtract_bgd();
};

