#include<iostream>
using namespace std;
template<typename T>
void fun() {
	cout << "fun����" << endl;
}
void test() {
	fun<int>();
}
int main() {
	test();
	return 0;
}