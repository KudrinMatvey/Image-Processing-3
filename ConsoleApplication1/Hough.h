#pragma once
#include <math.h>
#include "opencv2\core.hpp"
using namespace std;
using namespace cv;

int* generateAccumArray(Mat image);
Mat detectCircles(Mat image, int* AccumArray);
