#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;


class Emoployee : public Worker {

public:
	//构造

	Emoployee(int id, string name, int did);
	//显示个人信息
	void showInfo();


 
	//获取岗位名称
	string getPart();



 
	

};
