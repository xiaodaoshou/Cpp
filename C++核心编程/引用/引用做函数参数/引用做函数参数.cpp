#include<iostream>
using namespace std;
void swap1(int a, int b ) {
	int temp = a;
	a = b;
	b = temp;
}
void swap2(int& c, int& d) {
	int temp = c;
	c = d;
	d = temp;
}
void swap3(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

}
void test() {
	int a = 10;
	int b = 20;
	cout << "ֵ����" << endl;
	swap1(a, b);
	cout << "a��ֵΪ��" << a << endl;
	cout << "b��ֵΪ��" << b << endl;
	cout << "���ô���" << endl;
	swap2(a, b);
	cout << "a��ֵΪ��" << a << endl;
	cout << "b��ֵΪ��" << b << endl;
	cout << "��ַ����" << endl;
	swap3(&a, &b);
	cout << "a��ֵΪ��" << a << endl;
	cout << "b��ֵΪ��" << b << endl;
}
int main(){
	test();
	return 0;
}