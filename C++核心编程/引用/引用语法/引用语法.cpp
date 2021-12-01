#include<iostream>
using namespace std;
void test() {
	int a=10;
	int& b = a;
	cout << "a的值为：" << a<<endl;
	cout << "b的值为：" <<b<< endl;
	b = 20;
	cout << "a的值为：" << a << endl;
	cout << "b的值为：" << b << endl;
	int& c = a;
	cout << "c的值为：" << c << endl;
	int d=5;
	int & b = d;
	cout<< "b的值为：" << b << endl;
}
int main() {
	test();
	return 0;
}