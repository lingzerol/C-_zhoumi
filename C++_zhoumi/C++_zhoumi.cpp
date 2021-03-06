// C++_zhoumi.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdlib>
#include <fstream>
#include "Student.h"
#include "Aclass.h"

#define MAXN 50
using namespace std;
bool cmp1(float a, float b) {
	return a < b;
}
bool cmp2(Student &a, Student &b) {
	return a.get_Term_score() < b.get_Term_score();
}

Student::Student() {
	score = NULL;
	mscore = -1;
	lscore = -1;
	tscore = -1;
	medscore = -1;
	score_num=-1;
	sname = "\0";
}

float Student::get_Term_score() {
	if (tscore != -1) {
		return tscore;
	}
	else {
		tscore = medscore*0.4 + mscore * 0.2 + lscore * 0.4;
	}
	return tscore;
}
float Student::get_Medium(){
	sort(score, score + score_num, cmp1);
	if (score_num % 2 == 0) {
		return medscore=(score[score_num / 2 - 1] + score[score_num / 2]) / 2.0;
	}
	else return medscore=score[score_num / 2];
}

bool Student::information_Process(string s) {
	string name;
	float temp[MAXN];
	int num = 0;
	bool flag = true;
	for (int i = 0; i < s.size(); ++i) {
		int j = i;
		while (flag&&j<s.size()&&(s.at(j) < '0'||s.at(j) > '9')&&s.at(j)!=' '&&s.at(j)!='\n'&&s.at(j)!='.') {
			++j; 
		}
		if (j != i&&flag)
		{
			flag = false;
			name = s.substr(i, j - i), i = j - 1;
		}
		j = i;
		while (j<s.size()&&(s.at(j) >= '0'&&s.at(j) <= '9'||s.at(j) == '.')) {
			++j;
		}
		if (i == j)
			continue;
		temp[num] = 0;
		float ratio=10,sratio=1;
		for (int k = i; k < j; ++k) {
			if (s.at(k) >= '0'&&s.at(k) <= '9') {
				temp[num] = temp[num] * ratio + (s.at(k) - '0')*sratio;
			}
			if (s.at(k) == '.') {
				ratio = 1;
				sratio = 0.1;
			}
		}
		i = j - 1;
		++num;
	}//获得名字，成绩等
	sname = name; //cout << name;
	score = new float[num];
	score_num = num-2;
	for (int i = 0; i < num-2; ++i) {
		score[i] = temp[i];
	}
	mscore = temp[num - 2];
	lscore = temp[num - 1];
	get_Medium();
	//output();
	//cin >> lscore;
	if (sname != "\0"&&score_num > 2)
		return true;
	else return false;
}

string Student::get_Name() {
	return sname;
}
void Aclass::top_Five(string*str) {
	for (int i = 0; i < 5; ++i) {
		str[i] = tfive[i];
	}
}
void Aclass::last_Five(string*str) {
	for (int i = 0; i < 5; ++i) {
		str[i] = lfive[i];
	}
}
float Aclass::get_Average_score() {
	return averagesc;
}
float Aclass::get_Medium() {
	return maveragesc;
}
 Aclass::Aclass() {
	 s = new Student[25];
	 averagesc = 0;
	 maveragesc = 0;
	 for (int i = 0; i < 5; ++i) {
		 lfive[i] = "\0";
		 tfive[i] = "\0";
	 }
	 snum = 0;
	 ssize = 25;
}
 void Aclass::average_process() {
	 averagesc = 0;
	 for (int i = 0; i < snum; ++i) {
		 averagesc+= s[i].get_Term_score();
	 }
	 averagesc /= snum;

	 middle_average();
 }
 void Aclass::middle_average() {
	 sort(s, s + snum, cmp2);
	 if (snum % 2 == 0) {
		 maveragesc=(s[snum / 2 - 1].get_Term_score() + s[snum / 2].get_Term_score()) / 2;
	 }
	 else maveragesc = s[snum / 2].get_Term_score();
 }
void Aclass::information_Process() {
	 average_process();
	 for (int i = 0; i < ((5>snum)?snum:5); ++i) {
		 lfive[i] = s[i].get_Name();
		 tfive[i] = s[snum - i - 1].get_Name();
	 }
 }
void Aclass::insert_Student(string str) {
	Student s;
	Student *ts;
	s.information_Process(str);
	if (ssize <= snum) {
		ssize <<= 1;
		ts = new Student[ssize];
		for (int i = 0; i < snum; ++i) {
			ts[i] = this->s[i];
		}
		delete[] this->s;
		this->s = ts;
	}//防止溢出
	
	this->s[snum] = s;
	++snum;
}
int main()
{
	ifstream infile;
	string str;
	Aclass c;
	infile.open("./scores.txt");
	while (getline(infile,str)) {
		/*cout << str << endl;
		for (int i = 0; i < str.size(); ++i) {
			cout << (int)str[i];
			system("pause");
		}*/
		//system("pause");
		c.insert_Student(str);
	}//从文本中获取数据并插入到班级中
	c.information_Process();
	string tfive[6], lfive[6];
	float medium, average;
	c.top_Five(tfive);
	c.last_Five(lfive);
	medium = c.get_Medium();
	average = c.get_Average_score();
	cout << "The top five student is:" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << tfive[i] << ' ';
	}cout << endl;
	cout << "The reciprocal five student is:" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << lfive[i] << ' ';
	}cout << endl;
	cout << "The whole class average score is:" << average << endl;
	cout << "The medium score in the class is:" << medium << endl;
	system("pause");
    return 0;
}

