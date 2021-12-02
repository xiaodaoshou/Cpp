#include<iostream>
using namespace std;
void test() {
	int* p0 = NULL;
	int* p1 = (int *)0x1100;
	cout << *p1 << endl;
}
int main() {
	test();
	return 0;
}