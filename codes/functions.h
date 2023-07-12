#pragma once // 只编译一次
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 结构体，存各个数据
struct Contact {
	string phoneNumber;
	string name;
	string tag;
	string address;
	string birthdate;
};


// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
// ↓↓↓↓↓     基础函数     ↓↓↓↓↓
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


// 1. 读取数据文件
// 读取文件数据(若有) or 创建(若无)     在"./data.csv"
// 返回值：所有Contact的vecter数组
vector<Contact> readContactsFromCSV() {
	vector<Contact> contacts;
	ifstream file("data.csv");

	if (file.is_open()) {
		string line;
		getline(file, line); // 跳过标题行，反正都是固定的
		// 在contacts中分别储存各个contact
		while (getline(file, line)) {
			Contact contact;
			istringstream iss(line);
			string field;

			getline(iss, field, ',');
			contact.phoneNumber = field;

			getline(iss, field, ',');
			contact.name = field;

			getline(iss, field, ',');
			contact.tag = field;

			getline(iss, field, ',');
			contact.address = field;

			getline(iss, field, ',');
			contact.birthdate = field;

			contacts.push_back(contact);
		}

		file.close();

		cout << "成功读取 通讯录数据" << endl;
		//cout << "\n按任意键启动 通讯录管理系统" << endl;
		//cin.ignore(); // 忽略用户输入的字符
	}
	else {
		cout << "无法打开 通讯录数据文件" << endl;
		ofstream file("data.csv");

		file.close();
		cout << "已创建 通讯录数据文件" << endl;
		//cout << "\n按任意键以启动 通讯录管理系统" << endl;
		//cin.ignore();
	}
	system("cls");
	return contacts;
}
// 2. 保存数据文件
// 参数1：contact的vector数组
void saveContactsToCSV(const vector<Contact>& contacts) {
	ofstream file("data.csv");
	if (file.is_open()) {
		file << "Phone Number,Name,Tag,Address,Birthdate\n";

		for (const auto& contact : contacts) {
			file << contact.phoneNumber << ","
				<< contact.name << ","
				<< contact.tag << ","
				<< contact.address << ","
				<< contact.birthdate << "\n";
		}

		file.close();

		std::cout << "通讯录保存成功" << std::endl;
	}
	else {
		std::cout << "无法打开文件" << std::endl;
	}
}
// 3. 排序


// 3. 清空
// 3.1 清空输入流中的剩余字符（主要用于防止有人手贱，喜欢骚整，打一串字符）
// 3.2 清空界面
void clearIstream() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// 参数1：忽略限制为最大值(即，忽略所有字符)	参数2：忽略的终止字符为'\n'
	system("cls");
}



// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
// ↓↓↓↓↓     界面函数     ↓↓↓↓↓
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
// 
// 1. 主菜单界面
void showMenu() {
	clearIstream();
	cout << "*******************************" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    欢迎使用通讯录   *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*******************************" << endl;
	cout << "*****    1、显示联系人    *****" << endl;
	cout << "*****    2、查找联系人    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    3、添加联系人    *****" << endl;
	cout << "*****    4、删除联系人    *****" << endl;
	cout << "*****    5、修改联系人    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    6、立即排序      *****" << endl;
	cout << "*****    7、清空联系人    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    0、退出通讯录    *****" << endl;
	cout << "*******************************" << endl;
}

// 2. 显示联系人
void showMenu_1() {
	clearIstream();
	cout << "检测到 输入 1" << endl;
}
// 3. 查找联系人
void showMenu_2() {
	clearIstream();
	cout << "检测到 输入 2" << endl;
}
// 4. 添加联系人 
void showMenu_3() {
	clearIstream();
	cout << "检测到 输入 3" << endl;
}
// 5. 删除联系人
void showMenu_4() {
	clearIstream();
	cout << "检测到 输入 4" << endl;
}
// 6. 修改联系人
void showMenu_5() {
	clearIstream();
	cout << "检测到 输入 5" << endl;
}
// 7. 立即排序		不需要界面，吧
void showMenu_6() {
	clearIstream();
	cout << "检测到 输入 6" << endl;
}
// 8. 清空联系人(需要确认 或者 有个密码)
void showMenu_7() {
	clearIstream();
	cout << "检测到 输入 7" << endl;
}
// 9. 退出通讯录		在main.cpp中实现
void showMenu_0() {
	clearIstream();
	cout << "检测到 输入 0" << endl;
	cout << "欢迎下次使用" << endl;
	system("pause");
	return;
}



// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
// ↓↓↓↓↓ 操作联系人的函数 ↓↓↓↓↓
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

// 1. 显示所有联系人

// 2. 查找联系人 

// 3. 添加联系人 

// 4. 删除联系人

// 5. 修改联系人

// 6. 立即排序

// 7. 清空联系人