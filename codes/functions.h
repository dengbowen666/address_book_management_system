#pragma once // ֻ����һ��
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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
		ofstream file("data.csv");

		file.close();
		cout << "�Ѵ��� ͨѶ¼�����ļ�" << endl;
		//cout << "\n������������� ͨѶ¼����ϵͳ" << endl;
		//cin.ignore();
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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// ����1����������Ϊ���ֵ(�������������ַ�)	����2�����Ե���ֹ�ַ�Ϊ'\n'
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
void showMenu_1() {
	clearIstream();
	cout << "��⵽ ���� 1" << endl;
}
// 3. ������ϵ��
void showMenu_2() {
	clearIstream();
	cout << "��⵽ ���� 2" << endl;
}
// 4. �����ϵ�� 
void showMenu_3() {
	clearIstream();
	cout << "��⵽ ���� 3" << endl;
}
// 5. ɾ����ϵ��
void showMenu_4() {
	clearIstream();
	cout << "��⵽ ���� 4" << endl;
}
// 6. �޸���ϵ��
void showMenu_5() {
	clearIstream();
	cout << "��⵽ ���� 5" << endl;
}
// 7. ��������		����Ҫ���棬��
void showMenu_6() {
	clearIstream();
	cout << "��⵽ ���� 6" << endl;
}
// 8. �����ϵ��(��Ҫȷ�� ���� �и�����)
void showMenu_7() {
	clearIstream();
	cout << "��⵽ ���� 7" << endl;
}
// 9. �˳�ͨѶ¼		��main.cpp��ʵ��
void showMenu_0() {
	clearIstream();
	cout << "��⵽ ���� 0" << endl;
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	return;
}



// ��������������������������������������
// ���������� ������ϵ�˵ĺ��� ����������
// ��������������������������������������

// 1. ��ʾ������ϵ��

// 2. ������ϵ�� 

// 3. �����ϵ�� 

// 4. ɾ����ϵ��

// 5. �޸���ϵ��

// 6. ��������

// 7. �����ϵ��