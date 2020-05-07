#pragma once
#include <iostream>
#include <fstream>

class ppm
{
public:
	std::string magnum;
	unsigned int w = 0, h = 0, maxColVal = 0;
	char* m_Ptr{};
public:
	friend std::ostream& operator <<(std::ostream& outputStream, const ppm ppmObj);
	friend std::istream& operator >>(std::istream& inputStream, ppm& ppmObj);
	friend std::ostream& operator <<(std::ostream& outputStream, const cv::Mat3b matImg);
	friend std::istream& operator >>(std::istream& inputStream, cv::Mat3b matImg);
	ppm();
	~ppm();
};

