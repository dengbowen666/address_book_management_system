#include "functions.h"

int main() {
	// ��ȡ����
	vector<Contact> Contacts = readContactsFromCSV();
	clearIstream();
	// ���� 
	for (;;) {
		
		showMenu();
		char select;
		cin >> select;
		if (select == '1') {
			showMenu_1();
		}
		else if (select == '2') {
			showMenu_2();
		}
		else if (select == '3') {
			showMenu_3();
		}
		else if (select == '4') {
			showMenu_4();
		}
		else if (select == '5') {
			showMenu_5();
		}
		else if (select == '6') {
			showMenu_6();
		}
		else if (select == '7') {
			showMenu_7();
		}
		else if (select == '0') {
			showMenu_0();
		}
		else {
			clearIstream();
			cout << "��⵽�Ƿ�������\n�밴���⽨����..." << endl;
			clearIstream();
		}
	}


	return 0;
}