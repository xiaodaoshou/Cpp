# C++泛型编程

## 1 模板

C++提供两种模板机制：函数模板和类模板。

### 1.1 函数模板

作用：建立通用的函数，实现函数参数的**泛型化**，提高代码的**复用性**。

#### 1.1.1函数模板语法

语法：

```C++
template<typename T>
函数声明或定义
```

示例：

```c++
#include<iostream>
using namespace std;
template<typename T>
void Swap(T &a,T &b) {
	T temp = a;
	a = b;
	b = temp;
}
int main() {
	int a = 10;
	int b = 20;
	//自动推导类型
	Swap(a,b);
	cout << "a=" <<a<< endl;
	cout << "b=" << b << endl;
	double c = 10;
	double d = 20;
	//显示指定类型
	Swap<double>(c, d);
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
	return 0;
}
```

总结：

函数模板有自动类型推导和显示指定类型。

#### 1.1.2 函数模板注意事项

模板必须确定出T的数据类型才能使用。

示例：

```c++
#include<iostream>
using namespace std;
template<typename T>
void fun() {
	cout << "fun调用" << endl;
}
void test() {
	fun<int>();
}
int main() {
	test();
	return 0;
}
```



### 1.2类模板

#### 1.21类模板语法

作用：建立一个通用类，类中成员数据类型可以不具体制定。

```c++
template<class T>
    类
```

示例：

```C++
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
	Person <string,long>person("孙悟空", 999);
	person.showPerson();
}
int main() {
	test();
	return 0;
}
```

总结：

1 类模板语法与函数相似，在template后接上一个类，该类被称为类模板。

2 类模板必须示例化才能创建对象。

#### 1.22类模板与函数模板区别

1 类模板没有自动类型推导的使用方式。

2 类模板有默认的参数列表。

示例：

```C++
#include<iostream>
using namespace std;
template<class nametype=string,class agetype=int>
class Person {
public:nametype m_name;
	  agetype m_age;
	  Person(nametype name, agetype age) {
		  this->m_name = name;
		  this->m_age = age;
	  }
	  void showPerson() {
		  cout << this->m_name << endl;
		  cout << this->m_age << endl;
	  }
};
void test() {
	Person<> person0("孙悟空", 999);
	Person<string,double> person1("孙悟空", 999.01);
	person0.showPerson();
	person1.showPerson();
}
int main() {
	test();
	return 0;
}
```

总结：

类模板在没有显示指定类型的情况下回使用默认参数列表，但是实例化时必须加<>。
