#include<iostream>
using namespace std;
class Base1 {
public:  int m_A;
	  Base1() {
		  m_A = 10;
	  }
	
};
class Base2 {
public: int m_A;
	  Base2() {
		  m_A = 20;
	  }
};
class Son :public Base1,public Base2{
public:
	int m_C;
	Son() {
		m_C = 30;
	}
};
void test() {
	Son s;
	cout << "Base1�е�m_A=" << s.Base1::m_A << endl;
	cout << "Base2�е�m_A=" << s.Base2::m_A << endl;
	cout << "Son�е�m_C=" << s.m_C << endl;
}
int main() {
	test();
	return 0;
}