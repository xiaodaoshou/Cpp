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
	//�Զ��Ƶ�����
	Swap(a,b);
	cout << "a=" <<a<< endl;
	cout << "b=" << b << endl;
	double c = 10;
	double d = 20;
	//��ʾָ������
	Swap<double>(c, d);
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
	return 0;
}