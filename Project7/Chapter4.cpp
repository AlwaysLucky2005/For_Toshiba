#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
int main()
{
	Mat img(512, 512, CV_8UC3, Scalar(0,0,0));
	circle(img, Point(256, 256), 155, Scalar(255, 255, 255), FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(0, 0, 0), FILLED);
	line(img, Point(130, 296), Point(382, 296), Scalar(0, 0, 0), 2);
	putText(img, "TextTextText TExT", Point(137, 262), FONT_HERSHEY_PLAIN, 2, Scalar(209, 166, 48),2);
	imshow("Myimg", img);
	waitKey(0);
	return 0;
}