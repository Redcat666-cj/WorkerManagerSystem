#include"employee.h"
//构造
 Emoployee::Emoployee(int id, string name ,int did) {

	 this->m_Id = id;
	 this->m_Name = name;
	 this->m_Part = did;

}
 //显示个人信息 
 void Emoployee::showInfo() {

	 cout << "职工编号：" << this->m_Id
		 << "\t职工姓名：" << this->m_Name
		 << "\t岗位：" << this->getPart()
		 << "\t部门编号：" << this->m_Part
		 << endl;
	 
 }
 //获取岗位名称
 string Emoployee::getPart() {

	 return "普通职工";
 }
	 
 
