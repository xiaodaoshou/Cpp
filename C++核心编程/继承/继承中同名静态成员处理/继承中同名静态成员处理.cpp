#include<iostream>
using namespace std;
class Base {
public:static int m_A;
	  static void fun() {
		  cout << "Base下的fun" << endl;
	  }
};
int Base::m_A = 10;
class Son:public Base {
public:static int m_A;
	  static void fun() {
		  cout << "Son下的fun" << endl;
	  }
};
int Son::m_A = 20;
void test() {
	Son s;
	//通过对象访问
	cout << "Son下的m_A=" << s.m_A<<endl;
	cout << "Base下的m_A=" <<s.Base::m_A <<endl;
	s.fun();
	s.Base::fun();
	//通过类名访问
	cout << "Son下的m_A=" <<Son::m_A <<endl;
	cout << "Base下的m_A=" <<Son::Base::m_A<< endl;
	Son::fun();
	Son::Base::fun();
}
int main() {
	test();
	return 0;
}