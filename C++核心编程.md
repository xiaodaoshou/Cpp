# C++核心编程

## 继承



### 继承中的构造和析构顺序

问题：派生类在创建对象时会自动调用基类构造函数，那么两者构造和析构函数的顺序是怎么样的呢？

示例：

```c++
#include<iostream>
using namespace std;
class Base {
public:Base(){
		cout << "Base的构造函数" << endl;
	}
	~Base() {
		cout << "Base的析构函数" << endl;
	}
};
class Son:public Base {
public: Son() {
		cout << "Son的构造函数" << endl;
	}
	~Son() {
		cout << "Son的析构函数" << endl;
	}
};
void test() {
	Son s;
}
int main() {
	test();
	return 0;
}
```

 结论：继承中先调用基类构造函数，后调用派生类构造函数，析构顺序则相反。



### 继承中同名成员处理方式

问题：当派生类与父类出现同名的成员是，如何通过派生类对象去访问派生类成员和基类的同名成员。

示例：

```c++
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
```

总结：

1 派生类对象可以直接访问本类中的同名成员。

2 派生类对象加作用域可以访问基类中的同名成员。

3 当派生类拥有与基类同名的成员函数时，派生类会隐藏基类的同名成员函数，加作用域可以访问基类中同名函数（**即使派生类中没有基类中同名成员的重载函数，也不能直接访问基类中同名成员的重载函数**）。

