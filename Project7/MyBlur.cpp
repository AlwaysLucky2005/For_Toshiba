#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <thread>
using namespace cv;
using namespace std;
int blurPixelValue(Mat img,int x, int y, int sizex, int sizey, int ch, double am)
{
	int s = sizex * sizey;
	int sum = 0, count = 0;
	int i1 = x - sizex; int i2 = x + sizex;
	int j1 = y - sizey; int j2 = y + sizey;
	if (i1 < 0) i1 = 0; if (j1 < 0) j1 = 0;
	if (i2 >= img.rows) i2 = img.rows - 1; if (j2 >= img.cols) j2 = img.cols - 1;
	for (int i = i1; i <= i2; i++)
	{
		for (int j = j1; j <= j2; j++)
		{
			sum += (int)(img.at<Vec3b>(i, j)[ch]);
			count++;
		}
	}
	double ans = (sum / count);
	int pix = (int)(img.at<Vec3b>(x, y)[ch]);
	ans = (ans + pix) / 2.0;
	return (int)ans;
}
int main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path); 
	Mat img1;
	img.copyTo(img1);
	int sizex = 2, sizey = 2;
	Vec3b color;
	double amount=0.2;
	thread th[10000];
	int o = 0;
	for (int i = 0; i < img.rows / 2; i++)
	{
		th[o++] = thread([&]() {
		for (int j = 0; j < img.cols / 2; j++)
		{
			color[0] = blurPixelValue(img, i, j, sizex, sizey, 0, amount);
			color[1] = blurPixelValue(img, i, j, sizex, sizey, 1, amount);
			color[2] = blurPixelValue(img, i, j, sizex, sizey, 2, amount);
			img1.at<Vec3b>(i, j) = color;
		}
			});
	}
	for (int i = 0; i < o; i++) th[i].join();
	imshow("blured", img1);
	
	imshow("img", img);
	waitKey(0);
	return 0;

}