#pragma 
#include<iostream>
#include<string>
#define Max 1000
//联系人结构体
struct Person {
	std::string m_Name;
	int m_Sex;
	int m_Age;
	std::string m_Phone;
	std::string m_Address;

};
//通讯录结构体
struct Addressbook {
	//通讯录中保存的联系人数组
	struct Person personArray[Max];
	//通讯录中当前记录联系人个数
	int m_Size;
};
void showMenu();
void addPerson(struct Addressbook* abs);
void showPerson(struct Addressbook* abs);
void deletePerson(struct Addressbook* abs);