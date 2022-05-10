#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat src;
	VideoCapture capture(0);

	while (true)
	{
		capture >> src;

		cvtColor(src, src, COLOR_BGR2GRAY);
		Mat edge;
		Canny(src, edge, 50, 150);
		vector<Vec4i> lines;
		HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 50, 5);
		Mat dst;
		cvtColor(edge, dst, COLOR_GRAY2BGR);
		for (Vec4i l : lines) {
			line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
		}
		imshow("src", src);
		imshow("dst", dst);
		if (waitKey(10) > 0)
			break;
	}
}
