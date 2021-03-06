# C++核心编程

## 指针

### 指针语法

指针定义：`数据类型 * 指针变量名。`

指针变量赋值：`指针变量 =&变量。`

指针使用：通过*解引用操作符来获取指针指向内存的数据。

在32位操作系统下，指针占4个字节大小。

在64位操作系统下，指针占8个字节大小。

```c++
#include<iostream>
using namespace std;
void test() {
	int* p;
	int a = 10;
	p = &a;
	cout << "a的地址为：" << &a << endl;
	cout << "p的值：" << p << endl;
	cout<< "a的值：" << *p << endl;
    cout << "sizeof(int *)" << sizeof(int *)<<endl;
	cout << "sizeof(char *)" << sizeof(char*) << endl;
	cout << "sizeof(float *)" << sizeof(float*) << endl;
	cout << "sizeof(double *)" << sizeof(double*) << endl;
	cout << "sizeof(string *)" << sizeof(string*) << endl;

}
int main() {
	test();
	return 0;
}
```

总结：

1 指针和引用不同，指针是对象有内存空间，可以修改指针的指向，而引用不是对象没有内存空间，不能修改绑定对象。

### 空指针和野指针

空指针：指针变量指向编号为0的内存空间。

**用途**：用来初始化指针变量。

注意：空指针指向的内存不可以访问。

野指针：指针变量指向非法的内存空间。

```C++
#include<iostream>
using namespace std;
void test() {
	int* p0 = NULL;
	int* p1 = (int *)0x1100;
}
int main() {
	test();
	return 0;
}
```

总结：空指针和野指针指向的都不是我们申请的内存空间，所以不要访问。

### const修饰指针

const修饰指针有三种情况

1 `const int*p=&a或者int const *p=&a`  

**常量指针**(**指向常量的指针**)。

**注意**：常量指针限制了指针的间接访问，使得指针无法修改指针指向的地址中的内容，并非代表指针指向的地址中的内容是常量无法修改。

2 i`nt*const p=&a` 

**指针常量：**

**指针本身是个常量**，指针的指向不能改变，其指向的地址中的值是可变的。

3 `const int *const p=&a 或者 int const int *const p=&a`。

**指向常量的指针常量：**

指针的指向和指针指向的地址中的值都不能改变。

示例：

```c++
#include<iostream>
using namespace std;
void test() {
	int a = 10;
	int b = 20;
	int c = 30;
	const int* p0 = &a;//常量指针
	int * const p1 = &b;//指针常量
	const int* const p2 = &c;//指向常量的指针常量
    cout << "*p0的值为：" << *p0 << endl;;
	a = 11;
	cout << "*p0的值为：" << *p0 << endl;
	*p1 = 21;
	cout <<"*p2的值为：" << *p2 << endl;
	c = 31;
	cout << "*p2的值为：" << *p2 << endl;
}
int main() {
	test();
	return 0;
}
```

总结：

1 const 修饰的是什么，什么就是常量。

2 const 限制的是指针的指向或指针的值，但不限制通过原变量来直接修改值。

### 指针的算术运算和数组

指针可以进行四种运算：++，--，+，-。

**+运算：**

指针每+1，则指针指向的地址往后移指针指向的数据类型大小个字节。

例如：int *p，当p+1，则指针p向后移4个字节。

**-运算：**

与+运算相反，指针每-1则指针指向的地址往前移指针指向的数据类型大小个字节。

例如：int *p，当p-1，则指针p向前移4个字节。

**++运算：**

对指针进行递增运算，把值加上其数据类型的字节大小。

**--运算：**

对指针进行递减运算，把值减去其数据类型的字节大小。

**==,>=,<=,!=**

!=可以用来检测指针是否为空指针。

**p=NULL；

示例：

```
#include<iostream>
using namespace std;
void test() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	for (int i = 0;i < 10;*p++)
	{
		cout << "访问数组第" << i << "个元素" << *p<<endl;
		i++;
	}
}
int main() {
	test();
	return 0;
}
```

对一个指向简单变量的指针执行加减运算是没有意义的，指针运算与数组有关。

示例：

```
#include<iostream>
using namespace std;
void test() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	for (int i = 0;i < 10;*p++)
	{
		cout << "访问数组第" << i << "个元素" << *p<<endl;
		i++;
	}
}
int main() {
	test();
	return 0;
}
```

### 指针和函数

**指针可以作为函数的参数，使用指针做函数参数可以在调用函数时改变变量在原函数的值，因此要小心使用。**

总结：

有了指针做参数，函数不仅有输入参数，也有输出参数，函数可以返回多个值。

## 引用

### 引用的语法

引用的作用：给变量起别名。



语法：`数据类型 &引用 = 变量`。



示例：

```c++
#include<iostream>
using namespace std;
void test() {
	int a=10;
	int& b = a;
	cout << "a的值为：" << a<<endl;
	cout << "b的值为：" <<b<< endl;
	b = 20;
    
	cout << "a的值为：" << a << endl;
	cout << "b的值为：" << b << endl;
	int& c = a;
    
	cout << "c的值为：" << c << endl;
}
int main() {
   
	test();
	return 0;
}
```



总结：

1 引用必须初始化。（**即不存在空引用**）

2 引用初始化后只能绑定一个对象，不能指向其他对象。

3一个对象能有多个引用。



### 引用做函数参数

引用做函数参数时，可以修饰实参。

优点：可以简化指针修改实参。

示例：

```c++
#include<iostream>
using namespace std;
void swap1(int a, int b ) {
	int temp = a;
	a = b;
	b = temp;
}
void swap2(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap3(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

}
void test() {
	int a = 10;
	int b = 20;
	cout << "值传递" << endl;
	swap1(a, b);
	cout << "a的值为：" << a << endl;
	cout << "b的值为：" << b << endl;
	cout << "引用传递" << endl;
	swap2(a, b);
	cout << "a的值为：" << a << endl;
	cout << "b的值为：" << b << endl;
	cout << "地址传递" << endl;
	swap3(&a, &b);
	cout << "a的值为：" << a << endl;
	cout << "b的值为：" << b << endl;
}
int main(){
	test();
	return 0;
}
```

总结：

引用做函数参数时，引用名可以与实参名相同。



### 引用做函数返回值

**注意事项：不要返回局部变量的引用**

用法：函数调用作为左值。

示例：

```c++
#include<iostream>
using namespace std;
int& test1() {
	int a = 10;
	return a;
}
int& test2() {
	static int b = 20;
	return b;
}
int main() {
	int& c = test1();
	int& d = test2();
	cout << "test1()的返回值" <<c<< endl;
	cout << "test1()的返回值" << c << endl;
	cout << "test2()的返回值" <<d << endl;
	cout << "test2()的返回值" << d << endl;
    cout << "函数调用做左值" << endl;
	test2() = 30;
	cout << "test2()的返回值" << d << endl;
	cout << "test2()的返回值" << d << endl;
	return 0;
}
```

总结：没有引用做函数返回值时，函数调用不能做左值。



### 常量引用

作用：用来修饰形参，防止误操作。

示例：

```c++
#include<iostream>
using namespace std;
int a = 100;
void test(const int& b) {
	cout << "a的值为：" << b << endl;
}
int main() {
	test(a);
	return 0;
}
```

总结：

1 使用常量引用可以防止变量被修改。

2 实参为局部变量，也可不用加const修饰形参。

注意事项：**常量引用并不代表变量不可以被修改，只是无法通过常量引用修改变量。**

## **继承**

### 继承方式

C++中继承方式有三种，分别为public，protected，private。

语法：`class 派生类 : 继承方式 基类`

示例：

```c++
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
```

总结：

1 无论何种继承方式，基类非private的成员都能在派生中访问。

2 派生类会提升低于继承方式访问权限的基类成员在派生类的访问权限。

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

派生类对象模型：

![派生类对象内存模型](H:\md文档\派生类对象内存模型.png)

总结：

1 派生类对象可以直接访问本类中的同名成员。

2 派生类对象加作用域可以访问基类中的同名成员。

3 当派生类拥有与基类同名的成员函数时，派生类会隐藏基类的同名成员函数，但是派生类的对象模型中仍然有父类的同名成员，加作用域可以访问基类中同名函数（**即使派生类中没有基类中同名成员的重载函数，也不能直接访问基类中同名成员的重载函数**）。



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

## 多态

### 多态的基本语法

多态分两类：

**静态多态**（静态绑定）：函数地址早绑定，编译阶段确定函数地址。

**运行多态**（动态绑定）：函数地址晚绑定，运行阶段确定函数地址

多态条件：
1 继承关系

2 函数重写

3  基类对象指向派生类

示例：

```C++
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
```

