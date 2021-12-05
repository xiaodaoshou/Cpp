#include<iostream>
using namespace std;
template<typename T>
void Swap(T &a,T &b) {
	T temp = a;
	a = b;
	b = temp;
}
int main() {
	int a = 10;
	int b = 20;
	//自动推导类型
	Swap(a,b);
	cout << "a=" <<a<< endl;
	cout << "b=" << b << endl;
	double c = 10;
	double d = 20;
	//显示指定类型
	Swap<double>(c, d);
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
	return 0;
}