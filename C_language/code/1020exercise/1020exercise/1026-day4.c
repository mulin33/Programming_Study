# include<stdio.h>
# include<windows.h>

//void num2char(int num)
//{
//	int temp = num / 10;
//	if (temp != 0)
//		num2char(temp);
//	putchar(num % 10 - 1 + 'A');
//}
//
//int main()
//{
//	int num;
//	printf("请输入你想转换的数字：\n");
//	scanf("%d", &num);
//	printf("输出的对应字母为:\n");
//	num2char(num);
//	printf("\n");
//	system("pause");
//	return 0;
//}

////指针函数注意事项
//int numSum1(int num)
//{
//	int sum = 0;
//	for (int i = 0; i < num; i++)
//		sum = sum + i + 1;
//	return sum;
//}
//int *numSum2(int num)
//{
//	int sum = 0;
//	for (int i = 0; i < num; i++)
//		sum = sum + i + 1;
//	return &sum;
//}
//int main()
//{
//	int num = 10;
//	int sum1 = numSum1(num);
//	int *sum2 = numSum2(num);
//	printf("1-%d相加等于%d\n", num, sum1);	//此处sum被存储在数据段，所以结果无错
//	Sleep(1);
//	printf("1-%d相加等于%d\n", num, *sum2);	//此处sum2指向的sum存储在栈空间已经被释放，结果错误
//	system("pause");
//	return 0;
//}

//指针函数代码示例
//void printMax(int a, int b)
//{
//	if (a > b)
//		printf("a=%d > b=%d\n", a, b);
//	else
//		printf("a=%d < b=%d\n", a, b);
//}
//int main()
//{
//
//	/*定义函数指针*/
//	int(*fp)(int, int);
//	//或者 int (*fp)(int x, int y);
//
//	/*函数指针初始化*/
//	fp = printMax;
//
//	int a = 3, b = 4;
//	/*通过函数指针调用它所指向的函数*/
//	fp(a, b);
//	//等价printMax(a,b)
//
//	system("pause");
//	return 0;
//}