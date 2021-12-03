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