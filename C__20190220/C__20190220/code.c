#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//13����Χ��һȦ���ӵ�һ���˿�ʼ˳�򱨺�123��������3���˳�Ȧ�ӣ��ҳ��������Ȧ���е���ԭ������ţ�Ҫ��������ʵ��
int main() {
	struct king {
		int data;
		struct king *next;
	};
	int i, m, n;
	scanf("%d %d", &n, &m);	//m:���� n:������
	struct king *p, *head, *t;
	head = (struct king*)malloc(sizeof(struct king));
	head->next = NULL;
	head->data = 1;
	p = head;	 //ѭ������
	for (i = 2; i <= n; i++){
		t = (struct king*)malloc(sizeof(struct king));
		t->data = i;
		t->next = NULL;
		p->next = t;
		p = p->next;
	}
	p->next = head;		//ѭ������
	p = head;		 //ɾ������
	while (p->next != p){
		for (i = 1; i < m - 1; i++) {
			p = p->next;
		}
		struct king *tmp;
		tmp = p->next;
		p->next = p->next->next;
		p = tmp->next;
		free(tmp);
	}
	printf("\n���������:%d��\n", p->data);
	system("pause");
	return 0;
}



//дһ������insert��������һ����̬���������

//����һ
struct node{
	int data;
	struct node *next;
};
struct node *insert(struct node *head, struct node *p){	//��pָ��Ľ�����������ʹ���������� 
	struct node *p1, *p2;
	if (head == NULL){	//���ԭ����Ϊ�� 
		head = p;
		p->next = NULL;
		return head;
	}
	p2 = p1 = head;
	while ((p->data) > (p1->data) && (p1->next != NULL)){
		p2 = p1;
		p1 = p1->next;
	}
	if ((p->data) <= (p1->data)){
		p->next = p1;
		if (head == p1)		//���������ײ� 
			head = p;
		else
			p2->next = p1;	//���������м� 
	}
	else{
		p1->next = p;		//��������β���֮�� 
		p->next = NULL;
	}
	return head;
}


//������
struct student{
	long num;
	float score;
	struct student *next;
};
int n;
struct student *insert(struct student *head, struct student *stud){
	struct student *p0, *p1, *p2;
	p1 = head;                          //ʹp1ָ���һ�����
	p0 = stud;                          //ָ��Ҫ����Ľ��
	if (head == NULL){                    //ԭ���������ǿձ�
		head = p0; p0->next = NULL;
	}          //ʹp0ָ��Ľ����Ϊͷ���
	else{
		while ((p0->num > p1->num) && (p1->next != NULL)){
			p2 = p1;                           //ʹ��ָ��ղ�p��ָ��Ľ��
			p1 = p1->next;
		}                    //p1����һ�����
		if (p0->num <= p1->num){
			if (head == p1) head = p0;           //�嵽ԭ����һ�����֮ǰ
			else p2->next = p0;               //�嵽p2ָ��Ľ��֮�� 
			p0->next = p1;
		}
		else{
			p1->next = p0;
			p0->next = NULL;                  //�嵽���Ľ��֮��
		}
	}
	n++;                         //������ӣ�
	return (head);
}



//��3��ѧ����ÿ��ѧ�������ݰ���ѧ�š�������3�ųɼ�������3��ѧ������
//Ҫ�����3�ſγ̵���ƽ���ɼ����Լ���߷�ѧ��������
#define S 3
struct Stu {
	int id;
	char name[1024];
	double score[3];
	double average;
}stu[3];

void input(struct Stu stu[]) {
	printf("������%d��ѧ��������:\n", S);
	for (int i = 0; i < S; ++i) {
		scanf("%d %s %lf %lf %lf", &stu[i].id, stu[i].name,
			&stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
	}
}
void avg(struct Stu stu[]) {
	for (int i = 0; i < S; ++i) {
		stu[i].average = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
		printf("%s", stu[i].name);
		printf("��ƽ���ɼ�Ϊ:%7.2lf\n", stu[i].average);
	}
}
void MaxScore(struct Stu stu[]) {
	struct Stu temp;
	for (int i = 0; i < S; ++i) {
		for (int j = S - 1; j > i; --j) {
			if (stu[j - 1].average < stu[j].average) {
				temp = stu[j - 1];
				stu[j - 1] = stu[j];
				stu[j] = temp;
			}
		}
	}
	printf("\n\n��߷ֳɼ�ѧ��Ϊ%s\t����3�ųɼ�Ϊ:%7.2lf%7.2lf%7.2lf\n", stu[0].name,
		stu[0].score[0], stu[0].score[1], stu[0].score[2]);
}

int main() {
	input(stu);
	avg(stu);
	MaxScore(stu);
	system("pause");
	return 0;
}



//����һ������ϣ���дһ��input��������2��ѧ�������ݼ�¼
struct Student {
	int num;
	char name[1024];
	double score[3];
}stu[2];
void input(struct Student *p) {
	for (int i = 0; i < 2; ++i) {
		printf("�����%dλѧ������Ϣ:\n", i + 1);
		scanf("%d %s %lf %lf %lf", &stu[i].num, stu[i].name,
			&stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
	}
}
void print(struct Student *p){
	for (int i = 0;i < 2; ++i) {
		printf("%-4d%-8s%-7.2lf%-7.2lf%-7.2lf\n", p->num, p->name, p->score[0], p->score[1], p->score[2]);
		p++;
	}
}
int main() {
	input(stu);
	print(stu);
	system("pause");
	return 0;
}



//��дһ������print,��ӡһ��ѧ���ĳɼ����飬����������2��ѧ�������ݼ�¼��ÿ����¼����num��name��score[3]
//�������������¼����print�������
struct Student {
	int num;
	char name[1024];
	double score[3];
}stu[2];
void print(struct Student *p){
	for (int i = 0;i < 2; ++i) {
		printf("%-4d%-8s%-7.2lf%-7.2lf%-7.2lf\n", p->num, p->name, p->score[0], p->score[1], p->score[2]);
		p++;
	}
}
int main() {
	for (int i = 0; i < 2; ++i) {
		printf("�����%dλѧ������Ϣ:\n", i+1);
		scanf("%d %s %lf %lf %lf", &stu[i].num, stu[i].name,
			&stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
	}
	print(stu);
	system("pause");
	return 0;
}



//дһ������days��ʵ����һ��ļ��㣬���������������մ��ݸ�days������������������������������
struct Day{
	int year;
	int month;
	int date;
}day;
int Func(struct Day *day) {
	int count = 0;
	int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	count += day->date;
	for (int i = 0; i < day->month; ++i) {
		count += arr[i];
	}
	if (((day->year % 4 == 0) && (day->year % 100 != 0)) || (day->year % 400 == 0)) {
		count++;
	}
	return count;
}
int main() {
	struct Day d;
	struct Day* p = &d;
	printf("������������:\n");
	scanf("%d %d %d",&p->year, &p->month, &p->date);
	printf("%d\n",Func(p));
	system("pause");
	return 0;
}



//����һ���ṹ����������������գ���������ڱ������ǵڼ���
struct Day{
	int year;
	int month;
	int date;
}day;
int main() {
	int count = 0;
	int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	printf("������������:\n");
	scanf("%d %d %d", &day.year, &day.month, &day.date);
	count += day.date;
	for (int i = 0; i < day.month; ++i) {
		count += arr[i];
	}
	if (((day.year % 4 == 0) && (day.year % 100 != 0)) || (day.year % 400 == 0)) {
			count++;
	}
	printf("%d��%d��%d���Ǹ���ĵ�%d��.\n", day.year, day.month, day.date, count);
	system("pause");
	return 0;
}



//�ڴ����к졢�ơ������ס���������ɫ�������ɣ�ÿ�δӿڴ����Ⱥ�ȡ��3����
//�ʵõ���3�ֲ�ͬ��ɫ����Ŀ���ȡ�������ÿ�����е����
int main() {
	enum Color{
		red,
		yellow,
		blue,
		white,
		black
	};
	enum Color i, j, k, pri;
	int n = 0, loop;
	for (i = red; i <= black; ++i) {
		for (j = red; j <= black; ++j) {
			if (i != j) {
				for (k = red; k <= black; ++k) {
					if ((k != i) && (k != j)) {
						n++;
						printf("%-4d", n);
						for (loop = 1; loop <= 3; ++loop) {
							switch (loop) {
							case 1:pri = i; break;
							case 2:pri = j; break;
							case 3:pri = k; break;
							default:break;
							}
							switch (pri) {
							case red:printf("%-10s", "red"); break;
							case yellow:printf("%-10s", "yellow"); break;
							case blue:printf("%-10s", "blue"); break;
							case white:printf("%-10s", "white"); break;
							case black:printf("%-10s", "black"); break;
							default:break;
							}
						}
						printf("\n");
					}
				}
			}
		}
	}
	printf("\n����%d�����!\n",n);
	system("pause");
	return 0;
}




//��������Ա�����ݣ�������ѧ���ͽ�ʦ��ѧ�������ݰ��������������롢�Ա�ְҵ���༶
//��ʦ���ݰ��������������롢�Ա�ְҵ��ְ��Ҫ����ͬһ���������������2 ��
struct {
	int num;
	char name[10];
	char sex;
	char job;
	union {
		int class;
		char zhiwu[10];
	}u;
}person[2];
int main() {
	int i;
	for (i = 0; i < 2; ++i) {
		printf("��������Ϣ:\n");
		scanf("%d %s %c %c", &person[i].num, person[i].name, &person[i].sex, &person[i].job);
		if (person[i].job == 's') {		//ѧ��
			scanf("%d", &person[i].u.class);
		}
		else if (person[i].job == 't') {	//��ʦ
			scanf("%s", person[i].u.zhiwu);
		}
		else {
			printf("�������!\n");
		}
	}
	printf("\n");
	for (i = 0; i < 2; ++i) {
		if (person[i].job == 's') {
			printf("%-6d%-3s%-4c%-4c%-10d\n", person[i].num, person[i].name, person[i].sex,
				person[i].job, person[i].u.class);
		}
		else {
			printf("%-6d%-3s%-4c%-4c%-10s\n", person[i].num, person[i].name, person[i].sex,
				person[i].job, person[i].u.zhiwu);
		}
	}
	system("pause");
	return 0;
}



//��дһ�� <�������> �ĺ���print
#define LEN sizeof(struct Student)
struct Student {
	long num;
	float score;
	struct Student *next;
};
void print(struct Student *head) {
	struct Student *p;
	printf("\n������%d�����ݼ�¼.\n", n);
	p = head;
	if (head != NULL) {
		do {
			printf("%ld %5.1lf\n", p->num, p->score);
			p = p->next;		//��pԭ����ָ��Ľ����next��ֵ����p��ʹpָ����һ�����
		} while (p != NULL);
	}
}
