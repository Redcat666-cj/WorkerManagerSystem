//多文件项目报错 link2005重定义 在项目属性连接器中添加 /FORCE:MULTIPLE命令行
#include "workermanager.h"

using namespace std;


int main() {

	WorkerManager wm;

	


	int ret = 0;
		do {
			wm.show_menu();

			
			cin >> ret;
	
			switch (ret) {
			case 0:
				cout << "欢迎下次使用" << endl;
				break;
			case 1:
				wm.add_Emp();
				cout << "增加职工信息" << endl;

				break;
			case 2:
				cout << "显示职工信息" << endl;
				wm.show_Emem();
				break;
			case 3:
				cout << "删除离职职工" << endl;
				wm.delete_emp();
				break;
			case 4:
				cout << "修改职工信息" << endl;
				wm.mod_Emp();
				break;
			case 5:
				cout << "查找职工信息" << endl;
				wm.find_Emp();
				break;
			case 6:
				cout << "按照编号排序" << endl;
				wm.orderEmp();
				break;
	
			case 7:
				cout << "清空所有文档" << endl;
				wm.cleanemp();
				break;
			default:
				cout << "输入错误，请重新输入" << endl;
			}
	
	
		} while (ret);
	
	
	
	
	
	
	
	


	return 0;
}
