#include<iostream>
using namespace std;
void test() {
	int a = 10;
	int b = 20;
	int c = 30;
	const int* p0 = &a;//����ָ��
	int * const p1 = &b;//ָ�볣��
	const int* const p2 = &c;//ָ������ָ�볣��
	cout << "*p0��ֵΪ��" << *p0 << endl;;
	a = 11;
	cout << "*p0��ֵΪ��" << *p0 << endl;
	*p1 = 21;
	cout <<"*p2��ֵΪ��" << *p2 << endl;
	c = 31;
	cout << "*p2��ֵΪ��" << *p2 << endl;
}
int main() {
	test();
	return 0;
}