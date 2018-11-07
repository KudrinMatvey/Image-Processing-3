#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <math.h>
#include "AwesomeMap.h"
#include "time.h"
#include "Filters.h"
	using namespace cv;
	using namespace std;
	int main(int argc, char** argv)
	{
		uchar r, g, b;
		char* imageName = argv[1];
		Mat image;
		srand(2);
		image = imread("easycircle.jpg", IMREAD_COLOR);
		/*if (argc != 2 || !image.data)
		{
		printf(" No image data \n ");
		return -1;
		}*/
		Mat new_image = Mat::zeros(image.size(), image.type());
		/*Mat smooth_image = Mat::zeros(image.size(), image.type());
		Mat noise_image = image.clone();*/
		/*int noise;
		int size = 3;
		int start =size/2;
		double dgr = 1.0/(size*size); */
		/*for (int y = 0; y < image.rows; y++)
		{
		for (int x = 0; x < image.cols; x++)
		{
		r = image.at<Vec3b>(y, x)[0];
		g = image.at<Vec3b>(y, x)[1];
		b = image.at<Vec3b>(y, x)[2];
		gray_image.at<Vec3b>(y, x)[0]=min(min(r,g),b);
		gray_image.at<Vec3b>(y, x)[1] = min(min(r, g), b);
		gray_image.at<Vec3b>(y, x)[2] = min(min(r, g), b);
		}
		}*/
		/*for (int y = 0; y < image.rows; y++)
		{
		for (int x = 0; x < image.cols; x++)
		{
		noise = rand() % 100 + 1;
		if ( noise< 2)
		{
		noise_image.at<Vec3b>(y, x)[0] = 100;
		noise_image.at<Vec3b>(y, x)[1] = 100;
		noise_image.at<Vec3b>(y, x)[2] = 100;
		}
		}
		}*/

		/*//for (int y = 0; y < image.rows; y++)
		//{
		//	for (int x = 0; x < image.cols; x++)
		//	{
		//		double resr=1, resg=1, resb=1;
		//		if (y == 0)
		//		{
		//			if (x == 0)
		//			{
		//				for (int i = start; i < size+1; i++)
		//					for (int j = start; j < size+1; j++)
		//					{
		//						resr *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[0])*dgr);
		//						resg *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[1])*dgr);
		//						resb *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[2])*dgr);
		//						smooth_image.at<Vec3b>(y, x)[0] = resr;
		//						smooth_image.at<Vec3b>(y, x)[1] = resg;
		//						smooth_image.at<Vec3b>(y, x)[2] = resb;
		//					}
		//			}
		//			if (x == image.cols - 1)
		//			{
		//				for (int i = start; i < size+1; i++)
		//					for (int j = start; j < size+1; j++)
		//					{
		//						resr *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[0])*dgr);
		//						resg *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[1])*dgr);
		//						resb *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[2])*dgr);
		//						smooth_image.at<Vec3b>(y, x)[0] = resr;
		//						smooth_image.at<Vec3b>(y, x)[1] = resg;
		//						smooth_image.at<Vec3b>(y, x)[2] = resb;
		//					}
		//			}
		//			if (x != 0 && x != image.cols - 1)
		//			{
		//				for (int i = 0; i < size; i++)
		//					for (int j = start; j < size+1; j++)
		//					{
		//						resr *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[0])*dgr);
		//						resg *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[1])*dgr);
		//						resb *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[2])*dgr);
		//
		//					}
		//				smooth_image.at<Vec3b>(y, x)[0] = (uchar)resr;
		//				smooth_image.at<Vec3b>(y, x)[1] = (uchar)resg;
		//				smooth_image.at<Vec3b>(y, x)[2] = (uchar)resb;
		//			}
		//			continue;
		//		}
		//		if (y == image.rows - 1)
		//		{
		//			if (x == 0)
		//			{
		//				for (int i = start; i < size+1; i++)
		//					for (int j = start; j < size+1; j++)
		//					{
		//						resr *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[0])*dgr);
		//						resg *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[1])*dgr);
		//						resb *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[2])*dgr);
		//						smooth_image.at<Vec3b>(y, x)[0] = resr;
		//						smooth_image.at<Vec3b>(y, x)[1] = resg;
		//						smooth_image.at<Vec3b>(y, x)[2] = resb;
		//					}
		//			}
		//			if (x == image.cols - 1)
		//			{
		//				for (int i = start; i < size+1; i++)
		//					for (int j = start; j < size+1; j++)
		//					{
		//						resr *= exp(log(image.at<Vec3b>(y - j - start, x - i - start)[0])*dgr);
		//						resg *= exp(log(image.at<Vec3b>(y - j - start, x - i - start)[1])*dgr);
		//						resb *= exp(log(image.at<Vec3b>(y - j - start, x - i - start)[2])*dgr);
		//						smooth_image.at<Vec3b>(y, x)[0] = resr;
		//						smooth_image.at<Vec3b>(y, x)[1] = resg;
		//						smooth_image.at<Vec3b>(y, x)[2] = resb;
		//					}
		//			}
		//			if (x != 0 && x != image.cols - 1)
		//			{
		//				for (int i = 0; i < size; i++)
		//					for (int j = start; j < size+1; j++)
		//					{
		//						resr *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[0])*dgr);
		//						resg *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[1])*dgr);
		//						resb *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[2])*dgr);
		//						smooth_image.at<Vec3b>(y, x)[0] = resr;
		//						smooth_image.at<Vec3b>(y, x)[1] = resg;
		//						smooth_image.at<Vec3b>(y, x)[2] = resb;
		//					}
		//			}
		//			continue;
		//		}
		//		if (x == 0)
		//		{
		//			if (y != 0 && y != image.rows - 1)
		//			{
		//				for (int i = start; i < size+1; i++)
		//					for (int j = 0; j < size; j++)
		//					{
		//						resr *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[0])*dgr);
		//						resg *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[1])*dgr);
		//						resb *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[2])*dgr);
		//						smooth_image.at<Vec3b>(y, x)[0] = resr;
		//						smooth_image.at<Vec3b>(y, x)[1] = resg;
		//						smooth_image.at<Vec3b>(y, x)[2] = resb;
		//					}
		//			}
		//			continue;
		//		}
		//		if (x == image.cols - 1)
		//		{
		//			if (y != 0 && y != image.rows)
		//			{
		//				for (int i = start; i < size+1; i++)
		//					for (int j = 0; j < size; j++)
		//					{
		//						resr *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[0])*dgr);
		//						resg *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[1])*dgr);
		//						resb *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[2])*dgr);
		//						smooth_image.at<Vec3b>(y, x)[0] = resr;
		//						smooth_image.at<Vec3b>(y, x)[1] = resg;
		//						smooth_image.at<Vec3b>(y, x)[2] = resb;
		//					}
		//			}
		//			continue;
		//		}
		//		for (int i = 0; i < size; i++)
		//			for (int j = 0; j < size; j++)
		//			{
		//				resr *= exp(log(noise_image.at<Vec3b>(y + j - start, x + i - start)[0])*dgr);
		//				resg *= exp(log(noise_image.at<Vec3b>(y + j - start, x + i - start)[1])*dgr);
		//				resb *= exp(log(noise_image.at<Vec3b>(y + j - start, x + i - start)[2])*dgr);
		//			}
		//		/*resr = (int)exp(log(resr)*dgr);
		//		resg = (int)exp(log(resg)*dgr);
		//		resb = (int)exp(log(resb)*dgr);
		//		smooth_image.at<Vec3b>(y, x)[0] =resr;
		//		smooth_image.at<Vec3b>(y, x)[1] =resg;
		//		smooth_image.at<Vec3b>(y, x)[2] =resb;
		//		/*noise_image.at<Vec3b>(y, x)[0] = resr;
		//		noise_image.at<Vec3b>(y, x)[1] = resg;
		//		noise_image.at<Vec3b>(y, x)[2] = resb;
		//	}
		//}
		//	cvtColor(image, gray_image, COLOR_BGR2GRAY);
		//	imwrite("../../image/graysky.jpg", gray_image);*/





		namedWindow("Image", WINDOW_AUTOSIZE);
		imshow("Image", image);

		//Mat cannyImage = Mat::zeros(image.size(), image.type());
		//Mat blurredImage = Mat::zeros(image.size(), image.type());
		Mat cannyImage = image.clone();
		Mat blurredImage = image.clone();
		Mat grayImage = gray_filter(image);
		GaussianBlur(grayImage, blurredImage, Size(5, 5), 0);
		/*namedWindow("Blurred", WINDOW_AUTOSIZE);
		imshow("Blurred", blurredImage);*/
		Mat dst = Mat::zeros(image.size(), image.type());
		Canny(blurredImage, cannyImage, 90, 270, 3);
		dst = Scalar::all(0);
		grayImage.copyTo(dst, cannyImage);
		namedWindow("Canny", WINDOW_AUTOSIZE);
		imshow("Canny", dst);

		int zindex = 90, yindex = dst.rows, xindex = dst.cols;
		AwesomeMap map;
		/*int ***arr = new int**[zindex];

		for (int i = 0; i<zindex; i++)
		{
		arr[i] = new int*[yindex];
		for (int j = 0; j<yindex; j++)
		{
		arr[i][j] = new int[xindex];
		}
		}*/


		//int arr[90][100][100];

		//for (int z = 0; z<90; z++)
		//	for (int y = 0; y<100; y++)
		//		for (int x = 0; x<100; x++)
		//			arr[z][y][x] = 0;

		for (int y = 0; y < dst.rows; y++)
		{
			for (int x = 0; x < dst.cols; x++)
			{
				uchar b = dst.at<Vec3b>(y, x)[0];
				uchar g = dst.at<Vec3b>(y, x)[1];
				uchar r = dst.at<Vec3b>(y, x)[2];
				if (b == 0 && g == 0 && r == 0) continue;
				else
				{
					for (int r = 5; r < 20; r++) 
					{
						for (int theta = 0; theta < 360; theta++)
						{
							int a = x - r * cos(theta * 3.1415 / 180);
							int s = y - r * sin(theta * 3.1415 / 180);
							if (a > 0 && s > 0)
								map.add(r, s, a);
						}
					}
				}
			}
		}

		item* arr = map.findLocalMaximums();
		for (int i = 0; i < map.getArrSize(); i++) {
			Point center = Point(arr[i].x,arr[i].y);
			circle(image, center, arr[i].z, Scalar(256, 0, 0), 2, LINE_AA);
		}

		//for (int z = 5; z < 40; z++)
		//{
		//	for (int y = 0; y < 100; y++)
		//	{
		//		for (int x = 0; x < 100; x++)
		//		{
		//			if (arr[z][y][x] != NULL)
		//			{
		//				if (arr[z][y][x] > 20)
		//				{
		//					Point center = Point(x, y);
		//					circle(image, center, z, Scalar(256, 0, 0), 2, LINE_AA);
		//				}
		//			}
		//		}
		//	}
		//}
		namedWindow("After", WINDOW_AUTOSIZE);
		imshow("After", image);
		/*new_image = make_noise(image);
		namedWindow("Noise", WINDOW_AUTOSIZE);
		imshow("Noise", new_image);


		new_image = mean_filter(new_image, 3);
		new_image = mean_filter(new_image, 3);
		namedWindow("Filter", WINDOW_AUTOSIZE);
		imshow("Filter", new_image);


		Mat new_image1 = gray_filter(image);
		namedWindow("GrayFilter", WINDOW_AUTOSIZE);
		imshow("GrayFilter", new_image1);*/
		waitKey(0);
		return 0;
	}

