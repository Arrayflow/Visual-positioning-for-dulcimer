#ifndef _CLICK_H
#define _CLICK_H

#include <iostream>
#include <sstream>
#include "realsense.h"
#include "rsutil.h"
#include <cstdio>
#include <fstream>


using namespace std;
using namespace cv;

//3D坐标存放于vector容器中，5排琴码5个容器，
typedef Point3_<float> point3d;
vector<point3d> _3Dpoints1;     //2
vector<point3d> _3Dpoints2;		//12
vector<point3d> _3Dpoints3;		//10
vector<point3d> _3Dpoints4;		//9
vector<point3d> _3Dpoints5;		//9
point3d temp;

vector<point3d> resource;
point3d source;

//3D向量存放于vector中
vector<point3d> vec11;     //2
vector<point3d> vec22;		//12
vector<point3d> vec33;		//10
vector<point3d> vec44;		//9
vector<point3d> vec55;		//9
point3d vec;                //相减后的中间变量




rs2_intrinsics depth_intrin;
void on_mouse(int event, int x, int y, int flags, void* ustc);
void openFiles();

//初始化参数
int a = 0;
int b = 0;
float point[3] = { 0,0,0 };
float pixel[2] = { 0,0 };
float Distance = 0.0;
//点击次数初始化
int clickNum = 0;
//读取图片
Mat Depth = imread("./depth&color/13.png");       //depth
Mat Color = imread("./depth&color/13.bmp");        //RGB图像







void ParaInit()
{
	depth_intrin.width = 1280;
	depth_intrin.height = 720;
	depth_intrin.ppx = 640.715;
	depth_intrin.ppy = 371.578;
	depth_intrin.fx = 923.107;
	depth_intrin.fy = 923.089;
	depth_intrin.model = RS2_DISTORTION_BROWN_CONRADY;
}

void on_mouse(int event, int x, int y, int flags, void* ustc)
{
	if ((event == CV_EVENT_LBUTTONDOWN))//鼠标左键按下事件发生  
	{
		CvPoint pt = cvPoint(x, y);//获取当前点的横纵坐标值 
		cout << x << "," << y << endl;
		a = x;
		b = y;
		pixel[0] = a;
		pixel[1] = b;
		ushort* DepthData = Depth.ptr<ushort>(b);// 每一行灰度图像的指针
		Distance = DepthData[a] / 40;
		if (Distance == 0)                       //保证每一点深度值都存在
		{
			cout << "该点深度值缺失，重新点击" << endl;
		}
		else
		{


			rs2_deproject_pixel_to_point(point, &depth_intrin, pixel, Distance);
			cout << point[0] << " " << point[1] << " " << point[2] << endl;
			temp.x = point[0];
			temp.y = point[1];
			temp.z = point[2];
			if (clickNum < 2) {           //第一排
				_3Dpoints1.push_back(temp);
				vec.x = temp.x - resource.at(0).x;
				vec.y = temp.y - resource.at(0).y;
				vec.z = temp.z - resource.at(0).z;
				vec11.push_back(vec);
				//ofstream Outfile1("./每列坐标/1Col.txt", ios::app);
				//Outfile1 << temp.x << "," << temp.y << "," << temp.z << endl;
				//Outfile1.close();
				//ofstream Outfile2("./向量/1vec.txt", ios::app);
				//Outfile2 << vec.x << " " << vec.y << " " << vec.z << endl;
				//Outfile2.close();
			}
			else if (clickNum >= 2 && clickNum < 14) {    //第二排
				_3Dpoints2.push_back(temp);
				vec.x = temp.x - resource.at(1).x;
				vec.y = temp.y - resource.at(1).y;
				vec.z = temp.z - resource.at(1).z;
				vec22.push_back(vec);
				//ofstream Outfile1("./每列坐标/2Col.txt", ios::app);
				//Outfile1 << temp.x << "," << temp.y << "," << temp.z << endl;
				//Outfile1.close();
				//ofstream Outfile2("./向量/2vec.txt", ios::app);
				//Outfile2 << vec.x << " " << vec.y << " " << vec.z << endl;
				//Outfile2.close();
			}
			else if (clickNum >= 14 && clickNum < 24) {   //第三排
				_3Dpoints3.push_back(temp);
				vec.x = temp.x - resource.at(2).x;
				vec.y = temp.y - resource.at(2).y;
				vec.z = temp.z - resource.at(2).z;
				vec33.push_back(vec);
				//ofstream Outfile1("./每列坐标/3Col.txt", ios::app);
				//Outfile1 << temp.x << "," << temp.y << "," << temp.z << endl;
				//Outfile1.close();
				//ofstream Outfile2("./向量/3vec.txt", ios::app);
				//Outfile2 << vec.x << " " << vec.y << " " << vec.z << endl;
				//Outfile2.close();
			}
			else if (clickNum >= 24 && clickNum < 33) {    //第四排
				_3Dpoints4.push_back(temp);
				vec.x = temp.x - resource.at(3).x;
				vec.y = temp.y - resource.at(3).y;
				vec.z = temp.z - resource.at(3).z;
				vec44.push_back(vec);
				//ofstream Outfile1("./每列坐标/4Col.txt", ios::app);
				//Outfile1 << temp.x << "," << temp.y << "," << temp.z << endl;
				//Outfile1.close();
				//ofstream Outfile2("./向量/4vec.txt", ios::app);
				//Outfile2 << vec.x << " " << vec.y << " " << vec.z << endl;
				//Outfile2.close();
			}
			else {										//第五排
				_3Dpoints5.push_back(temp);
				vec.x = temp.x - resource.at(4).x;
				vec.y = temp.y - resource.at(4).y;
				vec.z = temp.z - resource.at(4).z;
				vec55.push_back(vec);
				//ofstream Outfile1("./每列坐标/5Col.txt", ios::app);
				//Outfile1 << temp.x << "," << temp.y << "," << temp.z << endl;
				//Outfile1.close();
				//ofstream Outfile2("./向量/5vec.txt", ios::app);
				//Outfile2 << vec.x << " " << vec.y << " " << vec.z << endl;
				//Outfile2.close();
			}




			clickNum += 1;
			if (clickNum == 42) {
				for (int i = 0; i < _3Dpoints3.size(); i++)
				{
					cout << "[" << _3Dpoints3.at(i).x << "," << _3Dpoints3.at(i).y << " " << _3Dpoints3.at(i).z << "]" << endl;
				}

				destroyAllWindows();
			}
		}




	}
}

//打开并导入数据
void openFiles()
{
	float temp1, temp2, temp3;
	//读取传过来的文件数据，进行相减后得到向量

	ifstream files("6Points(Left2Right).txt");

	for (int i = 0; i < 6; i++)
	{
		files >> temp1 >> temp2 >> temp3;
		source.x = temp1;
		source.y = temp2;
		source.z = temp3;
		resource.push_back(source);
	}
	files.close();
}

/*
void on_mouse(int EVENT, int x, int y, int flags, void* userdata)
{
	Get_3D_Data();
	static int num = 0;
	float Point_2D[2][2] = { 0 };//点击的坐标
	float Point_3D[2][3] = { 0 };
	//Mat img;
	//img = *(Mat*)userdata;
	switch (EVENT)
	{
	case EVENT_LBUTTONDOWN:
	{
		ushort* DepthData = Depth.depth_mat.ptr<ushort>(y);// 每一行灰度图像的指针
		float depth = DepthData[x] / 30;
		if (num == 0)
		{
			Point_2D[0][0] = x;
			Point_2D[0][1] = y;
			rs2_deproject_pixel_to_point(Point_3D[0], &D435.depth_intrin, Point_2D[0], depth);
			//Pixel_to_Point(x, y, depth, Point_3D[0]);
			printf("点1三维坐标为：%.3lf,%.3lf,%.3lf\n", Point_3D[0][0], Point_3D[0][1], Point_3D[0][2]);
		}
		else if (num == 1)
		{
			Point_2D[1][0] = x;
			Point_2D[1][1] = y;
			rs2_deproject_pixel_to_point(Point_3D[1], &D435.depth_intrin, Point_2D[1], depth);

			double distance = (Point_3D[1][0] - Point_3D[0][0])*(Point_3D[1][0] - Point_3D[0][0])
				+ (Point_3D[1][1] - Point_3D[0][1])*(Point_3D[1][1] - Point_3D[0][1])
				+ (Point_3D[1][2] - Point_3D[0][2])*(Point_3D[1][2] - Point_3D[0][2]);
			distance = sqrt(distance);
			printf("点2三维坐标为：%.3lf,%.3lf,%.3lf,距离为：%.3lf \n", Point_3D[1][0], Point_3D[1][1], Point_3D[1][2], distance);
		}

		num++;
		if (num >= 2)num = 0;
	}
	break;
	}

}*/

#endif // !_CLICK_H