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
	cout << "ְ�����Ϊ��" << this->m_Id;
	cout << "ְ������Ϊ��" << this->m_Name;
	cout << "ְ������Ϊ��" << this->getDeptName();
	cout << "����ϰ彻��������" << endl;
	cout << endl;

}
string Manager::getDeptName()
{
	return string("manager");
}