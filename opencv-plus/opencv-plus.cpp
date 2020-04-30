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
		if (std::string(argv[i]) == "-gc")
		{	
			// Determining the path and running the algorithm
			if (std::string(argv[i + 1]) == "-p")
			{
				path = std::string(argv[i + 2]);

				grab_cut grbc(path);
				grbc.exec_grc();
			}
		}
		// Other options
	}
	return 0;
}
