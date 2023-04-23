#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker
{
public:

	//前两个等于0的函数为纯虚函数
	//显示个人信息
	virtual void showInfo()=0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_Id;//职工编号
	string m_Name;//职工名称 
	int m_DeptId;//职工所在部门名称编码
 };
