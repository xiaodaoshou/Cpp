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
	cout << "test1()�ķ���ֵ" <<c<< endl;
	cout << "test1()�ķ���ֵ" << c << endl;
	cout << "test2()�ķ���ֵ" <<d << endl;
	cout << "test2()�ķ���ֵ" << d << endl;
	cout << "������������ֵ" << endl;
	test2() = 30;
	cout << "test2()�ķ���ֵ" << d << endl;
	cout << "test2()�ķ���ֵ" << d << endl;
	return 0;
}