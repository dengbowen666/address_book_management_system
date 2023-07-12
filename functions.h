#pragma once // ֻ����һ��
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>
using namespace std;

// �ṹ�壬���������
struct Contact {
	string phoneNumber;
	string name;
	string tag;
	string address;
	string birthdate;
};


// ��������������������������������������
// ����������     ��������     ����������
// ��������������������������������������


// 1. ��ȡ�����ļ�
// ��ȡ�ļ�����(����) or ����(����)     ��"./data.csv"
// ����ֵ������Contact��vecter����
vector<Contact> readContactsFromCSV() {
    vector<Contact> contacts;
	ifstream file("data.csv");
	if (file.is_open()) {
		string line;
		getline(file, line); // ���������У��������ǹ̶���
		// ��contacts�зֱ𴢴����contact
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

		cout << "�ɹ���ȡ ͨѶ¼����" << endl;
		//cout << "\n����������� ͨѶ¼����ϵͳ" << endl;
		//cin.ignore(); // �����û�������ַ�
	}
	else {
		cout << "�޷��� ͨѶ¼�����ļ�" << endl;
		ofstream file1("data.csv");

		file.close();
		cout << "�Ѵ��� ͨѶ¼�����ļ�" << endl;
		cout << "\n������������� ͨѶ¼����ϵͳ" << endl;
		cin.ignore();
	}
	system("cls");
	return contacts;
}
// 2. ���������ļ�
// ����1��contact��vector����
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

		std::cout << "ͨѶ¼����ɹ�" << std::endl;
	}
	else {
		std::cout << "�޷����ļ�" << std::endl;
	}
}
// 3. ����


// 3. ���
// 3.1 ����������е�ʣ���ַ�����Ҫ���ڷ�ֹ�����ּ���ϲ��ɧ������һ���ַ���
// 3.2 ��ս���
void clearIstream() {
    fflush(stdin);	// ����1����������Ϊ���ֵ(�������������ַ�)	����2�����Ե���ֹ�ַ�Ϊ'\n'
	system("cls");
}



// ��������������������������������������
// ����������     ���溯��     ����������
// ��������������������������������������
// 
// 1. ���˵�����
void showMenu() {
	clearIstream();
	cout << "*******************************" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    ��ӭʹ��ͨѶ¼   *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*******************************" << endl;
	cout << "*****    1����ʾ��ϵ��    *****" << endl;
	cout << "*****    2��������ϵ��    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    3�������ϵ��    *****" << endl;
	cout << "*****    4��ɾ����ϵ��    *****" << endl;
	cout << "*****    5���޸���ϵ��    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    6����������      *****" << endl;
	cout << "*****    7�������ϵ��    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    0���˳�ͨѶ¼    *****" << endl;
	cout << "*******************************" << endl;
}

// 2. ��ʾ��ϵ��
void show_contacts(vector<Contact>& contacts);
void showMenu_1(vector<Contact>& contacts) {
	clearIstream();
//	cout << "��⵽ ���� 1" << endl;
    show_contacts(contacts);
}
// 3. ������ϵ��
void showMenu_2() {
	clearIstream();
//	cout << "��⵽ ���� 2" << endl;
}
// 4. �����ϵ�� 
void showMenu_3() {
	clearIstream();
//	cout << "��⵽ ���� 3" << endl;
}
// 5. ɾ����ϵ��
void showMenu_4() {
	clearIstream();
//	cout << "��⵽ ���� 4" << endl;
}
// 6. �޸���ϵ��
void showMenu_5() {
	clearIstream();
//	cout << "��⵽ ���� 5" << endl;
}





// 7. ��������		����Ҫ���棬��
void show_function_sort()
{
    cout << "*******************************" << endl;
    cout << "*****                     *****" << endl;
    cout << "*****   ��ѡ������ʽ    *****" << endl;
    cout << "*****                     *****" << endl;
    cout << "*******************************" << endl;
    cout << "*****    1������������    *****" << endl;
    cout << "*****    2������������    *****" << endl;
    cout << "*****                     *****" << endl;
    cout << "*****    3����С��ǩ����  *****" << endl;
    cout << "*****  4�����绰��������  *****" << endl;
    cout << "*******************************" << endl;
    cout << "*****    5���˳�����    *****" << endl;
    cout << "*******************************" << endl;
}
void sort_contact(vector<Contact>& contacts,bool & sign);
void showMenu_6(vector<Contact>& contacts) {
    bool sign = false;
    while (true)
    {
        clearIstream();
        show_function_sort();
        sort_contact(contacts,sign);
        if (sign) break;
    }

}

// 8. �����ϵ��(��Ҫȷ�� ���� �и�����)
void showMenu_7() {
	clearIstream();
//	cout << "��⵽ ���� 7" << endl;
}
// 9. �˳�ͨѶ¼		��main.cpp��ʵ��
void showMenu_0() {
	clearIstream();
//	cout << "��⵽ ���� 0" << endl;
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
//	return;
}



// ��������������������������������������
// ���������� ������ϵ�˵ĺ��� ����������
// ��������������������������������������

// 1. ��ʾ������ϵ��
void show_contacts(vector<Contact>& contacts)
{
    cout << "------------------------------------------------------------------------" << endl;
    cout << "|    �绰    |    ����    |    ��ǩ    |        ��ַ        |    ����    |" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (auto & contact : contacts)
    {
        cout << setw(12) << contact.phoneNumber << setw(12) << contact.name << setw(12) << contact.tag << setw(20) << contact.address<< setw(16) << contact.birthdate << endl;
    }
    system("pause");
}
// 2. ������ϵ�� 

// 3. �����ϵ�� 

// 4. ɾ����ϵ��

// 5. �޸���ϵ��

// 6. ��������
bool cmp1(Contact& a,Contact& b)
{
    return a.name < b.name;
}

void sort_with_name(vector<Contact>& contacts)
{
    sort(contacts.begin(),contacts.end(),cmp1);
}

bool cmp2(Contact& a,Contact& b)
{
    return a.birthdate < b.birthdate;
}

void sort_with_birthday(vector<Contact>& contacts)
{
    sort(contacts.begin(),contacts.end(),cmp2);
}

bool cmp3(Contact& a,Contact& b)
{
    return a.tag < b.tag;
}

void sort_with_tag(vector<Contact>& contacts)
{
    sort(contacts.begin(),contacts.end(),cmp3);
}

bool cmp4(Contact& a,Contact& b)
{
    return a.phoneNumber < b.phoneNumber;
}

void sort_with_phone_number(vector<Contact>& contacts)
{
    sort(contacts.begin(),contacts.end(),cmp4);
}

void sort_contact(vector<Contact>& contacts,bool & sign)
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
// 7. �����ϵ��