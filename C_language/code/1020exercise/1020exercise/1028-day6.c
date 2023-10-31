#include<stdio.h>
#include<string.h>

/*字符数组应用示例——计算输入语句中单词平均长度*/
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
//		//为空白或者水平制表符，将flag置为1
//		if (ch == ' ' || ch == '\t')
//			flag = 0;
//		//计算单词个数，即前面为空白或水平制表符而后一位不是，并置回flag
//		else if (!flag&&ch != ' '&&ch != '\t')
//		{
//			word_count++;
//			flag = 1;
//		}
//			
//		if (ch != ' '&&ch != '\t')
//			letter++;
//	}
//	float word_average = (float)letter / word_count;	//输出别忘了转为浮点型
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
//	/*此处要调用循环才能将str调用strtok不断分割*/
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
//	//stu1.name = "ZhangSan";	//这里会报错，原因是数组名是常量，常量不能被修改
//	//stu1.sex = "female";
//	strcpy(stu1.name, "ZhangSan");	//使用strcpy函数可以复制到字符数组里面
//	strcpy(stu1.sex, "female");
//	printf("id:%d,name:%s,sex:%s\n", stu1.id, stu1.name, stu1.sex);
//
//	system("pause");
//	return 0;
//}

//typedef 举例
typedef struct student
{
	int id;
	char name[30];
	char sex[30];
	int age;
}Stu;
typedef struct student *stuP;
//Stu stu1 = { 3,"Lin","female",22 };	//等同struct student stu1={...};

int main()
{
	struct student stu1 = { 1,"ZhangSan","male",20 };
	struct student stu2 = { 2,"LiSi","male",22 };

	/*定义结构体数组并初始化*/
	struct student stu_array[] = { stu1,stu2 };	
	/*定义指向结构体数组的指针并初始化*/
	struct student *stu_arrayP = &stu_array;
	/*使用结构体指针stuP*/
	stuP stu_test = &stu_array;
	printf("%d\n", stu_test->age);
	for (int i = 0; i < 2; i++)
	{
		printf("%d\n", stu_arrayP->id);
		stu_arrayP++;
	}
	printf("%d\n%d\n", stu_array[0].id, stu_array[1].id);

	/*定义结构体指针数组并初始化*/
	struct student *stu_array_point[] = { &stu1,&stu2 };
	printf("%d\n%d\n", stu_array_point[0]->id, stu_array_point[1]->id);
	system("pause");
	return 0;
}