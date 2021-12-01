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
	cout << "值传递" << endl;
	swap1(a, b);
	cout << "a的值为：" << a << endl;
	cout << "b的值为：" << b << endl;
	cout << "引用传递" << endl;
	swap2(a, b);
	cout << "a的值为：" << a << endl;
	cout << "b的值为：" << b << endl;
	cout << "地址传递" << endl;
	swap3(&a, &b);
	cout << "a的值为：" << a << endl;
	cout << "b的值为：" << b << endl;
}
int main(){
	test();
	return 0;
}