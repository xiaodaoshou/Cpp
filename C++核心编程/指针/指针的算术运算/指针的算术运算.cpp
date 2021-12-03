#include<iostream>
using namespace std;
void test() {
	short int a = 10;
	int b = 11;
	short int* p0 = &a;
	int* p1 = &b;
	int* p2=&b;
	cout << "p0的值:" << (int)p0 << endl;
	cout << "p1的值:" <<(int) p1 << endl;
	p0 = p0 + 1;
	p1 = p1 + 1;
	cout << "p0的值:" <<(int) p0 << endl;
	cout << "p1的值:" << (int)p1 << endl;
	p0 = p0 - 1;
	p1 = p1 - 1;
	cout << "p0的值:" << (int)p0 << endl;
	cout << "p1的值:" << (int)p1 << endl;
	if (p2 != NULL)
		cout << "p2是空指针" << endl;
	else
		cout << "p2不是空指针" << endl;
}
int main() {
	test();
	return 0;
}