#include <bits/stdc++.h>

using namespace std;

class Person;
class AddressBook {
    int size;                      //通讯录目前的长度
    int capacity;                  //通讯录的容量
    Person *data;                  //通讯录的内容
public:
    AddressBook():size(0),capacity(200),data(nullptr){};
};

class Person {
    string name;
    string sex;
    long long phone_number;
    string address;
    string tag;
    string email;
    struct {
        int year;
        int month;
        int day;
    } birthday;
public:
};