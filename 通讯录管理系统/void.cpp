#include"Head.h"


//菜单界面
void showMenu() {
	std::cout << "************************" << std::endl;
	std::cout << "***** 1.添加联系人 *****" << std::endl;
	std::cout << "***** 2.显示联系人 *****" << std::endl;
	std::cout << "***** 3.删除联系人 *****" << std::endl;
	std::cout << "***** 4.查找联系人 *****" << std::endl;
	std::cout << "***** 5.修改联系人 *****" << std::endl;
	std::cout << "***** 6.清空联系人 *****" << std::endl;
	std::cout << "***** 0.退出通讯录 *****" << std::endl;
	std::cout << "************************" << std::endl;
}
//添加联系人
void addPerson(struct Addressbook* abs) {
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == Max) {
		std::cout << "通讯录已满，无法添加" << std::endl;
		return;
	}
	else {
		//添加具体联系人

		//姓名
		std::string name;
		std::cout << "请输入姓名：" << std::endl;
		std::cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		std::cout << "请输入性别（1-男 2-女）：" << std::endl;
		int sex;
		std::cin >> sex;
		while (sex != 1 && sex != 2) {
			std::cout << "输入错误，请输入正确性别（1-男 2-女）" << std::endl;
			std::cin >> sex;
		}
		abs->personArray[abs->m_Size].m_Sex = sex;
		//年龄
		std::cout << "请输入年龄：" << std::endl;
		int age;
		std::cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		std::cout << "请输入电话：" << std::endl;
		std::string phone;
		std::cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//地址
		std::cout << "请输入地址：" << std::endl;
		std::string address;
		std::cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;
		abs->m_Size++;
		std::cout << "添加成功" << std::endl;
	}
}
//显示联系人
void showPerson(struct Addressbook* abs) {
	if (abs->m_Size == 0) {
		std::cout << "当前通讯录为空" << std::endl;
		return;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			std::cout << "第" << i + 1 << "位" << std::endl;
			std::cout << "姓名；" << abs->personArray[i].m_Name << std::endl;
			std::cout << "年龄：" << abs->personArray[i].m_Age << std::endl;
			if (abs->personArray[i].m_Sex == 1) {
				std::cout << "性别：男" << std::endl;
			}
			else {
				std::cout << "性别：女" << std::endl;
			}
			std::cout << "电话号码：" << abs->personArray[i].m_Phone << std::endl;
			std::cout << "地址：" << abs->personArray[i].m_Address << std::endl;
			std::cout << "共有" << abs->m_Size << "个人" << std::endl;
		}
	}
}
//删除联系人
void deletePerson(struct Addressbook* abs) {
	//pos存储要删除的人的位置（-1表示没找到）
	int pos = -1;
	if (abs->m_Size == 0) {
		std::cout << "通讯录为空，无人可以删除" << std::endl;
		return;
	}
	else {
		//输入要删除的人的姓名
		std::string name;
		std::cout << "请输入要删除的联系人的姓名：" << std::endl;
		std::cin >> name;
		for (int i = 0; i < abs->m_Size; i++) {
			if (name == abs->personArray[i].m_Name) {
				pos = i;
				break;
				}
			}
		if (pos == -1) {
			std::cout << "没找到叫 " << name << " 的人" << std::endl;
			return;
			}
		}
		//找到name，删除代码
		for (int j = pos; j < abs->m_Size; j++) {
			abs->personArray[j] = abs->personArray[j + 1];//后续联系人前移一位
		}
		abs->m_Size--;
		std::cout << "删除成功" << std::endl;
}