#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>
#include "grab_cut.h"
std::string path;

int main(int argc, char** argv)
{
	for (int i = 0; i < argc; ++i)
	{
		// grabCut-Algorithm
		if (argv[i] == "g")
		{	
			// Determining the path and running the algorithm
			path = argv[i + 1];
			grab_cut sdgrb(path);
			sdgrb.exec_grc();
		}
		// Other options
	}
	return 0;
}