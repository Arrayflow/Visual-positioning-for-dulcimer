#include <iostream>
#include "tmpMatch.h"
#include "Click.h"
#include "resotre.h"

using namespace std;
using namespace cv;


int main()
{
	//模板匹配
    TmpMatch tmpMatch;            
	tmpMatch.match();

	//向量获取
	imshow("Depth", Depth);
	imshow("Color", Color);
	ParaInit();//初始化内参
	openFiles();
	cvSetMouseCallback("Color", on_mouse, 0);

	cvWaitKey(0);

	//向量复原
	RestoreVec();


    return 0;
}

