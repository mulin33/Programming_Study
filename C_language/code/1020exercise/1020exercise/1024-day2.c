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

////ȫ�ֱ�����ʡ��extern
//int a = 3;
////��̬ȫ�ֱ���
//static int b = 4;
//
//extern void variable(void);
//
//int main()
//{
//	printf("��һ�ε��ú�����\n");	//3,4,5,6
//	variable();
//	printf("�ڶ��ε��ú�����\n");	//4,5,5,7
//	variable();
//	printf("�����ε��ú�����\n");	//5,6,5,8
//	variable();
//
//	system("pause");
//	return 0;
//}
//static void variable(void)
//{
//	//�ֲ�����,ʡ��auto
//	int c = 5;
//	//��̬�ֲ�����
//	static int d = 6;
//	printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	a++;
//	b++;
//	c++;
//	d++;
//}
