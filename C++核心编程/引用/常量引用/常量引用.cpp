#include<iostream>
using namespace std;
int a = 100;
void test(const int& b) {
	cout << "aµÄÖµÎª£º" << b << endl;
}
int main() {
	test(a);
	return 0;
}