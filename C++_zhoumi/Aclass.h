#pragma once
#ifndef STUDENT_DEBUG
#define STUDENT_DEBUG
#include <iostream>
#include <string>
using namespace std;
#endif
class Aclass {
public:
	void  top_Five(string*);//���ǰ��ѧ��
	void last_Five(string*);//��õ���ǰ���ѧ��
	float get_Average_score();//���ƽ���ɼ�
	float get_Medium();//��óɼ�����λ��
	void information_Process();//������������
	void insert_Student(string);//����ѧ��
	Aclass();//��ʼ������
private:
	void average_process();//��༶��ƽ���ɼ�
	void middle_average();//���ܳɼ�����λ��
	string tfive[5];//ǰ���ѧ��
	string lfive[5];//����ǰ���ѧ��
	float averagesc;//����༶��ƽ���ɼ�
	float maveragesc;//����ɼ�����λ��
	int snum;//����ѧ��������
	int ssize;//s����Ĵ�С
	Student *s;//���ڱ���ѧ���ɼ�
};
