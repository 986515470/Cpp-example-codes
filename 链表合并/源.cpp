#include <stdio.h>
#include <stdlib.h>

typedef struct student {//链表结点
	int ID;
	int score;
	struct student* next;//前指向
	struct student* back;//后指向
} Stu;

typedef struct _list {
	struct student* head1;//表头指针
	struct student* tail1;//表尾指针
	struct student* head2;
	struct student* tail2;
} List;


void creat_a_link(List* pList, int N);//创建a链表
void creat_b_link(List* pList, int N);//创建b链表
void connect_link(List* paList);//链接链表
void sort_link(List* paList);//排序链表

int main() {
	List list;
	list.head1 = list.tail1 = list.head2 = list.tail2 = NULL;
	int N, M;
	scanf("%d%d", &N, &M);//属于A/B两个链表元素的数量；
	creat_a_link(&list, N);
	creat_b_link(&list, M);
	connect_link(&list);
	sort_link(&list);
	return 0;
}
/* 创建a链表 */
void creat_a_link(List* pList, int N) {
	int num, score;
	if (!N) {
		printf("can not creat empty list\n");
	}
	Stu* p = (Stu*)malloc(sizeof(Stu));//申请空间
	scanf("%d%d", &num, &score);
	p->ID = num;
	p->score = score;
	p->next = NULL;
	p->back = NULL;
	pList->head1 = p;
	pList->tail1 = pList->head1;
	while (--N) {
		Stu* q = (Stu*)malloc(sizeof(Stu));
		scanf("%d%d", &num, &score);
		q->ID = num;
		q->score = score;
		q->next = NULL;
		q->back = pList->tail1;
		pList->tail1->next = q;
		pList->tail1 = q;
	}
}
/* 创建b链表 */
void creat_b_link(List* pList, int N) {
	int num, score;
	if (!N) {
		printf("can not creat empty list\n");
	}
	Stu* p = (Stu*)malloc(sizeof(Stu));//申请空间
	scanf("%d%d", &num, &score);
	p->ID = num;
	p->score = score;
	p->next = NULL;
	p->back = NULL;
	pList->head2 = p;
	pList->tail2 = pList->head2;
	while (--N) {
		Stu* q = (Stu*)malloc(sizeof(Stu));
		scanf("%d%d", &num, &score);
		q->ID = num;
		q->score = score;
		q->next = NULL;
		q->back = pList->tail2;
		pList->tail2->next = q;
		pList->tail2 = q;
	}
}
/* 链接a,b链表 *///合并的后链表的头为lista.head,尾为listb.tail
void connect_link(List* pList) {
	Stu* p;
	for (p = pList->head2; p; p = p->next) {
		pList->tail1->next = p;
		p->back = pList->tail1;
		pList->tail1 = p;
	}
}
/* 排序列表 */
void sort_link(List* pList) {
	int temp = 0;
	Stu* p;
	Stu* q;
	/* 先对链表进行排序 */
	for (p = pList->head1; p; p = p->next) {
		for (q = p->next; q; q = q->next) {
			/* printf("%d %d", p->ID, q->ID); */
			if (p->ID > q->ID) { //换数据
				temp = q->ID;
				q->ID = p->ID;
				p->ID = temp;
				temp = q->score;
				q->score = p->score;
				p->score = temp;
			}
		}
	}
	for (p = pList->head1; p; p = p->next) {
		printf("%d %d\n", p->ID, p->score);
	}
}