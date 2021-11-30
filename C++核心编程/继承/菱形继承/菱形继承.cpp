#include<iostream>
using namespace std;
class Animal {
public:int m_age;
};
class lion :virtual public Animal {};
class tiger :virtual public Animal{};
class liger :public lion, public tiger {};
void test() {
	liger l;
	l.lion::m_age = 12;
	l.tiger::m_age = 13;
	cout << "l.lion::m_age的年龄为" << l.lion::m_age << endl;
	cout << "l.tiger::m_age的年龄为" << l.tiger::m_age << endl;
}
int main() {
	test();
	return 0;
}