#include "stdafx.h"
#include"Filters.h"
Mat gray_filter(Mat image)
{
	uchar b, g, r;
	Mat gray_image = Mat::zeros(image.size(), image.type());
	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			b = image.at<Vec3b>(y, x)[0];
			g = image.at<Vec3b>(y, x)[1];
			r = image.at<Vec3b>(y, x)[2];
			gray_image.at<Vec3b>(y, x)[0] = minBGR(b, g, r);
			gray_image.at<Vec3b>(y, x)[1] = min(min(b, g), r);
			gray_image.at<Vec3b>(y, x)[2] = min(min(b, g), r);
		}
	}
	return gray_image;
}
Mat make_noise(Mat image)
{
	int noise;
	uchar intens = 100;
	Mat noise_image = image.clone();
	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			noise = rand() % 100 + 1;
			if (noise< 2)
			{
				noise_image.at<Vec3b>(y, x)[0] = intens;
				noise_image.at<Vec3b>(y, x)[1] = intens;
				noise_image.at<Vec3b>(y, x)[2] = intens;
			}
		}
	}
	return noise_image;
}
Mat mean_filter(Mat image, int size)
{
	Mat smooth_image = Mat::zeros(image.size(), image.type());
	int start = size / 2;
	double dgr = 1.0 / (size*size);
	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			double resr = 1, resg = 1, resb = 1;
			if (y == 0)
			{
				if (x == 0)
				{
					for (int i = start; i < size + 1; i++)
						for (int j = start; j < size + 1; j++)
						{
							resr *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[0])*dgr);
							resg *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[1])*dgr);
							resb *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[2])*dgr);
							smooth_image.at<Vec3b>(y, x)[0] = resr;
							smooth_image.at<Vec3b>(y, x)[1] = resg;
							smooth_image.at<Vec3b>(y, x)[2] = resb;
						}
				}
				if (x == image.cols - 1)
				{
					for (int i = start; i < size + 1; i++)
						for (int j = start; j < size + 1; j++)
						{
							resr *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[0])*dgr);
							resg *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[1])*dgr);
							resb *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[2])*dgr);
							smooth_image.at<Vec3b>(y, x)[0] = resr;
							smooth_image.at<Vec3b>(y, x)[1] = resg;
							smooth_image.at<Vec3b>(y, x)[2] = resb;
						}
				}
				if (x != 0 && x != image.cols - 1)
				{
					for (int i = 0; i < size; i++)
						for (int j = start; j < size + 1; j++)
						{
							resr *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[0])*dgr);
							resg *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[1])*dgr);
							resb *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[2])*dgr);

						}
					smooth_image.at<Vec3b>(y, x)[0] = (uchar)resr;
					smooth_image.at<Vec3b>(y, x)[1] = (uchar)resg;
					smooth_image.at<Vec3b>(y, x)[2] = (uchar)resb;
				}
				continue;
			}
			if (y == image.rows - 1)
			{
				if (x == 0)
				{
					for (int i = start; i < size + 1; i++)
						for (int j = start; j < size + 1; j++)
						{
							resr *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[0])*dgr);
							resg *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[1])*dgr);
							resb *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[2])*dgr);
							smooth_image.at<Vec3b>(y, x)[0] = resr;
							smooth_image.at<Vec3b>(y, x)[1] = resg;
							smooth_image.at<Vec3b>(y, x)[2] = resb;
						}
				}
				if (x == image.cols - 1)
				{
					for (int i = start; i < size + 1; i++)
						for (int j = start; j < size + 1; j++)
						{
							resr *= exp(log(image.at<Vec3b>(y - j - start, x - i - start)[0])*dgr);
							resg *= exp(log(image.at<Vec3b>(y - j - start, x - i - start)[1])*dgr);
							resb *= exp(log(image.at<Vec3b>(y - j - start, x - i - start)[2])*dgr);
							smooth_image.at<Vec3b>(y, x)[0] = resr;
							smooth_image.at<Vec3b>(y, x)[1] = resg;
							smooth_image.at<Vec3b>(y, x)[2] = resb;
						}
				}
				if (x != 0 && x != image.cols - 1)
				{
					for (int i = 0; i < size; i++)
						for (int j = start; j < size + 1; j++)
						{
							resr *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[0])*dgr);
							resg *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[1])*dgr);
							resb *= exp(log(image.at<Vec3b>(y - j - start, x + i - start)[2])*dgr);
							smooth_image.at<Vec3b>(y, x)[0] = resr;
							smooth_image.at<Vec3b>(y, x)[1] = resg;
							smooth_image.at<Vec3b>(y, x)[2] = resb;
						}
				}
				continue;
			}
			if (x == 0)
			{
				if (y != 0 && y != image.rows - 1)
				{
					for (int i = start; i < size + 1; i++)
						for (int j = 0; j < size; j++)
						{
							resr *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[0])*dgr);
							resg *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[1])*dgr);
							resb *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[2])*dgr);
							smooth_image.at<Vec3b>(y, x)[0] = resr;
							smooth_image.at<Vec3b>(y, x)[1] = resg;
							smooth_image.at<Vec3b>(y, x)[2] = resb;
						}
				}
				continue;
			}
			if (x == image.cols - 1)
			{
				if (y != 0 && y != image.rows)
				{
					for (int i = start; i < size + 1; i++)
						for (int j = 0; j < size; j++)
						{
							resr *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[0])*dgr);
							resg *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[1])*dgr);
							resb *= exp(log(image.at<Vec3b>(y + j - start, x - i - start)[2])*dgr);
							smooth_image.at<Vec3b>(y, x)[0] = resr;
							smooth_image.at<Vec3b>(y, x)[1] = resg;
							smooth_image.at<Vec3b>(y, x)[2] = resb;
						}
				}
				continue;
			}
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
				{
					resr *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[0])*dgr);
					resg *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[1])*dgr);
					resb *= exp(log(image.at<Vec3b>(y + j - start, x + i - start)[2])*dgr);
				}
			smooth_image.at<Vec3b>(y, x)[0] = resr;
			smooth_image.at<Vec3b>(y, x)[1] = resg;
			smooth_image.at<Vec3b>(y, x)[2] = resb;
		}
	}
	return smooth_image;
}
uchar minBGR(uchar b, uchar g, uchar r)
{
	return min(min(b, g), r);
}