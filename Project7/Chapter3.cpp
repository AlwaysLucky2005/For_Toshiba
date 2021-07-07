#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
int main()
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgRes, imgCrop;
	resize(img, imgRes, Size(), 0.5, 1);
	Rect roi(100,200, 400, 300);
	imgCrop = img(roi);
	imshow("image", img);
	imshow("res", imgRes);
	imshow("crop", imgCrop);
	cout << img.size();
	waitKey(0);
	return 0;
}