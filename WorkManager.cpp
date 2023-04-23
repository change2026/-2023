#include<iostream>
#include"WorkManager.h"
#include"boss.h"
#include"employee.h"
#include"Worker.h"
#include"manager.h"
using namespace std;

WorkManager::WorkManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	 //�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())//eofΪ��ȡ�ļ������һ���ַ�Ϊ��
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << "��" << endl;
	this->m_EmpNum = num;//���³�Ա����
	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();
	
}
void WorkManager::Show_Menu()
{
	cout << "***********************************************" << endl;
	cout << "***** welcome to use managerment system *******" << endl;
	cout << "***************0.�˳�����ϵͳ******************" << endl;
	cout << "***************1.���ְ����Ϣ******************" << endl;
	cout << "***************2.��ʾְ����Ϣ******************" << endl;
	cout << "***************3.ɾ��ְ����Ϣ******************" << endl;
	cout << "***************4.�޸�ְ����Ϣ******************" << endl;
	cout << "***************5.����ְ����Ϣ******************" << endl;
	cout << "***************6.���ձ������******************" << endl;
	cout << "***************7.��������ĵ�******************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}
//���ְ��
void WorkManager::Add_Emp()
{
	cout << "please enter the num of the employee" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker **newSpace = new Worker*[newSize];
		//��ԭ�пռ��µ��ڴ����ݿ������µ��ڴ�ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//����������
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
			case 1://��ְͨ��
				worker = new Employee(id, name, 1);
				break;
			case 2://����
				worker = new Manager(id, name, 2);
				break;
			case 3://�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ����ָ�뱣�浽������
			newSpace[this->m_EmpNum + i] = worker;
			
		}
		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//�ɹ����֮����ļ���Ϊfalse
		this->m_FileIsEmpty = false;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����Ա��" << endl;
	}
	else
	{
		cout << "Wrong number" << endl;
	}
	system("pause");
	system("cls");
}
//����ְ��
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
		//��¼��ȡ��������
		num++;
	}
	ifs.close();
	return num;
}
//��ʼ������
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
//��ʾְ��
void WorkManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
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
//�ж�ְ���Ƿ����
int WorkManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}
//ɾ��ְ��
void WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1)//˵��ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
		{
			//����Ǩ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������еļ�¼����
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "���޴��ˣ�ɾ��ʧ��" << endl;
		}
	}
	system("pasue");
	system("cls");
}
//�޸�ְ��
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//����ְ������޸�
		cout << "��������Ҫ�޸�ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//˵��ְ������
		{
			delete this->m_EmpArray[index];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "���ҵ���" << id << "��ְ�����������µ�ְ���ţ� " << endl;
			cin >> newId;
			cout << "�������µ������� " << endl;
			cin >> newName;
			cout << "�������µĸ�λ�� " << endl;
			cin >> dSelect;
			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1://��ְͨ��
				worker = new Employee(newId, newName, 1);
				break;
			case 2://����
				worker = new Manager(newId, newName, 2);
				break;
			case 3://�ϰ�
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;
			cout << "�޸ĳɹ���" << this->m_EmpArray[index]->m_DeptId << endl;
			this->save();
		}
		else
		{
			cout << "���޴��ˣ��޸�ʧ��" << endl;
		}
	}
	system("pasue");
	system("cls");
}
//����ְ��
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.����ְ����Ų��ҡ�" << endl;
		cout << "2.������������." << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret!=-1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		if (select == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�������" << endl;
			cin >> name;
			bool flag = false;//���ҵ��ı�־
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
				else
				{
					cout << "���޴���" << endl;
					flag = false;
				}
			}
		}
		else
		{
			cout << "����ѡ����������������" << endl;
		}

	}
	system("pasue");
	system("cls");
}
//����ְ��
void WorkManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.����ְ���Ž�������" << endl;
		cout << "2.����ְ���Ž��н���" << endl; 
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
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}
	system("pasue");
	system("cls");
}
//����ļ�
void WorkManager::Clean_file()
{
	cout << "�Ƿ����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽ��ios����trunc  ��������ļ�ɾ���ļ������´���
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
			cout << "����ɹ�" << endl;
			}
	cout << "����ɹ�" << endl;
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