#include "stdafx.h"
#include "Hough.h"

int* generateAccumArray(Mat image) {
	int AccumArray[image.cols][image.rows];
	Mat grayImage;
x:	for (int x = 0; x < image.cols; x++)
	y : for (int y = 0; y < image.rows; y++) {
	if (grayImage.at<Vec3b>(y, x) == 0)
		continue;
	else{
		angle:	for (int alpha = 0; alpha < 360; alpha++)
			radius : for (int radius = 0; x < image.cols; x++) {
			if()
		}
	}
}

	
}



Mat detectCircles(Mat image, int* AccumArray);
