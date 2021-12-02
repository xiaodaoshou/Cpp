#include<iostream>
using namespace std;
void test() {
	int* p;
	int a = 10;
	p = &a;
	cout << "a的地址为：" << &a << endl;
	cout << "p的值：" << p << endl;
	cout<< "a的值：" << *p << endl;
	cout << "sizeof(int *)" << sizeof(int *)<<endl;
	cout << "sizeof(char *)" << sizeof(char*) << endl;
	cout << "sizeof(float *)" << sizeof(float*) << endl;
	cout << "sizeof(double *)" << sizeof(double*) << endl;
	cout << "sizeof(string *)" << sizeof(string*) << endl;
}
int main() {
	test();
	return 0;
}