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
	cout << "职工编号为：" << this->m_Id;
	cout << "职工姓名为：" << this->m_Name;
	cout << "职工部门为：" << this->getDeptName();
	cout << "下发任务给经理" << endl;
	cout << endl;
}

string Boss::getDeptName()
{
	return string("boss");
}