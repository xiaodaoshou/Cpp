#include<iostream>
using namespace std;
class Base {
public:	int m_A;
	Base() {
		m_A = 10;
	}
	void fun() {
		cout << "Base���е�fun����" << endl;
	}
	void fun(int a) {
		cout << "Base���е�����fun����" << endl;
	}
};
class Son :public Base {
public:int m_A;
	Son() {
		m_A = 20;
	}
	void fun() {
		cout << "Son���е�fun����" << endl;
	}
};
void test() {
	Son s;
	cout << "Son���е�m_A:" <<s.m_A << endl;
	cout << "Base���е�m_A:"<< s.Base::m_A << endl;
	s.fun();
	s.Base::fun();
	s.Base::fun(100);
}
int main() {
	test();
	return 0;
}