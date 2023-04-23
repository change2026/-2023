#pragma//防止头文件重复
#include<iostream>
#include"Worker.h"
#include<fstream>
#define FILENAME "emfile.txt"
using namespace std;

class WorkManager
{
public:
	//构造函数
	WorkManager();
	//展示菜单
	void Show_Menu();
   //退出系统
	void Exit_Menu();
	//当前文件中的人数个数
	int m_EmpNum;
	//员工数组的指针
	Worker **m_EmpArray;
	//添加职工
	void Add_Emp();
	//保存职工
	void save();
	//判断文件是否为空
	bool m_FileIsEmpty;
	//统计人数
	int get_EmpNum();
	//初始化数组
	void init_Emp();
	//显示职工信息
	void Show_Emp();
	//判断职工是否存在
	int IsExist(int id);
	//删除职工
	void Del_Emp();
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//排序职工
	void Sort_Emp();
	//清空数据
	void Clean_file();
	//析构函数
	~WorkManager();
};