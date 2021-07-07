#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
int main()
{
	string Path = "Resources/paper.jpg";
	Mat img, can,erod;
	img = imread(Path);
	//cv::imshow("img", img);
	cout << img.empty();
	Canny(img, can, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat di;
	dilate(can, di, kernel);
	erode(di, erod, kernel);
	cout << di.empty();
	imshow("can", can);
	imshow("cmg", di);
	imshow("cmg1", erod);
	//imshow("canny", can);
	waitKey(0);
	return 0;
}