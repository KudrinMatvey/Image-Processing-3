#pragma once
#include <opencv2/opencv.hpp>
#include <math.h>
using namespace std;
using namespace cv;
Mat gray_filter(Mat image);
Mat make_noise(Mat image);
Mat mean_filter(Mat image, int size);
//int Clamp(int value, int min, int max)
//{
//	if (value < min)
//		return min;
//	if (value > max)
//		return max;
//	return value;
//}
uchar minBGR(uchar b, uchar g, uchar r);

