#include "workermanager.h"

using namespace std;


WorkerManager::WorkerManager() {

	//展示菜单函数
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open()) {
		cout << "文件不存在"<<endl;

		this->m_Empnum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsempty = true;
		ifs.close();
		return;
	}
	//文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {

		//文件为空
		cout << "文件为空" << endl;
		this->m_Empnum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsempty = true;
		ifs.close();
		return;
	}
	//文件存在 并且记录数据
	int num = this->getEmpnum();
	cout << "职工人数为" << this->getEmpnum() << endl;
	this->m_Empnum = num;

	//开辟空间

	this->m_EmpArray = new Worker * [this->m_Empnum];

	//将数据存到数组
	this->Init_emp();

	for (int i = 0; i < this->m_Empnum; i++) {

		cout << "职工编号：" << this->m_EmpArray[i]->m_Id 
			 <<"姓名："<<this->m_EmpArray[i]->m_Name
			 <<"部门编号:"<<this->m_EmpArray[i]->m_Part<<endl;

	}
}
int WorkerManager::getEmpnum() {
	int num = 0;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读
	int id;
	string name;
	int Did;
	while (ifs >> id && ifs >> name && ifs >> Did) {
		//统计人数
		num++;
	}
	return num;
}


void WorkerManager::show_Emem() {
	//判断文件是否为空
	if (this->m_FileIsempty) {
		cout << "文件不存在或者为空" << endl;

	}
	else {
		for(int i = 0;i<this->m_Empnum;i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	
	}
	system("pause");

	system("cls");
}
//删除
void WorkerManager::delete_emp() {
	int index = 0;
	if (this->m_FileIsempty)
	{
		cout << "文件不存在或者为空" << endl;

	};
	int id = 0;
	cin >> id;
	this->Isexist(id);
	if (this->Isexist(id) == -1) {

		cout << "用户不存在" << endl;

	}
	else {
		int index = 1;
		index = this->Isexist(id);
		for ( index ; index< this->m_Empnum - 1; index++) {

			this->m_EmpArray[index] = this->m_EmpArray[index + 1];
			
		}
		this->m_Empnum--;
		this->save();
	}


	system("pause");

	system("cls");

};
//判断是否存在
int WorkerManager ::Isexist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_Empnum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			 index = i;
			break;

		}


	}

	return index;

};

//重载姓名
int WorkerManager::Isexist(string name) {
	int index = -1;
	for (int i = 0; i < this->m_Empnum; i++) {
		if (this->m_EmpArray[i]->m_Name == name) {
			index = i;
			break;

		}


	}

	return index;

};
void WorkerManager ::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); // 用输出模式打开文件，会清空原有内容

	// 遍历所有职工，利用多态调用正确的信息保存方式
	for (int i = 0; i < this->m_Empnum; i++) {
		// 使用基类指针调用虚函数，实现多态
		// 每个派生类都会按照自己的格式保存数据
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_Part << endl;
	}

	ofs.close();
	cout << "数据保存成功！共保存了 " << this->m_Empnum << " 条记录。" << endl;
};
void WorkerManager:: mod_Emp() {

	if (this->m_FileIsempty) {

		cout << "error" << endl;

	}
	else {

		cout << "请输入要修改的职工id" << endl;
		int id;
		cin >> id;
		int ret = this->Isexist(id);
		if (ret != -1) {
			//存在
			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = " ";
			int newpid = 0;
			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newid;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请输入岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> newpid;


			Worker* worker = NULL;
			switch (newpid) {
				case 1:
					worker = new Emoployee(newid, newname, newpid);
					break;
					
				case 2:
					worker = new Manager(newid, newname, newpid);
					break;
				case 3:
					worker = new Boss(newid, newname, newpid);
					break;
				default:
					break;

			}
			//更新数据到数组
			this->m_EmpArray[ret] = worker;
			cout<<"修改成功"<<endl;

			//保存
			this->save();

		}
		else
		{
			cout << "职工不存在" << endl;
		}


	}

	system("pause");
	system("cls");

}
//查找
void WorkerManager::find_Emp() {
	
	int select = 0;
	cout << "请选择查找的方式" << endl;
	cout << "1->按id查找" << endl;
	cout << "2->按姓名查找" << endl;
	cin >> select;
	switch (select) {
		
	case 1:
	{
		//1.按id查找
		int id = 0;
		cout << "请输入id" << endl;
		cin >> id;
		int ret = this->Isexist(id);
		if (ret != -1) {

			this->m_EmpArray[ret]->showInfo();

		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}
		break;
	case 2:
	{
		string name;
		cout << "请输入寻找的职工姓名" << endl;
		cin >> name;
		int ret2 = this->Isexist(name);
		if (ret2 != -1) {

			this->m_EmpArray[ret2]->showInfo();

		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}


		break;




	}

	system("pause");

	system("cls");
}
//排序
void WorkerManager::orderEmp() {

	if (this->m_FileIsempty)
	{
		cout << "文件不存在或者为空" << endl;
		
	}else
	{
		cout << "请输入1.升序，2.降序" << endl;
		int ret = 0;
		cin >> ret;
		if (ret == 1)
		{
			for (int i = 0; i < this->m_Empnum - 1; i++) {
				for (int j = 0; j < this->m_Empnum - 1 - i; j++) {
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
					{
						Worker* worker;
						worker = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = worker;
					}


				}

			}
		}
		if (ret == 2) {

			for (int i = 0; i < this->m_Empnum - 1; i++) {
				for (int j = 0; j < this->m_Empnum - 1 - i; j++) {
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
					{
						Worker* worker;
						worker = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = worker;
					}


				}

			}



		}







		cout << "排序成功" << endl;
		this->save();
		this->show_Emem();
	}
}

void WorkerManager::cleanemp() {

	cout << "确定清空吗" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {


		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL) {

			for (int i = 0; i < this->m_Empnum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_Empnum = 0;
			this->m_FileIsempty = true;

		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");


}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_Empnum; i++) {
			if (this->m_EmpArray[i] != NULL) {
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}

} 
void WorkerManager::show_menu() {

	cout << "****************************************" << endl;
	cout << "*********欢迎来到职工系统***************" << endl;
	cout << "**************0.退出职工系统************" << endl;
	cout << "**************1.增加职工信息************" << endl;
	cout << "**************2.显示职工信息****** *****" << endl;
	cout << "**************3.删除离职职工************" << endl;
	cout << "**************4.修改职工信息************" << endl;
	cout << "**************5.查找职工信息************" << endl;
	cout << "**************6.按照编号排序************" << endl;
	cout << "**************7.清空所有文档************" << endl;
	cout << "****************************************" << endl;

}
void WorkerManager::add_Emp() {
	cout << "增加职工函数数量" << endl;

	int addnum = 0;
	cin >> addnum;
	if (addnum > 0) {

		//添加
		//计算新增加空间大小
		int newsize = this->m_Empnum + addnum;//新空间的人数

		//开辟新空间
		Worker** newspace = new Worker * [newsize];

		//将原来空间下数据拷贝到新空间下
		if (this->m_EmpArray != NULL) {

			for (int i = 0; i < this->m_Empnum; i++) {

				newspace[i] = this->m_EmpArray[i];
			}

		}

		//批量添加新数据
		for (int i = 0; i < addnum; i++) {

			int id;
			string name;
			int Pselect;
			cout << "请输入第 " << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的的名字" << endl;
			cin >> name;
			cout << "请确认职务" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> Pselect;

			Worker* worker = NULL;
			switch (Pselect) {

			case 1:
				worker = new Emoployee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
			default:
				break;

			}
			//初始化下一次打开职工指向的首个职工
			newspace[this->m_Empnum + i] = worker;

		}
		//释放有原有空间
		delete[]this->m_EmpArray;


		//更改新空间的指向
		this->m_EmpArray = newspace;

		//更新新的职工人数
		this->m_Empnum = newsize;
		this->m_FileIsempty = false;

		cout << "成功添加" << addnum << "名职工" << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	system("pause");

	system("cls");
}

//初始化成员数组
void WorkerManager::Init_emp() {
	Worker* worker;
	int index =0;
	int id;
	string name;
	int did;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	while (ifs >> id && ifs >> name && ifs >> did) {

		if (did == 1) {

			worker = new Emoployee (id, name, did);

		}
		else if (did == 2) {

			worker = new Manager(id, name, did);

		}
		else  {

			worker = new Boss(id, name, did);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}


	ifs.close();

}
//void menu() {
//
//
//
//}



//int main() {
//	int ret = 0;
//	do {
//		
//		
//		cin >> ret;
//
//		switch (ret) {
//		case 0:
//			cout << "欢迎下次使用" << endl;
//			break;
//		case 1:
//			cout << "增加职工信息" << endl;
//			break;
//		case 2:
//			cout << "显示职工信息" << endl;
//			break;
//		case 3:
//			cout << "删除离职职工" << endl;
//			break;
//		case 4:
//			cout << "修改职工信息" << endl;
//			break;
//		case 5:
//			cout << "查找职工信息" << endl;
//			break;
//		case 6:
//			cout << "按照编号排序" << endl;
//
//			break;
//
//		case 7:
//			cout << "清空所有文档" << endl;
//			break;
//		default:
//			cout << "输入错误，请重新输入" << endl;
//		}
//
//
//	} while (ret);
//
//
//
//
//	system("pause");
//
//
//
//	return 0;
//}
//
