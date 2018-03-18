#pragma once
#ifndef STUDENT_DEBUG
#define STUDENT_DEBUG
#include <iostream>
#include <string>
using namespace std;
#endif
class Aclass {
public:
	void  top_Five(string*);
	void last_Five(string*);
	float get_Average_score();
	float get_Medium();
	void information_Process();
	void insert_Student(string);
	Aclass();
private:
	void average_process();
	void middle_average();
	string tfive[5];
	string lfive[5];
	float averagesc;
	float maveragesc;
	int snum;
	int ssize;
	Student *s;
};
