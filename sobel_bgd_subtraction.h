#pragma once
#include <string>


class sobel_bgd_subtraction
{
private:
	std::string path;

public:
	sobel_bgd_subtraction(std::string path);

public:
	void subtract_bgd();
};

