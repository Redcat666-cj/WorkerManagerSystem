#include<iostream>
#include"worker.h"
#include"manager.h"
#include "employee.h"
#include"boss.h"
#include <fstream>
#define FILENAME "empfile.txt"
#pragma once

using namespace std;
class WorkerManager {
public:
	WorkerManager();
			 

	~WorkerManager();

	

	void show_menu();

	//记录职工人数
	int m_Empnum;

	//职工数组指针
	Worker** m_EmpArray;



	//添加职工
	void add_Emp();

	//保存文件
	void save();
	//判定文件是否为空
	bool m_FileIsempty;

	int getEmpnum();


	//初始化数组
	void Init_emp();

	//展示
	void show_Emem();

	//删除
	void delete_emp();
	//判断是否存在
	int Isexist(int id);
	//重载
	int Isexist(string name);
	//修改
	void mod_Emp();
	//查找
	void find_Emp();

	//排序
	void orderEmp();
	//清空
	void cleanemp();
};
