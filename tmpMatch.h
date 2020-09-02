#ifndef _TMPMATCH_H
#define __TMPMATCH_H

#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv\cxcore.h>
#include <cstdlib>
#include <cstdio>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


class TmpMatch
{
	public:
		IplImage* src, * result, * show, * savedImg;
		IplImage* templat1, * templat2, * templat3, * templat4, * templat5, * templat6;
		int srcW, templatW, srcH, templatH, resultW, resultH;

		void match();
		void tMatch(int);



};




#endif