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
//	printf("����������ת�������֣�\n");
//	scanf("%d", &num);
//	printf("����Ķ�Ӧ��ĸΪ:\n");
//	num2char(num);
//	printf("\n");
//	system("pause");
//	return 0;
//}

////ָ�뺯��ע������
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
//	printf("1-%d��ӵ���%d\n", num, sum1);	//�˴�sum���洢�����ݶΣ����Խ���޴�
//	Sleep(1);
//	printf("1-%d��ӵ���%d\n", num, *sum2);	//�˴�sum2ָ���sum�洢��ջ�ռ��Ѿ����ͷţ��������
//	system("pause");
//	return 0;
//}

//ָ�뺯������ʾ��
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
//	/*���庯��ָ��*/
//	int(*fp)(int, int);
//	//���� int (*fp)(int x, int y);
//
//	/*����ָ���ʼ��*/
//	fp = printMax;
//
//	int a = 3, b = 4;
//	/*ͨ������ָ���������ָ��ĺ���*/
//	fp(a, b);
//	//�ȼ�printMax(a,b)
//
//	system("pause");
//	return 0;
//}