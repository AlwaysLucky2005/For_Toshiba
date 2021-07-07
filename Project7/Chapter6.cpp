#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
Mat imgH, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;
int main()
{
	string Path = "Resources/shapes.png";
	Mat img = imread(Path);
	cvtColor(img, imgH, COLOR_BGR2HSV);
	namedWindow("Track", (640, 200));
	createTrackbar("Hue min", "Track", &hmin, 179);
	createTrackbar("Hue max", "Track", &hmax, 179);
	createTrackbar("Sat min", "Track", &smin, 255);
	createTrackbar("Sat max", "Track", &smax, 255);
	createTrackbar("Val min", "Track", &vmin, 255);
	createTrackbar("Val max", "Track", &vmax, 255);
	imshow("img", img);
	imshow("hsv", imgH);
	while (true)
	{
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgH, lower, upper, mask);
		imshow("mask", mask);
		waitKey(1);
	}
	return 0;
}