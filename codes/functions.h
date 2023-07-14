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

// 1. 读取数据文件
// 读取文件数据(若有) or 创建(若无)     在"./data.csv"
// 返回值：所有Contact的vecter数组
vector<Contact> readContactsFromCSV();

// 2. 保存数据文件
// 参数1：contact的vector数组
void saveContactsToCSV(const vector<Contact>& contacts);

// 3. 清空
// 3.1 清空输入流中的剩余字符（主要用于防止有人手贱，喜欢骚整，打一串字符）
// 3.2 清空界面
void clearIstream();

 //1. 主菜单界面
void showMenu();

// 2. 显示联系人
void show_contacts(vector<Contact>& contacts);

void sort_with_name(vector<Contact>& contacts);

void showMenu_1(vector<Contact>& contacts);

// 3. 查找联系人菜单
void showMenu_2(const vector<Contact>& Contacts, int T = 0);

// 4. 添加联系人菜单
void showMenu_3();

// 5. 删除联系人菜单
void showMenu_4();

// 6. 修改联系人菜单
void showMenu_5();

// 7. 立即排序
void show_function_sort();
void sort_contact(vector<Contact>& contacts, bool& sign);

void showMenu_6(vector<Contact>& contacts);
// 8. 清空联系人(需要确认 或者 有个密码)菜单
void showMenu_7(vector<Contact>& contacts);

// 9. 退出通讯录菜单		在main.cpp中实现
void showMenu_0(vector<Contact>& contacts);


// 1. 显示所有联系人
void show_contacts(vector<Contact>& contacts);
// 2. 查找联系人函数
void search1(const vector<Contact>& contacts, int T=0);

void search2(const vector<Contact>& contacts, int T = 0);

void search3(const vector<Contact>& contacts, int T = 0);

void search4(const vector<Contact>& contacts, int T = 0);

void search5(const vector<Contact>& contacts, int T = 0);

// 3. 添加联系人函数
void add(vector<Contact>&a);

// 4. 删除联系人函数
void dele(vector<Contact>& a);

// 5. 修改联系人函数
void modify(vector<Contact>& a);

// 6. 立即排序函数
bool cmp1(Contact& a, Contact& b);

void sort_with_name(vector<Contact>& contacts);

bool cmp2(Contact& a, Contact& b);

void sort_with_birthday(vector<Contact>& contacts);

bool cmp3(Contact& a, Contact& b);

void sort_with_tag(vector<Contact>& contacts);

bool cmp4(Contact& a, Contact& b);

void sort_with_phone_number(vector<Contact>& contacts);

void sort_contact(vector<Contact>& contacts, bool& sign);
