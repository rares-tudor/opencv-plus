#pragma once
#include <string>
#include "opencv2/core/mat.hpp"

class canny_bgd_separator
{
private:
	std::string path;

public:
	canny_bgd_separator(const std::string& path);

public:
	void subtract_bgd();
};

