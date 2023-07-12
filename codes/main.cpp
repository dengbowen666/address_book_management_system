#include "functions.h"

int main() {
	// 读取数据
	vector<Contact> Contacts = readContactsFromCSV();
	// 启动 
	for (;;) {
		showMenu();
		char select;
		cin >> select;
		if (select == '1') {
			showMenu_1(Contacts);
		}
		else if (select == '2') {
			showMenu_2(Contacts);
		}
		else if (select == '3') {
			showMenu_3();
			add(Contacts);
		}
		else if (select == '4') {
			showMenu_4();
			dele(Contacts);
		}
		else if (select == '5') {
			showMenu_5();
			modify(Contacts);
		}
		else if (select == '6') {
			showMenu_6(Contacts);
		}
		else if (select == '7') {
			showMenu_7(Contacts);
		}
		else if (select == '0') {
			showMenu_0(Contacts);
			break;
		}
		else {
			clearIstream();
			cout << "检测到非法操作符" << endl;
		}
	}

	return 0;
}
