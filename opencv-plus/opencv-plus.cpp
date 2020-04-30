#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>

#include "grab_cut.h"
#include "bs_knn.h"
#include "bs_mog2.h"

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
		// mog2 algorithm (video)
		else if (std::string(argv[i]) == "-m")
		{
			if (std::string(argv[i + 1]) == "-p")
			{
				path = std::string(argv[i + 2]);

				bs_mog2 mog2_alg(path);
				mog2_alg.exec_bs_mog2();
			}
		}
		// knn algorithm (video)
		else if (std::string(argv[i]) == "-k")
		{
			if (std::string(argv[i + 1]) == "-p")
			{
				path = std::string(argv[i + 2]);

				bs_knn knn_alg(path);
				knn_alg.exec_bs_knn();
			}
		}
		// Other options
	}
	return 0;
}
