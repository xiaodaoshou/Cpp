#include<iostream>
#include<stdio.h>
using namespace std;
class Base {
public:Base(){
		cout << "Base�Ĺ��캯��" << endl;
	}
	~Base() {
		cout << "Base����������" << endl;
	}
};
class Son:public Base {
public: Son() {
		cout << "Son�Ĺ��캯��" << endl;
	}
	~Son() {
		cout << "Son����������" << endl;
	}
};
void test() {
	Son s;
}
int main() {
	test();
	return 0;
}