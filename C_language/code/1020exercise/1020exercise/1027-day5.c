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
//	printf("��������ĳɼ���\n");
//	scanf("%d", &grade);
//	judgement = comprehensive_grade(grade, grade_judgement);
//	printf("���ĳɼ�����Ϊ��%c\n", judgement);
//
//	system("pause");
//	return 0;
//}


//����ָ��ʾ��
//int main()
//{
//	int(*arrayP)[3];
//	int array[2][3] = { {1,2,3},{4,5,6} };
//	arrayP = array;
//	printf("�����һ�е�һ��Ԫ��Ϊ%d\n", *arrayP[0]);	//1
//	arrayP++;
//	printf("����ڶ��е�һ��Ԫ��Ϊ%d\n", *arrayP[0]);	//4
//
//	system("pause");
//	return 0;
//}

//�ַ�����ʾ��
//int main()
//{
//	/*��ά�ַ����鼰���ʼ��*/
//	char a[][10] = { "orange","apple","banana" };
//
//	/*�ַ���ʼ���ַ�����*/
//	char str1[] = { 'a','b','c','\0' };	//���������'\0'��β���������
//	/*�ַ�����ʼ��*/
//	char str2[] = "Hello";	//'\0'ʡ���ˣ��ַ���ʵ����'\0'��β
//	printf("�ַ���%s��ʵ�ʳ���Ϊ��%d\n", str2, sizeof(str2));	//result:6
//	printf("����'0'���ַ���%s�ĳ���Ϊ��%d\n", str2, strlen(str2));	//result:5
//
//	system("pause");
//	return 0;
//}