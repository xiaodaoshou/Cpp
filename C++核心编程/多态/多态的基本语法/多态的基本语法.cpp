#include<iostream>
using namespace std;
class Animal {
public: virtual void eat() {
	cout << "动物在吃" << endl;
}
};
class Cat:public Animal {
public: void eat() {
	cout << "猫在吃" << endl;
}
};
class Dog :public Animal {
public: void eat() {
	cout << "狗在吃" << endl;
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