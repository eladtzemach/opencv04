#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace cv;
using namespace std;




int main(int argc, const char** argv)
{
	Mat src_gray, cimg;
	Mat src = imread("C:/.../images/circles_target.jpg", CV_LOAD_IMAGE_COLOR);
	cvtColor(src, src_gray, COLOR_RGB2GRAY);
	GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);

	cvtColor(src_gray, cimg, COLOR_GRAY2RGB);
	vector<Vec3f> circles;
	HoughCircles(src_gray, circles, HOUGH_GRADIENT, 1, 10,
		8, 90, 0, 0 
					
		);
	for (size_t i = 0; i < circles.size(); i++)
	{
		Vec3i c = circles[i];
		circle(src, Point(c[0], c[1]), c[2], Scalar(0, 255, 0), 3, LINE_AA);
		circle(src, Point(c[0], c[1]), 2, Scalar(0, 0, 255), 3, LINE_AA);
	}

	imshow("detected circles", src);
	waitKey();
	return 0;

}
