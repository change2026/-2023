#include<iostream>
#include"employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "ְ�����Ϊ��" << this->m_Id;
	cout << "ְ������Ϊ��" << this->m_Name;
	cout << "ְ������Ϊ��" << this->getDeptName();
	cout << "��ɾ�����������" << endl;
	cout << endl;
}
string Employee::getDeptName()
{
	return string("Ա��");
}