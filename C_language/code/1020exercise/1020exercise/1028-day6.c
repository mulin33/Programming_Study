#include<stdio.h>
#include<string.h>

/*�ַ�����Ӧ��ʾ������������������е���ƽ������*/
//int main()
//{
//	int letter = 0, word_count = 0, flag = 0;
//	char input[30] = { '\0' };
//
//	printf("Please input your sentence:");
//	
//	fgets(input, sizeof(input), stdin);
//	printf("sizeof(input):%d,strlen(input):%d\n", sizeof(input), strlen(input));
//	int n = sizeof(input);
//
//	for (int i = 0; i < n; i++)
//	{
//		char ch = input[i];
//		if (ch == '\n') break;
//		//Ϊ�հ׻���ˮƽ�Ʊ������flag��Ϊ1
//		if (ch == ' ' || ch == '\t')
//			flag = 0;
//		//���㵥�ʸ�������ǰ��Ϊ�հ׻�ˮƽ�Ʊ������һλ���ǣ����û�flag
//		else if (!flag&&ch != ' '&&ch != '\t')
//		{
//			word_count++;
//			flag = 1;
//		}
//			
//		if (ch != ' '&&ch != '\t')
//			letter++;
//	}
//	float word_average = (float)letter / word_count;	//���������תΪ������
//	printf("the average word of your sentence is:%f\n", word_average);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char str[] = "hello:token:language:world\0";
//	int count = 0;
//	char* p = strtok(str, ":");
//	/*�˴�Ҫ����ѭ�����ܽ�str����strtok���Ϸָ�*/
//	while (p != NULL)
//	{
//		count++;
//		printf("%s", p);
//		p = strtok(str, ":");
//	}
//	system("pause");
//	return 0;
//}


//int main()
//{
//	struct student stu1, stu2;
//	stu1.id = 20200532;
//	//stu1.name = "ZhangSan";	//����ᱨ��ԭ�����������ǳ������������ܱ��޸�
//	//stu1.sex = "female";
//	strcpy(stu1.name, "ZhangSan");	//ʹ��strcpy�������Ը��Ƶ��ַ���������
//	strcpy(stu1.sex, "female");
//	printf("id:%d,name:%s,sex:%s\n", stu1.id, stu1.name, stu1.sex);
//
//	system("pause");
//	return 0;
//}

//typedef ����
typedef struct student
{
	int id;
	char name[30];
	char sex[30];
	int age;
}Stu;
typedef struct student *stuP;
//Stu stu1 = { 3,"Lin","female",22 };	//��ͬstruct student stu1={...};

int main()
{
	struct student stu1 = { 1,"ZhangSan","male",20 };
	struct student stu2 = { 2,"LiSi","male",22 };

	/*����ṹ�����鲢��ʼ��*/
	struct student stu_array[] = { stu1,stu2 };	
	/*����ָ��ṹ�������ָ�벢��ʼ��*/
	struct student *stu_arrayP = &stu_array;
	/*ʹ�ýṹ��ָ��stuP*/
	stuP stu_test = &stu_array;
	printf("%d\n", stu_test->age);
	for (int i = 0; i < 2; i++)
	{
		printf("%d\n", stu_arrayP->id);
		stu_arrayP++;
	}
	printf("%d\n%d\n", stu_array[0].id, stu_array[1].id);

	/*����ṹ��ָ�����鲢��ʼ��*/
	struct student *stu_array_point[] = { &stu1,&stu2 };
	printf("%d\n%d\n", stu_array_point[0]->id, stu_array_point[1]->id);
	system("pause");
	return 0;
}