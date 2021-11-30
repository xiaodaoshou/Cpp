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



### 继承中同名静态成员处理方式

示例：

```C++
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
```

总结：同名静态成员与非静态成员处理方式一样，其父类的同名成员被隐藏起来，并非没有继承，而是需要通过加作用域运算符来访问。在派生类对象的内存中仍有父类的同名成员空间。



### 多继承语法

C++中允许一个类继承多个类。

单继承中，派生类是基类的特例化，而在多继承中，派生类则是所有基类的一种组合。

语法：`class 派生类:继承方式 基类1，继承方式 基类2，。。。。。`

多继承可能会引发派生类与多个基类的成员同名问题，可以加作用域来解决。

**注意事项：实际开发中不建议使用多继承。**

示例：

```c++
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
	cout << "Base1中的m_A=" << s.Base1::m_A << endl;
	cout << "Base2中的m_A=" << s.Base2::m_A << endl;
	cout << "Son中的m_C=" << s.m_C << endl;
}
int main() {
	test();
	return 0;
}
```



### 菱形继承

菱形继承是指一个派生类继承自另外两个派生类，而这两个派生类又继承自同一个基类。

 

```C++
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
```

