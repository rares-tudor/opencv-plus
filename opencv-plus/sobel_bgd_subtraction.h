#pragma once
#include <string>


class sobel_bgd_subtraction
{
private:
	std::string rpath, wpath;

public:
	sobel_bgd_subtraction(const std::string& rpath, const std::string& wpath);

public:
	void subtract_bgd();
};

