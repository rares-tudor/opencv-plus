#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "ppm.h"

ppm::ppm()
{

}

std::istream& operator<<(std::istream& inputStream, ppm ppmObj)
{
	inputStream >> ppmObj.magnum;
	inputStream >> ppmObj.w >> ppmObj.h >> ppmObj.maxColVal;
	inputStream.get();
	size_t size = ppmObj.w * ppmObj.h * 3;
	ppmObj.m_Ptr = new char[size];
	inputStream.read(ppmObj.m_Ptr, size);
	return inputStream;
}

std::ostream& operator>>(std::ostream& outputStream, const ppm& ppmObj)
{
	outputStream << "P6" << "\n"
		<< ppmObj.w << " "
		<< ppmObj.h << "\n"
		<< ppmObj.maxColVal << "\n";
	size_t size = ppmObj.w * ppmObj.h * 3;
	outputStream.write(ppmObj.m_Ptr, size);
	return outputStream;
}

std::ostream& operator >>(std::ostream& outputStream, const cv::Mat3b matImg)
{
	outputStream << "P6" << "\n"
		<< matImg.cols << " "
		<< matImg.rows << "\n"
		<< 255 << "\n";
	size_t size = matImg.cols * matImg.rows * 3;
	char* ptr{};
	outputStream.write(ptr, size);
	return outputStream;
}



ppm::~ppm()
{

}