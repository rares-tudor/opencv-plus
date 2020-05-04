#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>

#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>

#include "grab_cut.h"
#include "bs_knn.h"
#include "bs_mog2.h"
#include "canny_edge_detection.h"
#include "canny_bgd_subtraction.h"
#include "sobel_edge_detection.h"
#include "sobel_bgd_subtraction.h"

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
		// canny edge detection (still img)
		else if (std::string(argv[i]) == "-c")
		{
			if (std::string(argv[i + 1]) == "-p")
			{
				path = std::string(argv[i + 2]);

				canny_edge_detection canny(path);
				canny.get_edges();
			}
		}
		// canny background separator (still img)
		else if (std::string(argv[i]) == "-cbs")
		{
			if (std::string(argv[i + 1]) == "-p")
			{
				path = std::string(argv[i + 2]);

				canny_bgd_separator cannyBgdSeparator(path);
				cannyBgdSeparator.subtract_bgd();
			}
		}
		// sobel edge detection (still img)
		else if (std::string(argv[i]) == "-s")
		{
			if (std::string(argv[i + 1]) == "-p")
			{
				path = std::string(argv[i + 2]);

				sobel_edge_detection sobel(path);
				sobel.get_edges_and_display();
			}
		}
		// sobel background subtraction (still img)
		else if (std::string(argv[i]) == "-sbs")
		{
			if (std::string(argv[i + 1]) == "-p")
			{
				path = std::string(argv[i + 2]);

				sobel_bgd_subtraction sobel_bgd(path);
				sobel_bgd.subtract_bgd();
			}
			// Other options
		}
	}
	return 0;
}
