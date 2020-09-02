#ifndef _VECRESTORE_H
#define _VECRESTORE_H


#include <iostream>
#include <fstream>

using namespace std;

ifstream vecFile1, vecFile2, vecFile3, vecFile4, vecFile5, Sourcepoints;

typedef Point3_<float> point3d;
vector<point3d> vec1;     //2
vector<point3d> vec2;		//12
vector<point3d> vec3;		//10
vector<point3d> vec4;		//9
vector<point3d> vec5;		//9
vector<point3d> Allpoints;   //存储复原点的所有坐标
point3d Temp;

void openVec();
void RestoreVec();


void openVec()
{
	vecFile1.open("./向量/1vec.txt");
	vecFile2.open("./向量/2vec.txt");
	vecFile3.open("./向量/3vec.txt");
	vecFile4.open("./向量/4vec.txt");
	vecFile5.open("./向量/5vec.txt");
	Sourcepoints.open("6Points(Left2Right).txt");
}

void RestoreVec()
{
	vecFile1.open("./向量/1vec.txt");
	vecFile2.open("./向量/2vec.txt");
	vecFile3.open("./向量/3vec.txt");
	vecFile4.open("./向量/4vec.txt");
	vecFile5.open("./向量/5vec.txt");
	Sourcepoints.open("6Points(Left2Right).txt");

	float sour1, sour2, sour3, temp1, temp2, temp3;

	for (int i = 0; !Sourcepoints.eof(); i++)
	{
		Sourcepoints >> sour1 >> sour2 >> sour3;

		if (vecFile1.is_open())
		{
			Temp.x = sour1;
			Temp.y = sour2;
			Temp.z = sour3;
			Allpoints.push_back(Temp);
			for (int j = 0; j < 2; j++)
			{
				vecFile1 >> temp1 >> temp2 >> temp3;
				Temp.x = sour1 + temp1;
				Temp.y = sour2 + temp2;
				Temp.z = sour3 + temp3;
				Allpoints.push_back(Temp);
			}
			vecFile1.close();
			;
			continue;
		}


		if (vecFile2.is_open())
		{
			Temp.x = sour1;
			Temp.y = sour2;
			Temp.z = sour3;
			Allpoints.push_back(Temp);
			for (int j = 0; j < 12; j++)
			{
				vecFile2 >> temp1 >> temp2 >> temp3;
				Temp.x = sour1 + temp1;
				Temp.y = sour2 + temp2;
				Temp.z = sour3 + temp3;
				Allpoints.push_back(Temp);
			}
			vecFile2.close();
			;
			continue;
		}


		if (vecFile3.is_open())
		{
			Temp.x = sour1;
			Temp.y = sour2;
			Temp.z = sour3;
			Allpoints.push_back(Temp);
			for (int j = 0; j < 10; j++)
			{
				vecFile3 >> temp1 >> temp2 >> temp3;
				Temp.x = sour1 + temp1;
				Temp.y = sour2 + temp2;
				Temp.z = sour3 + temp3;
				Allpoints.push_back(Temp);
			}
			vecFile3.close();
			;
			continue;
		}

		if (vecFile4.is_open())
		{
			Temp.x = sour1;
			Temp.y = sour2;
			Temp.z = sour3;
			Allpoints.push_back(Temp);
			for (int j = 0; j < 9; j++)
			{
				vecFile4 >> temp1 >> temp2 >> temp3;
				Temp.x = sour1 + temp1;
				Temp.y = sour2 + temp2;
				Temp.z = sour3 + temp3;
				Allpoints.push_back(Temp);
			}
			vecFile4.close();
			;
			continue;
		}

		if (vecFile5.is_open())
		{
			Temp.x = sour1;
			Temp.y = sour2;
			Temp.z = sour3;
			Allpoints.push_back(Temp);
			for (int j = 0; j < 9; j++)
			{
				vecFile5 >> temp1 >> temp2 >> temp3;
				Temp.x = sour1 + temp1;
				Temp.y = sour2 + temp2;
				Temp.z = sour3 + temp3;
				Allpoints.push_back(Temp);
			}
			vecFile5.close();
			;
			continue;
		}

		Temp.x = sour1;
		Temp.y = sour2;
		Temp.z = sour3;
		Allpoints.push_back(Temp);
	}

	Sourcepoints.close();

	int num = 1;
	for (int i = 0; i < Allpoints.size(); i++)
	{
		cout << num << ":  " << Allpoints.at(i).x << " " << Allpoints.at(i).y << " " << Allpoints.at(i).z << endl;
		num += 1;
	}
}


#endif


