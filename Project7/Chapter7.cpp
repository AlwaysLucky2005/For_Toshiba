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
	Mat img = imread(Path), can,imggray, imgblur, imgCanny;
	cvtColor(img, imggray, COLOR_BGR2GRAY);
	GaussianBlur(imggray, imgblur, Size(3, 3), 3, 0);
	Canny(imgblur, imgCanny, 25, 75);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5)); 
	Mat dil;
	dilate(imgCanny, dil, kernel);
	findContours(dil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	imshow("img", img);
	waitKey(0);
	return 0;
} 