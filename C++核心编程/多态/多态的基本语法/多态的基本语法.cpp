#include<iostream>
using namespace std;
class Animal {
public: virtual void eat() {
	cout << "�����ڳ�" << endl;
}
};
class Cat:public Animal {
public: void eat() {
	cout << "è�ڳ�" << endl;
}
};
class Dog :public Animal {
public: void eat() {
	cout << "���ڳ�" << endl;
}
};
void doeat(Animal& animal) {
	animal.eat();
}
void test() {
	Dog dog;
	Cat cat;
	doeat(dog);
	doeat(cat);
}
int main() {
	test();
	return 0;
}