#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "ppm.h"
#include <fstream>

ppm::ppm()
{

}

std::ostream& operator<<(std::ostream& outputStream, const ppm ppmObj)
{
	size_t size = ppmObj.w * ppmObj.h * 3;
	outputStream.write(ppmObj.m_Ptr, size);
	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, ppm& ppmObj)
{
	inputStream >> ppmObj.magnum;
	inputStream >> ppmObj.w >> ppmObj.h >> ppmObj.maxColVal;
	inputStream.get();
	size_t size = ppmObj.w * ppmObj.h * 3;
	ppmObj.m_Ptr = new char[size];
	inputStream.read(ppmObj.m_Ptr, size);
	return inputStream;
}

std::istream& operator >>(std::istream& inputStream, cv::Mat3b matImg)
{
	inputStream >> matImg.cols >> matImg.rows;
	inputStream.get();
	size_t size = matImg.cols * matImg.rows * 3;
	char* ptr{};
	inputStream.read(ptr, size);
	return inputStream;
}

std::ostream& operator <<(std::ostream& outputStream, const cv::Mat3b matImg)
{
	size_t size = (matImg.cols * matImg.rows * 3);
	char* ptr{};
	outputStream.write(ptr, size);
	return outputStream;
}

ppm::~ppm()
{

}