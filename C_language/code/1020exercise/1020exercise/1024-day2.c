# include <stdio.h>

//int main()
//{
//	int a = 3, b = 4;
//	int const * const p1 = &a;
//	//*p1 = b;----error
//	//p1 = &b;----error
//
//	system("pause");
//	return 0;
//}

////全局变量，省略extern
//int a = 3;
////静态全局变量
//static int b = 4;
//
//extern void variable(void);
//
//int main()
//{
//	printf("第一次调用函数：\n");	//3,4,5,6
//	variable();
//	printf("第二次调用函数：\n");	//4,5,5,7
//	variable();
//	printf("第三次调用函数：\n");	//5,6,5,8
//	variable();
//
//	system("pause");
//	return 0;
//}
//static void variable(void)
//{
//	//局部变量,省略auto
//	int c = 5;
//	//静态局部变量
//	static int d = 6;
//	printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	a++;
//	b++;
//	c++;
//	d++;
//}
