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
    } else {
        cout << "无法打开 通讯录数据文件" << endl;
        ofstream file1("data.csv");
        file1.close();
        cout << "已创建 通讯录数据文件" << endl;
    }
    cout << "\n准备启动 通讯录管理系统" << endl;
    return contacts;
}

// 2. 保存数据文件
// 参数1：contact的vector数组
void saveContactsToCSV(const vector<Contact> &contacts) {
    ofstream file("data.csv");
    if (file.is_open()) {
        file << "Phone Number,Name,Tag,Address,Birthdate\n";

        for (const auto &contact: contacts) {
            file << contact.phoneNumber << ","
                 << contact.name << ","
                 << contact.tag << ","
                 << contact.address << ","
                 << contact.birthdate << "\n";
        }

        file.close();

        std::cout << "通讯录保存成功" << std::endl;
    } else {
        std::cout << "无法打开文件" << std::endl;
    }
}

// 3. 清空
// 3.1 清空输入流中的剩余字符（主要用于防止有人手贱，喜欢骚整，打一串字符）
// 3.2 清空界面
void clearIstream() {
    fflush(stdin);
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
void show_contacts(vector<Contact> &contacts);

void sort_with_name(vector<Contact> &contacts);

void showMenu_1(vector<Contact> &contacts) {
    clearIstream();
    sort_with_name(contacts);
    show_contacts(contacts);
}

// 3. 查找联系人
void search2(const vector<Contact> &contacts);

void search1(const vector<Contact> &contacts) {
    string name0;
    int num = 0;
    //clearIstream();
    cout << "请输入姓名：";
    cin >> name0;
    vector<Contact> con;
    for (const auto &contact: contacts) {
        int len1 = (int) name0.size();
        int len2 = (int) contact.name.size();
        if (len1 <= len2) {
            size_t found = contact.name.find(name0);
            if (found != std::string::npos) {
                num++;
                cout << "phoneNumber:" << contact.phoneNumber << ","
                     << " name:" << contact.name << ","
                     << " tag:" << contact.tag << ","
                     << " address:" << contact.address << ","
                     << " birthdate:" << contact.birthdate << "\n";
                con.push_back(contact);
            }
        }
    }
    if (num == 0) {
        cout << "无结果！" << endl << "1:回到主界面" << endl << "其他:回到上一步" << endl;
        char truth;
        cin >> truth;
        if (truth != '1') {
            con = contacts;
            cout << "已回到上一步" << endl;
            search1(con);
        }
    } else {
        l1:
        cout << "1、继续" << endl << "2、返回主界面" << endl;
        char m;
        cin >> m;
        for (;;) {
            if (m == '1') {
                search2(con);
            } else if (m == '2') {
                //system("pause");
                break;
            } else {
                cout << "非法字符,请重输" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("pause");
                system("cls");
                goto l1;
            }
            break;
        }
    }

}

void search2(const vector<Contact> &contacts) {
    cout << "请输入电话：";
    string phoneNumber0;
    int num = 0;
    cin >> phoneNumber0;
    vector<Contact> con;
    for (const auto &contact: contacts) {
        int len1 = (int) phoneNumber0.size();
        int len2 = (int) contact.phoneNumber.size();
        if (len1 <= len2) {
            size_t found = contact.phoneNumber.find(phoneNumber0);
            if (found != std::string::npos) {
                num++;
                cout << "phoneNumber:" << contact.phoneNumber << ","
                     << " name:" << contact.name << ","
                     << " tag:" << contact.tag << ","
                     << " address:" << contact.address << ","
                     << " birthdate:" << contact.birthdate << "\n";
                con.push_back(contact);
            }
        }
    }
    if (num == 0) {
        cout << "无结果！" << endl << "1:回到主界面" << endl << "其他:回到上一步" << endl;
        char truth;
        cin >> truth;

        if (truth != 1) {
            con = contacts;
            cout << "已回到上一步" << endl;
            search2(con);
        }
    } else {
        l2:
        cout << "1、继续" << endl << "2、返回主界面" << endl;
        char m;
        cin >> m;
        for (;;) {
            if (m == '1') {
                search2(con);
            } else if (m == '2') {
                //system("pause");
                break;
            } else {
                cout << "非法字符,请重输" << endl;
                system("pause");
                goto l2;
            }
            break;
        }
    }
}

void search3(const vector<Contact> &contacts) {
    cout << "请输入标签：";
    string tag0;
    int num = 0;
    cin >> tag0;
    vector<Contact> con;
    for (const auto &contact: contacts) {
        int len1 = (int) tag0.size();
        int len2 = (int) contact.tag.size();
        if (len1 <= len2) {
            size_t found = contact.tag.find(tag0);
            if (found != std::string::npos) {
                num++;
                cout << "phoneNumber:" << contact.phoneNumber << ","
                     << " name:" << contact.name << ","
                     << " tag:" << contact.tag << ","
                     << " address:" << contact.address << ","
                     << " birthdate:" << contact.birthdate << "\n";
                con.push_back(contact);
            }
        }
    }
    if (num == 0) {
        cout << "无结果！" << endl << "1:回到主界面" << endl << "其他:回到上一步" << endl;
        char truth;
        cin >> truth;

        if (truth != 1) {
            con = contacts;
            cout << "已回到上一步" << endl;
            search3(con);
        }
    } else {
        l3:
        cout << "1、继续" << endl << "2、返回主界面" << endl;
        char m;
        cin >> m;
        for (;;) {
            if (m == '1') {
                search2(con);
            } else if (m == '2') {
                break;
            } else {
                cout << "非法字符,请重输" << endl;
                system("pause");
                goto l3;
            }
            break;
        }
    }
}

void search4(const vector<Contact> &contacts) {
    cout << "请输入地址：";
    string address0;
    int num = 0;
    cin >> address0;
    vector<Contact> con;
    for (const auto &contact: contacts) {
        int len1 = (int) address0.size();
        int len2 = (int) contact.address.size();
        if (len1 <= len2) {
            size_t found = contact.address.find(address0);
            if (found != std::string::npos) {
                num++;
                cout << "phoneNumber:" << contact.phoneNumber << ","
                     << " name:" << contact.name << ","
                     << " tag:" << contact.tag << ","
                     << " address:" << contact.address << ","
                     << " birthdate:" << contact.birthdate << "\n";
                con.push_back(contact);
            }
        }
    }
    if (num == 0) {
        cout << "无结果！" << endl << "1:回到主界面" << endl << "其他:回到上一步" << endl;
        char truth;
        cin >> truth;

        if (truth != 1) {
            con = contacts;
            cout << "已回到上一步" << endl;
            search4(con);
        }
    } else {
        l4:
        cout << "1、继续" << endl << "2、返回主界面" << endl;
        char m;
        cin >> m;
        for (;;) {
            if (m == '1') {
                search2(con);
            } else if (m == '2') {
                break;
            } else {
                cout << "非法字符,请重输" << endl;
                system("pause");
                goto l4;
            }
            break;
        }
    }
}

void search5(const vector<Contact> &contacts) {
    cout << "请输入生日：";
    string birthdate0;
    int num = 0;
    cin >> birthdate0;
    vector<Contact> con;
    for (const auto &contact: contacts) {
        int len1 = (int) birthdate0.size();
        int len2 = (int) contact.birthdate.size();
        if (len1 <= len2) {
            size_t found = contact.birthdate.find(birthdate0);
            if (found != std::string::npos) {
                num++;
                cout << "phoneNumber:" << contact.phoneNumber << ","
                     << " name:" << contact.name << ","
                     << " tag:" << contact.tag << ","
                     << " address:" << contact.address << ","
                     << " birthdate:" << contact.birthdate << "\n";
                con.push_back(contact);
            }
        }
    }
    if (num == 0) {
        cout << "无结果！" << endl << "1:回到主界面" << endl << "其他:回到上一步" << endl;
        char truth;
        cin >> truth;

        if (truth != 1) {
            con = contacts;
            cout << "已回到上一步" << endl;
            search5(con);
        }
    } else {
        l5:
        cout << "1、继续" << endl << "2、返回主界面" << endl;
        char m;
        cin >> m;
        for (;;) {
            if (m == '1') {
                search2(con);
            } else if (m == '2') {
                break;
            } else {
                cout << "非法字符,请重输" << endl;
                system("pause");
                goto l5;
            }
            break;
        }
    }
}


void showMenu_2(const vector<Contact> &Contacts) {
    clearIstream();
    for (;;) {
        cout << "选择查找方式:" << endl << "1.按姓名查找" << endl << "2.按电话查找" << endl << "3.按标签查找" << endl <<
             "4.按地址查找" << endl << "5.按生日查找" << endl;
        char i;
        string name0;
        cin >> i;
        clearIstream();
        if (i == '1') {
            cout << "按姓名查找" << endl;
            search1(Contacts);
            break;
        } else if (i == '2') {
            cout << "按电话查找" << endl;
            search2(Contacts);
            break;
        } else if (i == '3') {
            cout << "按标签查找" << endl;
            search3(Contacts);
            break;
        } else if (i == '4') {
            cout << "按地址查找" << endl;
            search4(Contacts);
            break;
        } else if (i == '5') {
            cout << "按生日查找" << endl;
            search5(Contacts);
            break;
        } else {
            cout << "非法字符，请重新输入！" << endl;
            break;
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
void show_function_sort() {
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

void sort_contact(vector<Contact> &contacts, bool &sign);

void showMenu_6(vector<Contact> &contacts) {
    bool sign = false;
    while (true) {
        clearIstream();
        show_function_sort();
        sort_contact(contacts, sign);
        if (sign)
            break;
    }
}

// 8. 清空联系人(需要确认 或者 有个密码)
void showMenu_7(vector<Contact> &contacts) {
    ofstream file("data.csv");
    if (!file.is_open()) {
        cout << "文件不存在" << endl;
        return;
    }
    cout << "是否确定清空？（y/n）" << endl;
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        contacts.clear();
        file.open("data.csv", ios::out);
        cout << "清空成功" << endl;
        system("pause");
        clearIstream();
    } else
        cout << "清除失败！" << endl;
    system("pause");
}

// 9. 退出通讯录		在main.cpp中实现
void showMenu_0(vector<Contact> &contacts) {
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
void show_contacts(vector<Contact> &contacts) {
    cout << "------------------------------------------------------------------------" << endl;
    cout << "|    电话    |    姓名    |    标签    |        地址        |    生日    |" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (auto &contact: contacts) {
        cout << setw(12) << contact.phoneNumber << setw(12) << contact.name << setw(12) << contact.tag << setw(
                20) << contact.address << setw(16) << contact.birthdate << endl;
    }
    system("pause");
}
// 2. 查找联系人

// 3. 添加联系人

// 4. 删除联系人

// 5. 修改联系人

// 6. 立即排序
bool cmp1(Contact &a, Contact &b) {
    return a.name < b.name;
}

void sort_with_name(vector<Contact> &contacts) {
    sort(contacts.begin(), contacts.end(), cmp1);
}

bool cmp2(Contact &a, Contact &b) {
    return a.birthdate < b.birthdate;
}

void sort_with_birthday(vector<Contact> &contacts) {
    sort(contacts.begin(), contacts.end(), cmp2);
}

bool cmp3(Contact &a, Contact &b) {
    return a.tag < b.tag;
}

void sort_with_tag(vector<Contact> &contacts) {
    sort(contacts.begin(), contacts.end(), cmp3);
}

bool cmp4(Contact &a, Contact &b) {
    return a.phoneNumber < b.phoneNumber;
}

void sort_with_phone_number(vector<Contact> &contacts) {
    sort(contacts.begin(), contacts.end(), cmp4);
}

void sort_contact(vector<Contact> &contacts, bool &sign) {
    char select;
    cin >> select;
    system("cls");
    switch (select) {
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

void modify(vector<Contact> &a) {
    cout << "***********************************************" << endl;
    cout << "*              请选择修改方式:" << setw(17) << "*" << endl;
    cout << "*               1.按电话查找" << setw(19) << "*" << endl;
    cout << "*               2.按姓名查找" << setw(20) << " * " << endl;
    cout << "***********************************************" << endl;
    char m;
    int n, j;
    cin >> m;
    if (m != '1' && m != '2') {
        cout << "查找错误！返回系统" << endl;
        system("pause");
        system("cls");
    } else
        switch (m) {
            case '1': {
                cout << "请输入号码：" << endl;
                string number;
                cin >> number;
                auto it = a.begin();
                while (it != a.end()) {
                    if (number == it->phoneNumber) {
                        cout << "请确定你要修改的内容:\n1-name\n2-address\n3-phoneNumber\n4-tag\n5-birthdate " << endl;

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
                            default: {
                                break;
                            }
                        }
                        break;
                    }
                    it++;

                }
                if (it == a.end()) {
                    cout << "修改失败" << endl;
                    system("pause");
                    return;
                }
                break;
            }
            case '2': {
                cout << "请输入姓名：" << endl;

                string na;
                cin >> na;

                auto it2 = a.begin();
                while (it2 != a.end()) {
                    if (na == it2->name) {
                        cout << "请确定你要修改的内容：\n1-name\n2-address\n3-phoneNumber\n4-tag\n5-birthdate " << endl;

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
                            default: {
                                break;
                            }
                        }
                        break;
                    }
                    it2++;
                    if (it2 == a.end()) {
                        cout << "修改失败" << endl;
                        system("pause");
                        return;
                    }

                }
                break;
            }
            default: {
                break;
            }

        }

    cout << "修改成功" << endl;
    saveContactsToCSV(a);
    system("pause");
    system("cls");
}

bool contains(vector<Contact> &a, string &phone) {
    for (auto &it: a) {
        if (it.phoneNumber == phone)
            return true;
    }
    return false;
}

void add(vector<Contact> &a) {
    Contact person;
    cout << "请输入号码： " << endl;
    string phone;
    cin >> phone;
    if (contains(a, phone)) {
        cout << "用户已经存在,";
        cout << "添加失败!" << endl;
        system("pause");
        return;
    }
    person.phoneNumber = phone;
    cout << "请输入姓名： " << endl;
    cin >> person.name;
    cout << "请输入地址：" << endl;
    cin >> person.address;
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

void dele(vector<Contact> &a) {
    cout << "***********************************************" << endl;
    cout << "*              请选择修改方式:" << setw(17) << "*" << endl;
    cout << "*               1.按电话查找" << setw(19) << "*" << endl;
    cout << "*               2.按姓名查找" << setw(20) << " * " << endl;
    cout << "***********************************************" << endl;
    char m;
    cin >> m;
    if (m != '1' && m != '2') {
        cout << "查找错误！返回系统" << endl;
        system("pause");
        system("cls");
    } else
        switch (m) {
            case '1': {
                cout << "请输入你要删除的联系人电话： " << endl;
                string number;
                cin >> number;
                auto it = a.begin();
                while (it != a.end()) {
                    if (number == it->phoneNumber) {
                        a.erase(it);
                        cout << "删除成功" << endl;
                        system("pause");
                        return;
                    }
                    it++;
                }
                if (it == a.end()) {
                    cout << "删除失败" << endl;
                    system("pause");
                    return;
                }
                saveContactsToCSV(a);
                system("pause");
                system("cls");
                break;
            }
            case '2': {
                cout << "请输入你要删除的联系人姓名： " << endl;
                string name;
                cin >> name;
                int count = 0;
                vector<int> a2;
                for (int i = 0; i < a.size(); i++) {
                    if (a[i].name == name) {
                        count++;
                        a2.push_back(i);
                    }
                }
                if (count == 0) {
                    cout << "联系人不存在，删除失败！" << endl;
                    system("pause");
                    return;
                } else if (count == 1) {
                    a.erase(a.begin() + a2[0]);
                    cout << "删除成功！" << endl;
                    saveContactsToCSV(a);
                    system("pause");
                    return;
                } else {
                    for (int &it2: a2) {
                        cout << a[it2].phoneNumber << "," << a[it2].name << "," << a[it2].address << "," << a[it2].tag
                             << "," << a[it2].birthdate << endl;
                    }
                    cout << "请选择需要删除的联系人的号码：" << endl;
                    string phone;
                    cin >> phone;
                    for (int &it2: a2) {
                        if (a[it2].phoneNumber == phone) {
                            a.erase(a.begin() + it2);
                            cout << "删除成功！" << endl;
                            saveContactsToCSV(a);
                            system("pause");
                            return;
                        }
                    }
                }

                saveContactsToCSV(a);
                system("pause");
                system("cls");
                break;
            }
            default: {
                break;
            }
        }
}
