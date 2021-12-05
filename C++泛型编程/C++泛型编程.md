# C++泛型编程

## 模板

C++提供两种模板机制：函数模板和类模板。

### 函数模板

作用：建立通用的函数，实现函数参数的**泛型化**，提高代码的**复用性**。

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

函数模板有自动类型推导和显示指定类型

### 类模板

