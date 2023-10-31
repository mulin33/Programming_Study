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

//struct student *stu_array[] = { &stu1,&stu2 };
