#include<iostream>
using namespace std;
void test() {
	int a=10;
	int& b = a;
	cout << "a��ֵΪ��" << a<<endl;
	cout << "b��ֵΪ��" <<b<< endl;
	b = 20;
	cout << "a��ֵΪ��" << a << endl;
	cout << "b��ֵΪ��" << b << endl;
	int& c = a;
	cout << "c��ֵΪ��" << c << endl;
	int d=5;
	int & b = d;
	cout<< "b��ֵΪ��" << b << endl;
}
int main() {
	test();
	return 0;
}