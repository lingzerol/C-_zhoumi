#pragma once
#ifndef ACLASS_DEBUG
#define ACLASS_DEBUG
#include <iostream>
#include <string>
using namespace std;
#endif
class Student {
public:
	float get_Term_score();
	string get_Name();
	bool information_Process(string);
	Student();
	void output() {
		cout << sname << ' ';
		for (int i = 0; i < score_num; ++i) {
			cout << score[i] << ' ';
		}
		cout << endl;
	}
private:
   
	float get_Medium();
	float *score;
	float mscore;
	float lscore;
	float tscore;
	float medscore;
	int score_num;
	string sname;
};
