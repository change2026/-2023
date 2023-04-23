#include<iostream>
#include"manager.h"
using namespace std;

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Manager::showInfo()
{
	cout << "职工编号为：" << this->m_Id;
	cout << "职工姓名为：" << this->m_Name;
	cout << "职工部门为：" << this->getDeptName();
	cout << "完成老板交给的任务" << endl;
	cout << endl;

}
string Manager::getDeptName()
{
	return string("manager");
}