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
	worker = new Employee(1,"����",1);
	worker->showInfo();
	delete worker;
	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;
	worker = new Boss(3, "����", 3);
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
		case 1://���ְ����Ϣ
			wm.Add_Emp();
			wm.save();
			break;
		case 2://��ʾְ����Ϣ
			wm.Show_Emp();
			break;
		case 3://3.ɾ����ְԱ��
			wm.Del_Emp();
			break;
		case 4://4.�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5://5.����ְ����Ϣ
			wm.Find_Emp();
			break;
		case 6://6.���ձ������
			wm.Sort_Emp();
			break;
		case 7://7.��������ĵ�
			break;
		case 0://�˳�����
			wm.Exit_Menu();
			break;
		}
	}
	system("pause");
	return 0;
}