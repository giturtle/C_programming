#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//写一函数建立一个有3名学生数据的动态链表
#define LEN sizeof(struct Student)
struct Student {
	long num;
	float score;
	struct Student *next;
};
struct Student *Func() {
	struct Student *head;
	struct Student *p1,*p2;
	static int n = 0;
	p1 = p2 = (struct Student*)malloc(LEN);
	scanf("%ld %f", &p1->num, &p1->score);
	head = NULL;
	while (p1->num != 0) {
		n++;
		if (n == 1) {
			head = p1;
		}
		else {
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct Student*)malloc(LEN);
		scanf("%ld %f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return head;
}

int main() {
	struct Student *p;
	p = Func();		//函数返回链表第一个结点的地址
	printf("\nnum:%ld\nscore:%5.1f\n", p->num, p->score);		//输出第一个结点的成员值
	system("pause");
	return 0;
}



//链表输出学生信息
struct Student {
	int num;
	double score;
	struct Student *next;
};
int main() {
	struct Student a, b, c, *head, *p;
	a.num = 10101; a.score = 89.5;
	b.num = 10103; b.score = 90;
	c.num = 10105; c.score = 85;
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	p = head;
	do {
		printf("%d %5.1lf\n", p->num, p->score);
		p = p->next;
	} while (p != NULL);
	system("pause");
	return 0;
}