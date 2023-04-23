#include<iostream>
#include<string>
#include"WorkManager.h"
#include"boss.h"
#include"employee.h"
#include"Worker.h"
#include"manager.h"
using namespace std;

/*void test()
{
	Worker *worker = NULL;
	worker = new Employee(1,"张三",1);
	worker->showInfo();
	delete worker;
	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;
	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;

}*/
int main()
{
	
	WorkManager wm;
	int choice = 0;;
	while (true)
	{
		wm.Show_Menu();
		cin >> choice;
		switch (choice)
		{
		case 1://添加职工信息
			wm.Add_Emp();
			wm.save();
			break;
		case 2://显示职工信息
			wm.Show_Emp();
			break;
		case 3://3.删除离职员工
			wm.Del_Emp();
			break;
		case 4://4.修改职工信息
			wm.Mod_Emp();
			break;
		case 5://5.查找职工信息
			wm.Find_Emp();
			break;
		case 6://6.按照编号排序
			wm.Sort_Emp();
			break;
		case 7://7.清空所有文档
			break;
		case 0://退出程序
			wm.Exit_Menu();
			break;
		}
	}
	system("pause");
	return 0;
}