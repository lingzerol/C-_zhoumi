#pragma once
#ifndef STUDENT_DEBUG
#define STUDENT_DEBUG
#include <iostream>
#include <string>
using namespace std;
#endif
class Aclass {
public:
	void  top_Five(string*);//获得前五学生
	void last_Five(string*);//获得倒数前五的学生
	float get_Average_score();//获得平均成绩
	float get_Medium();//获得成绩的中位数
	void information_Process();//处理所有数据
	void insert_Student(string);//插入学生
	Aclass();//初始化变量
private:
	void average_process();//求班级的平均成绩
	void middle_average();//求总成绩的中位数
	string tfive[5];//前五的学生
	string lfive[5];//倒数前五的学生
	float averagesc;//保存班级的平均成绩
	float maveragesc;//保存成绩的中位数
	int snum;//保存学生的数量
	int ssize;//s数组的大小
	Student *s;//用于保存学生成绩
};
