#pragma once
#include<iostream>
#include"Worker.h"
class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);

	virtual void showInfo();
	
	virtual string getDeptName();
};
