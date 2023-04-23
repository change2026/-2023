#include<iostream>
#include"WorkManager.h"
#include"boss.h"
#include"employee.h"
#include"Worker.h"
#include"manager.h"
using namespace std;

WorkManager::WorkManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	 //文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof为读取文件到最后一个字符为空
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	cout << "职工个数为：" << num << "个" << endl;
	this->m_EmpNum = num;//更新成员属性
	//开辟空间
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();
	
}
void WorkManager::Show_Menu()
{
	cout << "***********************************************" << endl;
	cout << "***** welcome to use managerment system *******" << endl;
	cout << "***************0.退出管理系统******************" << endl;
	cout << "***************1.添加职工信息******************" << endl;
	cout << "***************2.显示职工信息******************" << endl;
	cout << "***************3.删除职工信息******************" << endl;
	cout << "***************4.修改职工信息******************" << endl;
	cout << "***************5.查找职工信息******************" << endl;
	cout << "***************6.按照编号排序******************" << endl;
	cout << "***************7.清空所有文档******************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}
//添加职工
void WorkManager::Add_Emp()
{
	cout << "please enter the num of the employee" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker **newSpace = new Worker*[newSize];
		//将原有空间下的内存内容拷贝到新的内存空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//输入新数量
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "please enter the ID of the employee   " <<i + 1 << endl;
			cin >> id;
			cout << "please enter the name of the employee    " << i + 1 << endl;
			cin >> name;
			cout << "please choice the position of the employee    " << i + 1 << endl;
			cout << "1.employee" <<  endl;
			cout << "2.manager" <<  endl;
			cout << "3.boss" <<  endl;
			cin >> dSelect;
			Worker *worker = NULL;

			switch (dSelect)
			{
			case 1://普通职工
				worker = new Employee(id, name, 1);
				break;
			case 2://经理
				worker = new Manager(id, name, 2);
				break;
			case 3://老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工的指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
			
		}
		//释放原有空间
		delete[]this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//成功添加之后把文件置为false
		this->m_FileIsEmpty = false;
		//提示添加成功
		cout << "成功添加" << addNum << "名新员工" << endl;
	}
	else
	{
		cout << "Wrong number" << endl;
	}
	system("pause");
	system("cls");
}
//保存职工
void WorkManager::save()
{
	fstream ofs;
	ofs.open(FILENAME,ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name << " " << this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while(ifs>>id&&ifs>>name&&ifs>>dId)
	{
		//记录获取到的人数
		num++;
	}
	ifs.close();
	return num;
}
//初始化对象
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker *worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
//显示职工
void WorkManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//判断职工是否存在
int WorkManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}
//删除职工
void WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工编号" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1)//说明职工存在，并且要删掉index位置上的职工
		{
			//数据迁移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组中的记录人数
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "查无此人，删除失败" << endl;
		}
	}
	system("pasue");
	system("cls");
}
//修改职工
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照职工编号修改
		cout << "请输入想要修改职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//说明职工存在
		{
			delete this->m_EmpArray[index];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查找到：" << id << "的职工，请输入新的职工号： " << endl;
			cin >> newId;
			cout << "请输入新的姓名： " << endl;
			cin >> newName;
			cout << "请输入新的岗位： " << endl;
			cin >> dSelect;
			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1://普通职工
				worker = new Employee(newId, newName, 1);
				break;
			case 2://经理
				worker = new Manager(newId, newName, 2);
				break;
			case 3://老板
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;
			cout << "修改成功！" << this->m_EmpArray[index]->m_DeptId << endl;
			this->save();
		}
		else
		{
			cout << "查无此人，修改失败" << endl;
		}
	}
	system("pasue");
	system("cls");
}
//查找职工
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1.按照职工编号查找。" << endl;
		cout << "2.按照姓名查找." << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入要查找的职工编号：" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret!=-1)
			{
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		if (select == 2)
		{
			string name;
			cout << "请输入要查找的姓名：" << endl;
			cin >> name;
			bool flag = false;//查找到的标志
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_Id << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
				else
				{
					cout << "查无此人" << endl;
					flag = false;
				}
			}
		}
		else
		{
			cout << "输入选项有误，请重新输入" << endl;
		}

	}
	system("pasue");
	system("cls");
}
//排序职工
void WorkManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按照职工号进行升序" << endl;
		cout << "2.按照职工号进行降序" << endl; 
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if(this->m_EmpArray[minOrMax]->m_Id<this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker *temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功，排序后的结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
	system("pasue");
	system("cls");
}
//清空文件
void WorkManager::Clean_file()
{
	cout << "是否清空" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式，ios：：trunc  如果存在文件删除文件并重新创建
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
			ofs.close();
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
            this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
			cout << "清除成功" << endl;
			}
	cout << "清除成功" << endl;
	}
	system("pasue");
	system("cls");
}
void WorkManager::Exit_Menu()
{
	cout << "Welcome to use again" << endl;
	system("pause");
	exit(0);
}
WorkManager::~WorkManager()
{
	if(this->m_EmpArray!=NULL)
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}