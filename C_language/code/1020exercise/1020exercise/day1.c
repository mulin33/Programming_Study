#include <stdio.h>


//int main()
//{
//	int a = 10;
//	int *p1 = &a;
//	printf("a=%d\n", *p1);
//
//	/*指针的初始化*/
//	//NULL为空指针，不指向任何变量，值为0
//	int *p2 = NULL; 
//	printf("p2=%p\n", p2);
//	printf("p2存储地址的值=%d\n", p2);
//	system("pause");
//	return 0;
//}
/*
void func1(int array[], int size);
void func2(int *ap, int size);

int main()
{
	double a[] = { 1,10,100,1000,10000 };
	int *p = a;
	printf("++(*p):%d\n", ++(*p));	//2
	printf("(*p)++:%d\n", (*p)++);	//2
	//数组元素值被修改
	printf("a[0]:%d\n", a[0]);	//3

	//自增和取值运算符优先级一样，从右往左进行运算
	printf("*p++:%d\n", *p++);	//3
	printf("*(p++):%d\n", *(p++));	//100
	printf("*p:%d\n", *p);	//10

	printf("a[1]=%d\n", a[1]);	//10
	printf("*(a+1)=%d\n", *(a + 1));	//10

	printf("在main函数里数组字节长度:%d\n", sizeof(a));
	func1(a, 5);

	system("pause");
	return 0;
}

void func1(int array[], int size)
{
	printf("在调用函数里数组字节长度:%d\n", sizeof(array));
	return;
}
*/
