# <h1 align = "center">C进阶学习[^温馨提示]</h1>

## 1 指针进阶

### 1.1 指针基础

#### 1.1.1 指针的介绍

```c
/*-----定义指针--------*/
//p1为指针变量，占四个字节
int a = 10;
int *p1 = &a;

/*-------指针的初始化-----------*/
//NULL为空指针，不指向任何变量
int *p2 = NULL;
printf("p2=%p\n", p2);  //00000000
printf("p2=%d\n", p2);  //0

//初始化一个随机数，指向不确定的内存区域
int *p3;
```

#### 1.1.2 **指针加减运算**

参考下方代码可理解取值和自增运算符，注意*数组元素会被修改*

```c
int main()
{
	int a[] = { 1,10,100,1000,10000 };
	int *p = a;
	printf("++(*p):%d\n", ++(*p));	//2
	printf("(*p)++:%d\n", (*p)++);	//2
	//数组元素值被修改
	printf("a[0]:%d\n", a[0]);	//3

	//自增和取值运算符优先级一样，从右往左进行运算
	printf("*p++:%d\n", *p++);	//3
	printf("*(p++):%d\n", *(p++));	//100
	printf("*p:%d\n", *p);	//10

	system("pause");
	return 0;
}
```

#### 1.1.3 **二级指针**

二级指针变量中存放的是一级指针变量的地址

```c
int a=10;
int *p=&a;
int **pp=&p;
```

#### 1.1.4 常量指针和指针常量

> **常量指针**：
>
> * 通过该指针不可以修改它所指向的存储单元中的值
> * 指针本身地址可以被修改
> * 常作为***函数形参***使用——目的是在函数中不允许通过该常量指针去修改它所指向的存储单元中的值
>
> ```c
> int a = 3;
> int const *p1 = &a;
> 
> //*p1 = 4;----error:指针指向的值不能被修改
> 
> int b = 4;
> p1 = &b;	//p1存储的地址可以被修改
> 
> void func(int const *p);	//常量指针在函数形参中使用
> ```

> **指针常量**
>
> * 指针本身不可以被修改
> * 通过该指针可以修改它所指向的存储单元中的值
>
> ```c
> int a = 3, b = 4;
> int * const p1 = &a;
> 
> //p1 = &b;----error:指针本身不能被修改
> 
> *p1 = b;	//指向的值可以被修改
> 
> int c = 5;
> int **pp1 = &p1;
> *pp1 = &c;	//通过二级指针可以修改指针常量
> ```

> **指向常量的指针常量**
>
> * 指针本身不可以被修改
> * 通过该指针不可以修改它所指向的存储单元中的值
>
> ```c
> int a = 3, b = 4;
> int const * const p1 = &a;
> //*p1 = b;----error
> //p1 = &b;----error
> ```



****

### 1.2 段错误和Linux内存管理

![image-20231024152811031](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231024152811031.png)

***段错误***是访问的内存超出系统所给这个程序的内存空间

1. 操作空指针
2. 操作地址不存在的内存
3. 操作受系统保护的内存

**Linux内存管理**

* 进程隔离：计算机上每一个**进程**都为其分配4G的虚拟内存
* 段页式内存管理：内存->段->页，虚拟地址由段号，页号和页中偏移量构成，虚拟地址和内存中物理地址**动态映射**

假设有32条总线，则其**虚拟内存**空间为2<sup>32</sup>约等于4G，其可分为以下几个部分。

> 1. **栈**
>
> * 存储局部变量，参数，函数返回地址等
>
> 2. **堆**
>
> * 动态内存分配，由程序员调用***malloc***等函数向系统中申请任意指定大小的内存，并调用***free***函数释放
>
> 3. **数据段**
>
> * 静态存储区：存储全局变量和static变量，分为初始化区和未初始化区
> * 常量区
>
> 4. **代码段**
>
> * 存储程序的函数代码

<img src="https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231024165837787.png" alt="image-20231024165837787" style="zoom: 33%;" />

**C程序的执行流程**

<img src="https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231024172817365.png" alt="image-20231024172817365" style="zoom: 50%;" />

### 1.3 指针和数组

**数组**存储在一块连续的内存单元；**数组名**是内存单元首地址，也是第一个元素地址；**数组名**是一个常量，不允许重新赋值	

#### 1.3.1. 数组作为函数参数进行传参

```c
/*有以下两种：第一种为数组，第二种为指针形式----------------------------------*/
void func1(int array[], int size);
void func2(int *ap, int size);

/*注意数组在main和func1函数里sizeof计算方式不一样---------------------------------*/
int main()
{
    double a[] = { 1,10,100,1000,10000 };
    printf("在main函数里数组字节长度:%d\n", sizeof(a));	//在main是总的数组长度——40
	func1(a, 5);
}
void func1(int array[], int size)
{
	printf("在调用函数里数组字节长度:%d\n", sizeof(array));	//在func1是指针长度——4
	return;
}
```

#### 1.3.2 数组指针和指针数组

> **数组指针**
>
> * 指向数组的指针，也叫**行指针**
>
> * ```c
>   int(*P)[n];	//优先级：()>[]>*
>   int (*p)[4];	//定义了一个指向含有4个元素的一维数组的指针
>   int a[3][4];
>   p=a;	//将二维数组的首地址赋值给p,即a[0][0]
>   p++;	//表示p将跨过行a[0][],指向a[1][]
>   ```
>
> * ```c
>   //数组指针示例
>   int main()
>   {
>   	int(*arrayP)[3];
>   	int array[2][3] = { {1,2,3},{4,5,6} };
>   	arrayP = array;
>   	printf("数组第一行第一列元素为%d\n", *arrayP[0]);	//1
>   	arrayP++;
>   	printf("数组第二行第一列元素为%d\n", *arrayP[0]);	//4
>               
>   	system("pause");
>   	return 0;
>   }
>   ```

> **指针数组**
>
> * 数组含有的元素为指针类型
>
> * ```c
>   int* pArray[n];	//优先级：()>[]>*	
>   ```
>
> * 



### 1.4 指针和函数

#### 1.4.1 函数栈的调度流程

函数的**调用过程**实际上是对**栈空间**操作过程，调用函数是使用对栈空间来保存信息，**过程如下**：

1. 建立被调用函数的栈空间
2. 保护调用函数的运行状态和返回地址
3. 传递函数实参给形参
4. 执行被调用函数的函数体内语句
5. 将控制权或返回值转交给调用函数
6. 函数调用完毕，释放被调用函数的栈空间

不同被调函数栈区互相独立，即使**同一函数多次被调用其每次栈空间地址不同**

**值传递和地址传递**

> **值传递**：在函数调用过程中，形参值的变化不会影响到实参值的变化
>
> **地址传递**：通过形参指针可以修改实参指针所指向的存储单元中的值

--------

#### 1.4.2 递归调用

* 一个函数在它的函数体内**调用它自身**称为递归调用，这种函数称为递归函数，每次调用开辟新的栈空间
* **应用**：其在阶乘，二叉树，汉诺塔，背包等问题
* 递归所需特性：

1. 存在限制条件，当符合限制条件递归不再继续
2. 每次递归越来越接近该限制条件
3. 其占用内存较多，使用前考虑递归还是迭代，尾部递归最好采用循环方式以提高效率

```c
# include<stdio.h>

//递归调用示例，将数字转为大写字母A——I
void num2char(int num)
{
	int temp = num / 10;
	if (temp != 0)
		num2char(temp);
	putchar(num % 10 - 1 + 'A');
}

int main()
{
	int num;
	printf("请输入你想转换的数字：\n");
	scanf("%d", &num);
	printf("输出的对应字母为:\n");
	num2char(num);
	printf("\n");
	system("pause");
	return 0;
}
```

#### 1.4.3 指针函数和函数指针

1. **指针函数**——返回类型是某一类型的指针，本质是一个函数。示例：`int *func(paramenter) { }`

从下可得：指针函数要**避免返回局部变量地址**，因为存储局部变量的栈空间会被回收

```c
//指针函数注意事项
int numSum1(int num)
{
	int sum = 0;
	for (int i = 0; i < num; i++)
		sum = sum + i + 1;
	return sum;
}
int *numSum2(int num)
{
	int sum = 0;
	for (int i = 0; i < num; i++)
		sum = sum + i + 1;
	return &sum;
}
int main()
{
	int num = 10;
	int sum1 = numSum1(num);
	int *sum2 = numSum2(num);
	printf("1-%d相加等于%d\n", num, sum1);	//result:55----此处sum被存储在数据段，所以结果无错
	Sleep(1);
	printf("1-%d相加等于%d\n", num, *sum2);	//result:1----此处sum2指向的sum存储在栈空间已经被释放，结果错误
	system("pause");
	return 0;
}
```

2. **函数指针**——C语言在编译时，每一个函数都有一个入口地址，该入口地址就是函数指针。通过函数指针，可以调用它所指向的函数

函数指针的定义、初始化、和调用方式及相应代码示例如下：

> * ***personally***:函数指针这里只是一个概念，像下面代码段的用法只是一种介绍，并不实用，其真正用法在于后面**1.4.4 回调函数**和**1.4.5函数指针数组**
>
> * **函数名**就是一个函数指针

![](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231026212112983.png)

```c
//指针函数代码示例
void printMax(int a, int b)
{
	if (a > b)
		printf("a=%d > b=%d\n", a, b);
	else
		printf("a=%d < b=%d\n", a, b);
}
int main()
{
	/*定义函数指针*/
	int(*fp)(int, int);
	//或者 int (*fp)(int x, int y);

	/*函数指针初始化*/
	fp = printMax;

	int a = 3, b = 4;
	/*通过函数指针调用它所指向的函数*/
	fp(a, b);
	//等价printMax(a,b)

	system("pause");
	return 0;
}
```

#### 1.4.4 回调函数

* 把**函数指针**作为**参数**传递给另一个函数，当这个指针被用来调用它所指向的函数时，我们就是这是回调函数

![img](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/4819cbcea9578c710141b2cbb9c4cc7f.jpeg)

举一个例子来看，1. 首先假设校长定义了成绩评定方式grade_judgement并且知道学生成绩grade

2. 那么库文件里面定义了一个comprehensive_grade函数计算了综合成绩并调用回调函数输出成绩评级
3. 这么写是因为：当成绩评定修改时，不用对库文件里面函数进行修改，而库文件也只要给出接口，保证各功能代码独立性

```c
/*这里类比库文件里面的库文件函数*/
#include <windows.h>

/*C语言-advanced练习头文件*/

extern char comprehensive_grade(int grade, char(*fp)(int))	//这里类比库文件中的内容
{
	/*这里类比库文件对输入成绩进行处理*/
	grade = grade*0.8 + 100 * 0.2;
	Sleep(100);
	/*调用回调函数*/
	return fp(grade);
}
```

```c
/*这里类比自己定义的主函数和回调函数*/

#include<stdio.h>
#include "c_Exercise.h"

/*定义的回调函数，判断成绩等级*/
char grade_judgement(int grade)
{
	if (grade >= 90)
		return 'A';
	else if (grade >= 70)
		return 'B';
	else if (grade >= 60)
		return 'C';
	else
		return 'N';
}

/*main program*/
int main()
{
	int grade;
	char judgement;
	printf("请输入你的成绩：\n");
	scanf("%d", &grade);
	judgement = comprehensive_grade(grade, grade_judgement);	//调用库文件，把函数指针作为参数
	printf("您的成绩评级为：%c\n", judgement);

	system("pause");
	return 0;
}
```

#### 1.4.5 函数指针数组

数组元素是函数指针的数组称为函数指针数组

定义、初始化和使用

```
返回类型说明符(*函数指针数组名[])(参数列表)={fp1/函数名1,...,fpn/函数名n};
函数指针数组名[下标](实参列表);
```

```c
//举例
int(*fp_array[])(int, int) = { add,sub,mul,div };	//定义和初始化
fp_array[n](a,b);	//使用
```



-------

## 2 C语言进阶

### 2.1 变量存储类型

#### 2.1.1 四种存储类型

* **全局变量**：从定义位置到文件末尾都有效

* **局部变量**：仅在函数中有效

* 且需要注意的是，全局变量和静态变量在**编译时**就存放在数据段，一直**只有一个地址**

<img src="https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231024202111183.png" alt="变量存储类型表格" style="zoom: 33%;" />

<img src="https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231025212704311.png" alt="image-20231025212704311" style="zoom:67%;" />

#### 2.1.2 四种存储类型在内存上的分配

* ***const***修饰全局变量存放在数据段，***const***修饰局部变量存放在栈
* C/C++在程序(exe)运行前分为全局区和代码区
* 代码区特点是共享和只读

![C程序内存分配](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231024221508374.png)

#### 2.1.3 static使用

从下面代码段可以看出，静态局部变量和局部变量区别，

* **static修饰局部变量增长了其生命周期**，其延长为了整个程序的生命周期；作用域不变

* static修饰全局变量或函数，则作用域为**当前文件**
* 有些只用于当前文件的函数可以使用static修饰（这样不同文件有同名函数不会互相干扰，且增强代码安全性）

```c

//全局变量，省略extern
int a = 3;
//静态全局变量
static int b = 4;

void variable(void)
{
	//局部变量,省略auto
	int c = 5;
	//静态局部变量
	static int d = 6;
	printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
	a++;
	b++;
	c++;
	d++;
}

int main()
{
	printf("第一次调用函数：\n");	//3,4,5,6
	variable();
	printf("第二次调用函数：\n");	//4,5,5,7
	variable();
	printf("第三次调用函数：\n");	//5,6,5,8
	variable();

	system("pause");
	return 0;
}
```

#### 2.1.4 extern使用

* extern修饰，可以在**当前文件和其他文件**使用
* extern常用于**多文件编程**，比如在**头文件中声明函数**`extern int  readpcv(const char *file, pcvs_t *pcvs);` 其可以**在*1.c*文件中定义**，**在main.c中include该头文件**，就可以避免所有函数都必须定义在同一个.c文件里
* 虽然声明函数默认extern，但是一般会再加上extern，为了表明当前文件中使用的函数被定义在别处。
* static和extern修饰变量和函数作用如下：

```c
# include<stdio.h>

/*可以在当前文件和其他文件使用，省略extern*/
int x = 10;
/*仅限当前文件使用*/
static int y = 10;
/*外部函数，可以在多个文件使用，extern可以省略，但一般会保留，提醒可以被外部调用*/
extern int a() 
{
	printf("a为外部函数");
}
/*内部函数，仅限于当前文件*/
static int b()
{
	/*存储类型为auto，局部变量*/
	int k = 1;
	/*静态局部变量，仅限当前函数使用，生命周期变长*/
	static int m = 2;
}
int main()
{
	system("pause");
	return 0;
}
```

* extern用来声明（声明不分配内存空间）

编译器遇到extern时： 从本文找外部变量定义-->没有找到，在**连接时**从其他文件找外部变量定义-->找不到按*error*处理



```c
//此处extern用来声明，因为变量定义在引用后面
extern int a, b;
int main()
{
	printf("a=%d\nb=%d\n", a, b);
	system("pause");
	return 0;
}
int a = 10, b = 1;
```

### 2.2 可变参数列表

例`int scanf(const char* format, ...);`中`"..."`为可变参数列表，可以用来接受个数和类型不确定的实参

> 有点没看懂视频，学完宏再看一遍

### 2.3 字符串进阶

#### 2.3.1 字符串和字符数组和字符指针

**字符数组**——存放字符的数组，字符数组中一个元素存放一个字符

```c
/*二维字符数组及其初始化*/
	char a[][10] = { "orange","apple","banana" };
```

**字符串**——以结束符'\0'为结尾的字符数组，C语言中没有专门的字符串变量

```c
//字符数组示例
int main()
{
	/*字符初始化字符数组*/
	char str1[] = { 'a','b','c','\0' };	//建议最后以'\0'结尾，方便输出
	/*字符串初始化*/
	char str2[] = "Hello";	//'\0'省略了，字符串实际以'\0'结尾-----------局部变量，存储在栈区
    /*结束符'\0'初始化*/
    char str3[30]={'\0'};	//这里有个易错点：str3实际只能存储29位，最后一位为'\0'
	printf("字符串%s的实际长度为：%d\n", str2, sizeof(str2));	//result:6
	printf("忽略'0'的字符串%s的长度为：%d\n", str2, strlen(str2));	//result:5

	system("pause");
	return 0;
}
```

**字符指针**——指向字符串的指针，被指向的字符串存放在**常量区**，不能修改

```c
char *pstr="C language";	//定义字符指针，存储在数据段常量区
```

```c
#include<stdio.h>
#include<string.h>

/*字符数组应用示例——计算输入语句中单词平均长度*/
int main()
{
	int letter = 0, word_count = 0, flag = 0;
	char input[30] = { '\0' };

	printf("Please input your sentence:");
	
	fgets(input, sizeof(input), stdin);
	printf("sizeof(input):%d,strlen(input):%d\n", sizeof(input), strlen(input));
	int n = sizeof(input);

	for (int i = 0; i < n; i++)
	{
		char ch = input[i];
		if (ch == '\n') break;
		//为空白或者水平制表符，将flag置为1
		if (ch == ' ' || ch == '\t')
			flag = 0;
		//计算单词个数，即前面为空白或水平制表符而后一位不是，并置回flag
		else if (!flag&&ch != ' '&&ch != '\t')
		{
			word_count++;
			flag = 1;
		}
			
		if (ch != ' '&&ch != '\t')
			letter++;
	}
	float word_average = (float)letter / word_count;	//输出别忘了转为浮点型
	printf("the average word of your sentence is:%f\n", word_average);

	system("pause");
	return 0;
}
```

#### 2.3.2 字符串处理函数

这里只是初步介绍，后面阅读RTKLIB源代码读取文件那里会详细归类，参考

(RTKLIB读取文件函数)[https://blog.csdn.net/weixin_60131151/article/details/129816887]

```c
//常用字符串处理<string.h>
//stdin、stdout为FILE*类型的指针
int strlen(char const *string);	//字符串长度，传入字符数组或字符指针
fgets(input, sizeof(input), stdin);	//存储字符串,实际fets读取进(sizeof(input)-1)个字符，最后一个为'\0'

/*des建议是字符数组，其他的可能初始化被保存在常量区，会发生段错误*/
char* strcpy(char* des,char* src);	//拷贝函数，'\0'也拷贝，返回新字符串地址，
char* strncpy(char* des,char* src,int size);	//加上size参数拷贝指定长度的字符串

char* strcat(const char* str1,const char* str2);	//连接函数，删除str1后面'\0'，连接上str2,返回str1地址
char* strncat(char* str1,const char* str2,int size);

int strcmp(const char* str1,const char* str2);	//比较函数，按照ASCII值比较，等于：0；大于:>0;小于:<0
int strncmp(const char* str1,const char* str2,int size);

char* strtok(char* str,const char* delimiters);//分割函数，将str通过deli分割成若干子字符串，返回分割出的子字符串/NULL

char* strchr(const char* str,int c)；	//查找字符，c为要查找的字符，返回指向该字符的指针/NULL
char* strrchr(const char* str,int c)；	//与上面函数区别在于从右向左匹配

char* strstr(const char* haystack,const char* needle);//查找字符串，needel为要查找的小字符串，返回指向ned的指针/NULL
```

```c
//使用strtok一些需要注意的事项
int main()
{
	char str[] = "hello:token:language:world\0";
	int count = 0;
	char* p = strtok(str, ":");
	/*此处要调用循环才能将str调用strtok不断分割*/
	while (p != NULL)
	{
		count++;
		printf("%s", p);
		p = strtok(str, ":");
	}
	system("pause");
	return 0;
}
```



#### 2.3.3 常见的C标准库函数

1. ***stdlib.h***中声明的整型算术、随机数函数和转换函数
2. ***math.h***中声明的数学公示函数
3. ***time.h***中声明的时间日期函数

### 2.4 结构体

#### 2.4.1 结构体介绍

* 结构体在使用之前需要**声明结构体**，一般声明在**头文件**中

* 结构体的使用需要定义对应的结构体变量及其初始化
* 结构体变量成员的引用方式`结构体变量.成员名`

```c
struct 结构体名
{
    类型说明符 成员名；//成员可以是基本数据类型或另一个构造类型
    ...
};	//记得加分号
/*定义结构体变量*/
struct 结构体名 变量名1,...,变量名n;
/*定义结构体并初始化*/
struct 结构体名 变量名1={成员值列表},...,
               变量名n={成员值列表};
```

* 结构体变量成员的赋值

```c
/*结构体赋值过程中需要注意的事项——成员为字符数组赋值*/
struct student
{
	int id;
	char name[30];
	char sex[10];
	int age;
};
int main()
{
	struct student stu1, stu2;
	stu1.id = 20200532;
	//stu1.name = "ZhangSan";	//这里会报错，原因是数组名是常量，常量不能被修改
	//stu1.sex = "female";
	strcpy(stu1.name, "ZhangSan");	//使用strcpy函数可以复制到字符数组里面
	strcpy(stu1.sex, "female");
	printf("id:%d,name:%s,sex:%s\n", stu1.id, stu1.name, stu1.sex);

	system("pause");
	return 0;
}
```

* 结构体的**嵌套**

可以将一个结构体放入另一个结构体之内，但结构体不能嵌套它自身，此处描述的是结构体

* 结构体**自引用**

在一个结构体内部包含指向该结构体本身的**指针**（事实上指向的是同一类型不同结构体变量）——常用于链表

* 结构体的**不完整声明**

为了解决不同结构体相互依赖的问题，声明一个作为结构体标签的标识符，用该标识符声明指向该结构体的指针

```c
struct B;	//不完整声明
struct A{
		 struct B *partner;
};
struct B{
		 struct A *partner;
};
```

#### 2.4.2 结构体数组和结构体指针

> **结构体数组**

* 元素为结构体类型的数组称为结构体数组
* 先声明结构体后定义结构体数组，例`struct 结构体名 数组名[长度]={{成员值列表},...,{成员值列表}};` 
* 结构体数组的引用方式`结构体数组名[下标].成员名`

> 结构体的字节大小，由其成员决定。
>
> 在实际应用中，会遇到**函数**里面需要传入**结构体变量**。由于**结构体所占用内存较大**，因此我们会选择传入其**结构体指针**，其只占四个字节，减少了时间和空间的开销

> **结构体指针**

* 结构体指针指向第一个结构体变量，结构体指针的定义及其初始化
* 结构体指针访问成员
* 结构体指针作为函数参数

```c
//结构体指针定义
struct 结构体名 *结构体指针变量名；
//结构体指针的初始化
结构体指针变量名=&结构体变量；
//访问成员
结构体指针->成员名;	
//结构体指针作为函数参数
void func(struct student *stu){..};
```

#### 2.4.3 结构体指针数组和指向结构体数组的指针

```c
int main()
{
	struct student stu1 = { 1,"ZhangSan","male",20 };
	struct student stu2 = { 2,"LiSi","male",22 };

	/*定义结构体数组并初始化*/
	struct student stu_array[] = { stu1,stu2 };	
	/*定义指向结构体数组的指针并初始化*/
	struct student *stu_arrayP = &stu_array;
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
```

#### 2.4.4 typedef和#define 类型定义符

简单来说以上两个关键字都是来起**别名的**,#define 无法正确处理指针类型，typedef更为合适

```c
/*typedef和#define区别举例*/
typedef char* ptr_char;
ptr_char a,b,c;	//a,b,c为指针
#define PTR_CHAR char*;
PTR_CHAR a,b,c;	//a为指针，b和c为char类型
```



> typedef——`typedef 原类型名 新类型名`
>
> 系统中有一个很常见的别名**size_t**是unsigned int(无符号整型)

```c
//typedef 举例
typedef struct student	//或typedef struct
{
	int id;
	char name[30];
	char sex[30];
	int age;
}Stu;
Stu stu1 = { 3,"Lin","female",22 };	//等同struct student stu1={...};
//定义结构体指针
typedef struct student *Stu_p;
```

> #define (宏定义)——预处理指令
>
> `#define 新类型名 原类型名`





## 4 关于一些待学待思考的问题

**4.1 怎么使用宏能方便删除和增加声明在头文件的全局变量**

这里还需要后面学了宏后再琢磨琢磨

[C语言在头文件定义全局变量的技巧-CSDN博客](https://blog.csdn.net/a1598025967/article/details/105876724)

* scanf不能输入空格，我们可以调用stdin存储输入值
* 

-------

[^温馨提示]:本文档图片存储在github图床，需能访问github才能查看图片
