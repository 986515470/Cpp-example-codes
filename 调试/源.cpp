#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//创建stu类型变量 包括学号、姓名、数学, 英语, 语文的成绩
typedef struct student 
{
	char number[20];
	char name[50];
	float score1,score2,score3;
	struct student* uuu;
}stu;
//创建链表
int iCount;
stu* Create() 
{
	stu* a = NULL, * b, * c;
	c = b = (stu*)malloc(sizeof(stu));
	scanf("%s%s%f%f%f", c->number, c->name, &c->score1, &c->score2, &c->score3);
	while (strcmp(c->number, "0") != 0)
	{
		iCount++;
		if (iCount == 1)
		{
			c->uuu = a;
			b = c;
			a = c;
		}
		else
		{
			c->uuu = NULL;
			b->uuu = c;
			b = c;
		}
		c = (stu*)malloc(sizeof(stu));
		scanf("%s%s%f%f%f", c->number, c->name, &c->score1, &c->score2, &c->score3);
	}
	free(c);
	return a;
}
int main()
{
	int j = 1;
	char number[20]; stu* p;
	p = Create();
	scanf("%s", number);
	while (p->uuu != NULL)
	{
		p = p->uuu;
		if (strcmp(p->number, number) == 0)
		{
			printf("%s %s %0.1f %0.1f %0.1f", p->number, p->name, p->score1, p->score2, p->score3); j = 0;
		}
	}
	if (j == 1) printf("No such person");
	free(p);
	return 0;
}