#pragma//��ֹͷ�ļ��ظ�
#include<iostream>
#include"Worker.h"
#include<fstream>
#define FILENAME "emfile.txt"
using namespace std;

class WorkManager
{
public:
	//���캯��
	WorkManager();
	//չʾ�˵�
	void Show_Menu();
   //�˳�ϵͳ
	void Exit_Menu();
	//��ǰ�ļ��е���������
	int m_EmpNum;
	//Ա�������ָ��
	Worker **m_EmpArray;
	//���ְ��
	void Add_Emp();
	//����ְ��
	void save();
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	//ͳ������
	int get_EmpNum();
	//��ʼ������
	void init_Emp();
	//��ʾְ����Ϣ
	void Show_Emp();
	//�ж�ְ���Ƿ����
	int IsExist(int id);
	//ɾ��ְ��
	void Del_Emp();
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����ְ��
	void Sort_Emp();
	//�������
	void Clean_file();
	//��������
	~WorkManager();
};