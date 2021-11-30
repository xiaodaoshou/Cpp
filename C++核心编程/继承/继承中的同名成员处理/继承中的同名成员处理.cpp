#include<iostream>
using namespace std;
class Base {
public:	int m_A;
	Base() {
		m_A = 10;
	}
	void fun() {
		cout << "Base类中的fun函数" << endl;
	}
	void fun(int a) {
		cout << "Base类中的重载fun函数" << endl;
	}
};
class Son :public Base {
public:int m_A;
	Son() {
		m_A = 20;
	}
	void fun() {
		cout << "Son类中的fun函数" << endl;
	}
};
void test() {
	Son s;
	cout << "Son类中的m_A:" <<s.m_A << endl;
	cout << "Base类中的m_A:"<< s.Base::m_A << endl;
	s.fun();
	s.Base::fun();
	s.Base::fun(100);
}
int main() {
	test();
	return 0;
}