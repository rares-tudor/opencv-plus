#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>

#include "ppm.h"
#include "grab_cut.h"
#include "bs_knn.h"
#include "bs_mog2.h"
#include "canny_edge_detection.h"
#include "canny_bgd_subtraction.h"
#include "sobel_edge_detection.h"
#include "sobel_bgd_subtraction.h"

std::string rpath, wpath; //readpath, writepath

int main(int argc, char** argv)
{
	for (int i = 0; i < argc; ++i)
	{
		// Determining the path
		if (std::string(argv[i + 2]) == "-rp")
		{
			rpath = std::string(argv[i + 3]); //-rp
			wpath = std::string(argv[i + 5]); //-wp
		}

		// Running the algorithm
		if (std::string(argv[i+1]) == "-gc")
		{
			grab_cut grbc(rpath, wpath); // grabcut
			grbc.exec_grc();
		}
		else if (std::string(argv[i+1]) == "-m")
		{
			bs_mog2 mog2_alg(rpath, wpath); // mog2 algorithm (video)
			mog2_alg.exec_bs_mog2();
		}
		else if (std::string(argv[i+1]) == "-k")
		{
			bs_knn knn_alg(rpath, wpath); // knn algorithm (video)
			knn_alg.exec_bs_knn();
		}
		else if (std::string(argv[i+1]) == "-c")
		{
			canny_edge_detection canny(rpath, wpath); // canny edge detection (still img)
			canny.get_edges();
		}
		else if (std::string(argv[i+1]) == "-cbs")
		{
			canny_bgd_separator cannyBgdSeparator(rpath, wpath); // canny background separator (still img)
			cannyBgdSeparator.subtract_bgd();
		}
		else if (std::string(argv[i+1]) == "-s")
		{
			sobel_edge_detection sobel(rpath, wpath); // sobel edge detection (still img)
			sobel.get_edges_and_display();
		}
		else if (std::string(argv[i+1]) == "-sbs")
		{
			sobel_bgd_subtraction sobel_bgd(rpath, wpath); // sobel background subtraction (still img)
			sobel_bgd.subtract_bgd();
		}
	}
	return 0;
}
