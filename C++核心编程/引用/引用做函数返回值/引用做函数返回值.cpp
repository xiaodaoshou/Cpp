#include<iostream>
using namespace std;
int& test1() {
	int a = 10;
	return a;
}
int& test2() {
	static int b = 20;
	return b;
}
int main() {
	int& c = test1();
	int& d = test2();
	cout << "test1()的返回值" <<c<< endl;
	cout << "test1()的返回值" << c << endl;
	cout << "test2()的返回值" <<d << endl;
	cout << "test2()的返回值" << d << endl;
	cout << "函数调用做左值" << endl;
	test2() = 30;
	cout << "test2()的返回值" << d << endl;
	cout << "test2()的返回值" << d << endl;
	return 0;
}