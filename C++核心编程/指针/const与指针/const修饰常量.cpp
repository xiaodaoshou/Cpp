#include<iostream>
using namespace std;
void test() {
	int a = 10;
	int b = 20;
	int c = 30;
	const int* p0 = &a;//����ָ��
	int * const p1 = &b;//ָ�볣��
	const int* const p2 = &c;//ָ������ָ�볣��
}
int main() {
	test();
	return 0;
}