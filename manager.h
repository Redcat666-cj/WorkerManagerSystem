#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class Manager : public Worker {

public:
	//构造
	Manager(int id, string name, int did);
	//显示个人信息
	void showInfo();
	//获取岗位名称
	string getPart();
	//虚析构函数
	//virtual ~Manager() { cout << "Manager析构函数调用" << endl; }




};

