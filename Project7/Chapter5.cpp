#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
float w = 250, h = 350;
int main()
{
	string Path = "Resources/cards.jpg";
	Mat img = imread(Path);
	Point2f pts[4] = { {60, 320}, {340, 278}, {89, 633} ,{404, 572} };
	Point2f d[4] = { {0,0}, {w, 0}, {0, h}, {w,h} };
	Mat m = getPerspectiveTransform(pts, d);
	Mat imgWarp;
	warpPerspective(img, imgWarp, m, Point());

	imshow("img", img);
	imshow("imgw", imgWarp);
	waitKey(0);
	return 0;
}