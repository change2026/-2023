#include<iostream>
#include"boss.h"
using namespace std;

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Boss::showInfo()
{
	cout << "ְ�����Ϊ��" << this->m_Id;
	cout << "ְ������Ϊ��" << this->m_Name;
	cout << "ְ������Ϊ��" << this->getDeptName();
	cout << "�·����������" << endl;
	cout << endl;
}

string Boss::getDeptName()
{
	return string("boss");
}