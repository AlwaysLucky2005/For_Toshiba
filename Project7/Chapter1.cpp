#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

int main() {

	string path = "Resources/test_video.mp4";
	VideoCapture cap(1);
	Mat img;
	while (true)
	{
		cap.read(img);
		imshow("Video", img);
		waitKey(1);
	}


}