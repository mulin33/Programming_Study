#include<stdio.h>
#include<string.h>
#include "c_Exercise.h"

//char grade_judgement(int grade)
//{
//	if (grade >= 90)
//		return 'A';
//	else if (grade >= 70)
//		return 'B';
//	else if (grade >= 60)
//		return 'C';
//	else
//		return 'N';
//}
//
//int main()
//{
//	int grade;
//	char judgement;
//	printf("请输入你的成绩：\n");
//	scanf("%d", &grade);
//	judgement = comprehensive_grade(grade, grade_judgement);
//	printf("您的成绩评级为：%c\n", judgement);
//
//	system("pause");
//	return 0;
//}


//数组指针示例
//int main()
//{
//	int(*arrayP)[3];
//	int array[2][3] = { {1,2,3},{4,5,6} };
//	arrayP = array;
//	printf("数组第一行第一列元素为%d\n", *arrayP[0]);	//1
//	arrayP++;
//	printf("数组第二行第一列元素为%d\n", *arrayP[0]);	//4
//
//	system("pause");
//	return 0;
//}

//字符数组示例
//int main()
//{
//	/*二维字符数组及其初始化*/
//	char a[][10] = { "orange","apple","banana" };
//
//	/*字符初始化字符数组*/
//	char str1[] = { 'a','b','c','\0' };	//建议最后以'\0'结尾，方便输出
//	/*字符串初始化*/
//	char str2[] = "Hello";	//'\0'省略了，字符串实际以'\0'结尾
//	printf("字符串%s的实际长度为：%d\n", str2, sizeof(str2));	//result:6
//	printf("忽略'0'的字符串%s的长度为：%d\n", str2, strlen(str2));	//result:5
//
//	system("pause");
//	return 0;
//}