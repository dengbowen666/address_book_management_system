#pragma once // 只编译一次
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>
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
	}
	else {
		// 创建基础文件与默认数据
		ofstream file("data.csv");
		string str1 = "Phone Number,Name,Tag,Address,Birthdate";
		string str2 = "12345678901,Alice,Friend,123 Main St,2003-01-01";
		file << str1 << endl << str2 << endl;
		file.close();

		Contact contact;
		contact.phoneNumber = "12345678901";
		contact.name = "Alice";
		contact.tag = "Friend";
		contact.address = "123 Main St";
		contact.birthdate = "2003-01-01";
		contacts.push_back(contact);

		cout << "已创建 通讯录数据文件并添加默认数据" << endl;
	}
	cout << "\n准备启动 通讯录管理系统" << endl;
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

// 3. 清空
// 3.1 清空输入流中的剩余字符（主要用于防止有人手贱，喜欢骚整，打一串字符）
// 3.2 清空界面
void clearIstream() {
	// fflush(stdin);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
}

// 4.排序


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
void show_contacts(vector<Contact>& contacts);
void sort_with_name(vector<Contact>& contacts);
void showMenu_1(vector<Contact>& contacts) {
	clearIstream();
	sort_with_name(contacts);
	show_contacts(contacts);
}
// 3. 查找联系人

void search1(const vector<Contact>& contacts) {
	cout << "请输入姓名：";
	string name0;
	int num = 0;
	cin >> name0;
	for (int i = 0; i < contacts.size(); i++)
	{
		int len1 = sizeof(name0);
		int len2 = sizeof(contacts[i].name);
		if (len1 <= len2) {
			size_t found = contacts[i].name.find(name0);
			if (found != std::string::npos) {
				num++;
				cout << contacts[i].phoneNumber << ","
					<< contacts[i].name << ","
					<< contacts[i].tag << ","
					<< contacts[i].address << ","
					<< contacts[i].birthdate << "\n";
			}
		}
	}
	if (num == 0) {
		cout << "无结果！" << endl;
	}
	system("pause");
}
void search2(const vector<Contact>& contacts) {
	cout << "请输入电话：";
	string phoneNumber0;
	int num = 0;
	cin >> phoneNumber0;
	for (int i = 0; i < contacts.size(); i++)
	{
		int len1 = sizeof(phoneNumber0);
		int len2 = sizeof(contacts[i].phoneNumber);
		if (len1 <= len2) {
			size_t found = contacts[i].phoneNumber.find(phoneNumber0);
			if (found != std::string::npos) {
				num++;
				cout << contacts[i].phoneNumber << ","
					<< contacts[i].name << ","
					<< contacts[i].tag << ","
					<< contacts[i].address << ","
					<< contacts[i].birthdate << "\n";
			}
		}
	}
	if (num == 0) {
		cout << "无结果！" << endl;
	}
	system("pause");
}
void search3(const vector<Contact>& contacts) {
	cout << "请输入标签：";
	string tag0;
	int num = 0;
	cin >> tag0;
	for (int i = 0; i < contacts.size(); i++)
	{
		int len1 = sizeof(tag0);
		int len2 = sizeof(contacts[i].tag);
		if (len1 <= len2) {
			size_t found = contacts[i].tag.find(tag0);
			if (found != std::string::npos) {
				num++;
				cout << contacts[i].phoneNumber << ","
					<< contacts[i].name << ","
					<< contacts[i].tag << ","
					<< contacts[i].address << ","
					<< contacts[i].birthdate << "\n";
			}
		}
	}
	if (num == 0) {
		cout << "无结果！" << endl;
	}
	system("pause");
}
void search4(const vector<Contact>& contacts) {
	cout << "请输入地址：";
	string address0;
	int num = 0;
	cin >> address0;
	for (int i = 0; i < contacts.size(); i++)
	{
		int len1 = sizeof(address0);
		int len2 = sizeof(contacts[i].address);
		if (len1 <= len2) {
			size_t found = contacts[i].address.find(address0);
			if (found != std::string::npos) {
				num++;
				cout << contacts[i].phoneNumber << ","
					<< contacts[i].name << ","
					<< contacts[i].tag << ","
					<< contacts[i].address << ","
					<< contacts[i].birthdate << "\n";
			}
		}
	}
	if (num == 0) {
		cout << "无结果！" << endl;
	}
	system("pause");
}
void search5(const vector<Contact>& contacts) {
	cout << "请输入生日：";
	string birthdate0;
	int num = 0;
	cin >> birthdate0;
	for (int i = 0; i < contacts.size(); i++)
	{
		int len1 = sizeof(birthdate0);
		int len2 = sizeof(contacts[i].birthdate);
		if (len1 <= len2) {
			size_t found = contacts[i].birthdate.find(birthdate0);
			if (found != std::string::npos) {
				num++;
				cout << contacts[i].phoneNumber << ","
					<< contacts[i].name << ","
					<< contacts[i].tag << ","
					<< contacts[i].address << ","
					<< contacts[i].birthdate << "\n";
			}
		}
	}
	if (num == 0) {
		cout << "无结果！" << endl;
	}
	system("pause");
}


void showMenu_2(const vector<Contact>& Contacts) {
	clearIstream();
	for (;;) {
		cout << "选择查找方式:" << endl << "1.按姓名查找" << endl << "2.按电话查找" << endl << "3.按标签查找" << endl << "4.按地址查找" << endl << "5.按生日查找" << endl;
		char i;
		string name0;
		cin >> i;
		clearIstream();
		if (i == '1') {
			cout << "按姓名查找" << endl;
			search1(Contacts);
			break;
		}
		else if (i == '2') {
			cout << "按电话查找" << endl;
			search2(Contacts);
			break;
		}
		else if (i == '3') {
			cout << "按标签查找" << endl;
			search3(Contacts);
			break;
		}
		else if (i == '4') {
			cout << "按地址查找" << endl;
			search4(Contacts);
			break;
		}
		else if (i == '5') {
			cout << "按生日查找" << endl;
			search5(Contacts);
			break;
		}
		else if (i == '6') {
			cout << "即将返回上一级" << endl;
			break;
		}
		else {
			cout << "非法字符，请重新输入！" << endl;
			system("pause");
		}
	}
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
// 7. 立即排序		
void show_function_sort()
{
	cout << "*******************************" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****   请选择排序方式    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*******************************" << endl;
	cout << "*****    1、按姓名排序    *****" << endl;
	cout << "*****    2、按生日排序    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    3、按小标签排序  *****" << endl;
	cout << "*****  4、按电话号码排序  *****" << endl;
	cout << "*******************************" << endl;
	cout << "*****    5、退出排序    *****" << endl;
	cout << "*******************************" << endl;
}
void sort_contact(vector<Contact>& contacts, bool& sign);
void showMenu_6(vector<Contact>& contacts) {
	bool sign = false;
	while (true)
	{
		clearIstream();
		show_function_sort();
		sort_contact(contacts, sign);
		if (sign) break;
	}
}
// 8. 清空联系人(需要确认 或者 有个密码)
void showMenu_7(vector<Contact>& contacts) {
	ofstream file("data.csv");
	if (!file.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}
	contacts.clear();
	file.open("data.csv", ios::out);
	cout << "清空成功" << endl;
	system("pause");
	clearIstream();
	cout << "检测到 输入 7" << endl;
}
// 9. 退出通讯录		在main.cpp中实现
void showMenu_0(vector<Contact>& contacts) {
	clearIstream();
	cout << "欢迎下次使用" << endl;
	sort_with_name(contacts);
	system("pause");
	//return;
}



// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
// ↓↓↓↓↓ 操作联系人的函数 ↓↓↓↓↓
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

// 1. 显示所有联系人
void show_contacts(vector<Contact>& contacts)
{
	cout << "------------------------------------------------------------------------" << endl;
	cout << "|    电话    |    姓名    |    标签    |        地址        |    生日    |" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	for (auto& contact : contacts)
	{
		cout << setw(12) << contact.phoneNumber << setw(12) << contact.name << setw(12) << contact.tag << setw(20) << contact.address << setw(16) << contact.birthdate << endl;
	}
	system("pause");
}
// 2. 查找联系人 

// 3. 添加联系人 

// 4. 删除联系人

// 5. 修改联系人

// 6. 立即排序
bool cmp1(Contact& a, Contact& b)
{
	return a.name < b.name;
}

void sort_with_name(vector<Contact>& contacts)
{
	sort(contacts.begin(), contacts.end(), cmp1);
}

bool cmp2(Contact& a, Contact& b)
{
	return a.birthdate < b.birthdate;
}

void sort_with_birthday(vector<Contact>& contacts)
{
	sort(contacts.begin(), contacts.end(), cmp2);
}

bool cmp3(Contact& a, Contact& b)
{
	return a.tag < b.tag;
}

void sort_with_tag(vector<Contact>& contacts)
{
	sort(contacts.begin(), contacts.end(), cmp3);
}

bool cmp4(Contact& a, Contact& b)
{
	return a.phoneNumber < b.phoneNumber;
}

void sort_with_phone_number(vector<Contact>& contacts)
{
	sort(contacts.begin(), contacts.end(), cmp4);
}

void sort_contact(vector<Contact>& contacts, bool& sign)
{
	char select;
	cin >> select;
	system("cls");
	switch (select)
	{
	case '1':
		sort_with_name(contacts);
		break;
	case '2':
		sort_with_birthday(contacts);
		saveContactsToCSV(contacts);
		break;
	case '3':
		sort_with_tag(contacts);
		break;
	case '4':
		sort_with_phone_number(contacts);
		break;
	case '5':
		sign = true;
		return;
	default:
		break;
	}
	show_contacts(contacts);
}

void modify(vector<Contact>& a) {
	cout << "***********************************************" << endl;
	cout << "*              请选择修改方式:"<<setw(17) <<"*" << endl;
	cout << "*               1.按电话查找"<< setw(19) << "*" << endl;
	cout << "*               2.按姓名查找"<< setw(20)<<" * "<< endl;
	cout << "***********************************************" << endl;
	char m;
	int n, j;
	cin >> m;
	switch (m) {
	case '1': {
		cout << "请输入号码：" << endl;
		string number;
		cin >> number;
		auto it = a.begin();
		while (it != a.end()) {
			if (number == it->phoneNumber) {
				cout << "请确定你要修改的内容：\n1-name\n2-address\n3-phoneNumber\n4-tag\n5-birthdate " << endl;

				cin >> n;
				switch (n) {
				case 1: {
					cout << "请输入你要修改的内容：" << endl;
					cin >> it->name;
					break;
				}
				case 2: {
					cout << "请输入你要修改的内容：" << endl;
					cin >> it->address;
					break;
				}
				case 3: {
					cout << "请输入你要修改的内容：" << endl;
					cin >> it->phoneNumber;
					break;
				}
				case 4: {
					cout << "请输入你要修改的内容：" << endl;
					cin >> it->tag;
					break;
				}
				case 5: {
					cout << "请输入你要修改的内容：" << endl;

					cin >> it->birthdate;
					break;
				}

				}



			}
			it++;

		}
		if (it == a.end())
		{
			cout << "修改失败" << endl;
			system("pause");
			return;
		}
		break;
	}
	case '2':

	{
		cout << "请输入姓名：" << endl;

		string na;
		cin >> na;

		auto it2 = a.begin();
		while (it2 != a.end()) {
			if (na == it2->name) {
				cout << "请确定你要修改的内容：1-name\n2-address\n3-phoneNumber\n4-tag\n5-birthdate " << endl;

				cin >> j;
				switch (j) {
				case 1: {
					cout << "请输入你要修改的内容：" << endl;
					cin >> it2->name;
					break;
				}
				case 2: {
					cout << "请输入你要修改的内容：" << endl;
					cin >> it2->address;
					break;
				}
				case 3: {
					cout << "请输入你要修改的内容：" << endl;
					cin >> it2->phoneNumber;
					break;
				}
				case 4: {
					cout << "请输入你要修改的内容：" << endl;
					cin >> it2->tag;
					break;
				}
				case 5: {
					cout << "请输入你要修改的内容：" << endl;

					cin >> it2->birthdate;
					break;
				}

				}



			}
			it2++;

		}
		if (it2 == a.end())
		{
			cout << "修改失败" << endl;
			system("pause");
			return;
		}
		break;
	}


	}


	cout << "修改成功" << endl;
	saveContactsToCSV(a);
	system("pause");
	system("cls");
}

void add(vector<Contact>& a) {
	Contact person;
	cout << "请输入姓名： " << endl;
	cin >> person.name;
	cout << "请输入地址：" << endl;
	cin >> person.address;
	cout << "请输入号码： " << endl;
	cin >> person.phoneNumber;
	cout << "请输入标签： " << endl;
	cin >> person.tag;
	cout << "请输入生日：" << endl;
	cin >> person.birthdate;
	a.push_back(person);
	saveContactsToCSV(a);
	cout << "添加成功" << endl;
	system("pause");
	system("cls");






}

void dele(vector<Contact>& a) {
	cout << "请输入你要删除的联系人电话： " << endl;
	string number;
	cin >> number;
	auto it = a.begin();
	while (it != a.end()) {
		if (number == it->phoneNumber) {
			a.erase(it);
			cout << "删除成功" << endl;
			break;

		}
		it++;
	}
	if (it == a.end())
	{
		cout << "删除失败" << endl;
		system("pause");
		return;
	}
	saveContactsToCSV(a);
	system("pause");
	system("cls");
}

