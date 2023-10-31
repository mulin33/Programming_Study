# include<stdio.h>
//
///*可以在当前文件和其他文件使用，省略extern*/
//int x = 10;
///*仅限当前文件使用*/
//static int y = 10;
///*外部函数，可以在多个文件使用，extern可以省略，但一般会保留，提醒可以被外部调用*/
//extern int a() 
//{
//	printf("a为外部函数");
//}
///*内部函数，仅限于当前文件*/
//static int b()
//{
//	/*存储类型为auto，局部变量*/
//	int k = 1;
//	/*静态局部变量，仅限当前函数使用，生命周期变长*/
//	static int m = 2;
//}

//此处extern用来声明，因为变量定义在引用后面
//extern int a, b;
//int main()
//{
//	printf("a=%d\nb=%d\n", a, b);
//	system("pause");
//	return 0;
//}
//
//int a = 10, b = 1;

