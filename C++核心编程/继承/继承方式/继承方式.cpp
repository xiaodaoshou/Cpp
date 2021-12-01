#include<iostream>
using namespace std;
class Base {
public:int m_A;
protected:int m_B;
private:int m_C;
};
class Son1 :public Base {
public:Son1() {
		m_A = 1;
		cout << m_A << endl;
		m_B = 1;
		cout << m_B << endl;
	}
};
class Son2 :protected Base {
public:	Son2() {
		m_A = 2;
		cout << m_A << endl;
		m_B = 2;
		cout << m_B << endl;
	}
};
class Son3 :private Base {
public:	Son3() {
		m_A = 3;
		cout << m_A << endl;
		m_B = 3;
		cout << m_B << endl;
	}
};
void test() {
	Son1 s1;
	Son2 s2;
	Son3 s3;
}
int main() {
	test();
	return 0;
}