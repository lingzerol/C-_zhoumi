#pragma once
#ifndef ACLASS_DEBUG
#define ACLASS_DEBUG
#include <iostream>
#include <string>
using namespace std;
#endif
class Student {
public:
	float get_Term_score();//���ѧ��ѧ���ܳɼ�
	string get_Name();//���ѧ������
	bool information_Process(string);//����ѧ������
	Student();//��ʼ������
	void output() {
		cout << sname << ' ';
		for (int i = 0; i < score_num; ++i) {
			cout << score[i] << ' ';
		}
		cout << endl;
	}//���ڲ���
private:
   
	float get_Medium();//��óɼ�����λ��
	float *score;//ѧ�������гɼ�
	float mscore;//���гɼ�
	float lscore;//��ĩ�ɼ�
	float tscore;//ѧ���ܳɼ�
	float medscore;//�ɼ�����λ��
	int score_num;//�ɼ���Ŀ
	string sname;//ѧ������
};
