#include "boss.h"

using namespace std;


Boss::Boss(int id, string name, int did) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_Part = did;

}
void Boss::showInfo() {

	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getPart()
		<< "\t部门编号：" << this->m_Part
		<< endl;


}
string Boss::getPart() {

	return "老板";

}
