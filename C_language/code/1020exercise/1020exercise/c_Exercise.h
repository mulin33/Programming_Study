#include <windows.h>

/*C����-advanced��ϰͷ�ļ�*/

extern char comprehensive_grade(int grade, char(*fp)(int))	//������ȿ��ļ��е�����
{
	/*������ȿ��ļ�������ɼ����д���*/
	grade = grade*0.8 + 100 * 0.2;
	Sleep(100);
	/*���ûص�����*/
	return fp(grade);
}

//struct student *stu_array[] = { &stu1,&stu2 };
