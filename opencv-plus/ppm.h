#pragma once
#include <iostream>
#include <fstream>

class ppm
{
public:
	std::string magnum;
	int w, h, maxColVal;
	char* m_Ptr;
public:
	friend std::istream& operator <<(std::istream& inputStream, ppm ppmObj);
	friend std::ostream& operator >>(std::ostream& outputStream, const ppm& ppmObj);
	ppm();
	~ppm();
};

