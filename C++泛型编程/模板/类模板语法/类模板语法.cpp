#include<iostream>
using namespace std;
template<class nametype,class agetype>
class Person {
public:nametype m_name;
	  agetype m_age;
	  Person(nametype name,agetype age) {
		  this->m_name = name;
		  this->m_age = age;
	  }
	  void showPerson() {
		  cout << this->m_name << endl;
		  cout << this->m_age << endl;
	  }
};
void test() {
	Person <string,long>person("ËïÎò¿Õ", 999);
	person.showPerson();
}
int main() {
	test();
	return 0;
}