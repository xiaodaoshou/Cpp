#include<iostream>
using namespace std;
void test() {
	int a = 10;
	int b = 20;
	int c = 30;
	const int* p0 = &a;//常量指针
	int * const p1 = &b;//指针常量
	const int* const p2 = &c;//指向常量的指针常量
	cout << "*p0的值为：" << *p0 << endl;;
	a = 11;
	cout << "*p0的值为：" << *p0 << endl;
	*p1 = 21;
	cout <<"*p2的值为：" << *p2 << endl;
	c = 31;
	cout << "*p2的值为：" << *p2 << endl;
}
int main() {
	test();
	return 0;
}