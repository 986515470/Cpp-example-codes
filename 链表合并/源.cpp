#include <stdio.h>
#include <stdlib.h>

typedef struct student {//������
	int ID;
	int score;
	struct student* next;//ǰָ��
	struct student* back;//��ָ��
} Stu;

typedef struct _list {
	struct student* head1;//��ͷָ��
	struct student* tail1;//��βָ��
	struct student* head2;
	struct student* tail2;
} List;


void creat_a_link(List* pList, int N);//����a����
void creat_b_link(List* pList, int N);//����b����
void connect_link(List* paList);//��������
void sort_link(List* paList);//��������

int main() {
	List list;
	list.head1 = list.tail1 = list.head2 = list.tail2 = NULL;
	int N, M;
	scanf("%d%d", &N, &M);//����A/B��������Ԫ�ص�������
	creat_a_link(&list, N);
	creat_b_link(&list, M);
	connect_link(&list);
	sort_link(&list);
	return 0;
}
/* ����a���� */
void creat_a_link(List* pList, int N) {
	int num, score;
	if (!N) {
		printf("can not creat empty list\n");
	}
	Stu* p = (Stu*)malloc(sizeof(Stu));//����ռ�
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
/* ����b���� */
void creat_b_link(List* pList, int N) {
	int num, score;
	if (!N) {
		printf("can not creat empty list\n");
	}
	Stu* p = (Stu*)malloc(sizeof(Stu));//����ռ�
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
/* ����a,b���� *///�ϲ��ĺ������ͷΪlista.head,βΪlistb.tail
void connect_link(List* pList) {
	Stu* p;
	for (p = pList->head2; p; p = p->next) {
		pList->tail1->next = p;
		p->back = pList->tail1;
		pList->tail1 = p;
	}
}
/* �����б� */
void sort_link(List* pList) {
	int temp = 0;
	Stu* p;
	Stu* q;
	/* �ȶ������������ */
	for (p = pList->head1; p; p = p->next) {
		for (q = p->next; q; q = q->next) {
			/* printf("%d %d", p->ID, q->ID); */
			if (p->ID > q->ID) { //������
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