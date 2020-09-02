#include "tmpMatch.h"



void TmpMatch::match()
{
	//加载源图像
	src = cvLoadImage("./模板图片/灰度图像.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	//加载用于显示结果的图像
	show = cvLoadImage("./模板图片/灰度图像.jpg");
	//用来存储用的图像
	savedImg = cvLoadImage("./模板图片/灰度图像.jpg");

	//加载模板图像

	if (!src) {
		printf("打开图片失败");
		exit(0);
	}

	for (int i = 1; i < 7; i++) {
		tMatch(i);
	}
	

	//cvSaveImage("sssss.jpg", savedImg);

	Mat savedImage = cvarrToMat(savedImg);
	Mat savedShow = cvarrToMat(show);
	imwrite("savedResult.jpg", savedImage);
	imwrite("savedShow.jpg", savedShow);
	cvShowImage("savedShow", show);
	cout << "已保存图片" << endl;
	


}

void TmpMatch::tMatch(int capNum)
{
	

	srcW = src->width;
	srcH = src->height;


	//创建存放结果的空间


	double minVal, maxVal;
	CvPoint minLoc, maxLoc;

	if (capNum == 1)
	{
		templat1 = cvLoadImage("./模板图片/1.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		templatW = templat1->width;
		templatH = templat1->height;
		resultW = srcW - templatW + 1;
		resultH = srcH - templatH + 1;
		result = cvCreateImage(cvSize(resultW, resultH), 32, 1);
		//进行模板匹配
		cvMatchTemplate(src, templat1, result, 1);
		cvMinMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, NULL);
		//绘制第一个查找结果到图像上
		cvRectangle(savedImg, minLoc, cvPoint(minLoc.x + templat1->width, minLoc.y + templat1->height), CV_RGB(0, 255, 0), -1);
		minLoc.x -= 2;
		minLoc.y -= 2;
		cvRectangle(show, minLoc, cvPoint(4 + minLoc.x + templat1->width, 4 + minLoc.y + templat1->height), CV_RGB(0, 255, 0), 2);



	}
	if (capNum == 2)
	{
		templat2 = cvLoadImage("./模板图片/2.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		templatW = templat2->width;
		templatH = templat2->height;
		resultW = srcW - templatW + 1;
		resultH = srcH - templatH + 1;
		result = cvCreateImage(cvSize(resultW, resultH), 32, 1);
		cvMatchTemplate(src, templat2, result, 1);
		cvMinMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, NULL);
		cvRectangle(savedImg, minLoc, cvPoint(minLoc.x + templat2->width, minLoc.y + templat2->height), CV_RGB(0, 255, 0), -1);
		minLoc.x -= 2;
		minLoc.y -= 2;
		cvRectangle(show, minLoc, cvPoint(4 + minLoc.x + templat2->width, 4 + minLoc.y + templat2->height), CV_RGB(0, 255, 0), 2);

	}
	if (capNum == 3)
	{
		templat3 = cvLoadImage("./模板图片/3.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		templatW = templat3->width;
		templatH = templat3->height;
		resultW = srcW - templatW + 1;
		resultH = srcH - templatH + 1;
		result = cvCreateImage(cvSize(resultW, resultH), 32, 1);
		cvMatchTemplate(src, templat3, result, 1);
		cvMinMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, NULL);
		cvRectangle(savedImg, minLoc, cvPoint(minLoc.x + templat3->width, minLoc.y + templat3->height), CV_RGB(0, 255, 0), -1);
		minLoc.x -= 2;
		minLoc.y -= 2;
		cvRectangle(show, minLoc, cvPoint(4 + minLoc.x + templat3->width, 4 + minLoc.y + templat3->height), CV_RGB(0, 255, 0), 2);
	}
	if (capNum == 4)
	{
		templat4 = cvLoadImage("./模板图片/4.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		templatW = templat4->width;
		templatH = templat4->height;
		resultW = srcW - templatW + 1;
		resultH = srcH - templatH + 1;
		result = cvCreateImage(cvSize(resultW, resultH), 32, 1);
		cvMatchTemplate(src, templat4, result, 1);
		cvMinMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, NULL);
		cvRectangle(savedImg, minLoc, cvPoint(minLoc.x + templat4->width, minLoc.y + templat4->height), CV_RGB(0, 255, 0), -1);
		minLoc.x -= 2;
		minLoc.y -= 2;
		cvRectangle(show, minLoc, cvPoint(4 + minLoc.x + templat4->width, 4 + minLoc.y + templat4->height), CV_RGB(0, 255, 0), 2);
	}
	if (capNum == 5)
	{
		templat5 = cvLoadImage("./模板图片/5.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		templatW = templat5->width;
		templatH = templat5->height;
		resultW = srcW - templatW + 1;
		resultH = srcH - templatH + 1;
		result = cvCreateImage(cvSize(resultW, resultH), 32, 1);
		cvMatchTemplate(src, templat5, result, 1);
		cvMinMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, NULL);
		cvRectangle(savedImg, minLoc, cvPoint(minLoc.x + templat5->width, minLoc.y + templat5->height), CV_RGB(0, 255, 0), -1);
		minLoc.x -= 2;
		minLoc.y -= 2;
		cvRectangle(show, minLoc, cvPoint(4 + minLoc.x + templat5->width, minLoc.y + 4 + templat5->height), CV_RGB(0, 255, 0), 2);
	}
	if (capNum == 6)
	{
		templat6 = cvLoadImage("./模板图片/6.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		templatW = templat6->width;
		templatH = templat6->height;
		resultW = srcW - templatW + 1;
		resultH = srcH - templatH + 1;
		result = cvCreateImage(cvSize(resultW, resultH), 32, 1);
		cvMatchTemplate(src, templat6, result, 1);
		cvMinMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, NULL);
		cvRectangle(savedImg, minLoc, cvPoint(minLoc.x + templat6->width, minLoc.y + templat6->height), CV_RGB(0, 255, 0), -1);
		minLoc.x -= 2;
		minLoc.y -= 2;
		cvRectangle(show, minLoc, cvPoint(4 + minLoc.x + templat6->width, 4 + minLoc.y + templat6->height), CV_RGB(0, 255, 0), 2);
	}
	cout << "第" << capNum << "个琴码匹配度最小值为" << minVal << '\t' << "最大值为" << maxVal << endl;
}
