#pragma once
#ifndef ACLASS_DEBUG
#define ACLASS_DEBUG
#include <iostream>
#include <string>
using namespace std;
#endif
class Student {
public:
	float get_Term_score();//获得学生学期总成绩
	string get_Name();//获得学生名字
	bool information_Process(string);//处理学生数据
	Student();//初始化变量
	void output() {
		cout << sname << ' ';
		for (int i = 0; i < score_num; ++i) {
			cout << score[i] << ' ';
		}
		cout << endl;
	}//用于测试
private:
   
	float get_Medium();//获得成绩的中位数
	float *score;//学生的所有成绩
	float mscore;//期中成绩
	float lscore;//期末成绩
	float tscore;//学期总成绩
	float medscore;//成绩的中位数
	int score_num;//成绩数目
	string sname;//学生名字
};
