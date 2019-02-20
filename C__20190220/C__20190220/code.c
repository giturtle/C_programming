#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//13个人围成一圈，从第一个人开始顺序报号123，凡报到3者退出圈子，找出最后留在圈子中的人原来的序号，要求用链表实现
int main() {
	struct king {
		int data;
		struct king *next;
	};
	int i, m, n;
	scanf("%d %d", &n, &m);	//m:人数 n:报号数
	struct king *p, *head, *t;
	head = (struct king*)malloc(sizeof(struct king));
	head->next = NULL;
	head->data = 1;
	p = head;	 //循环链表
	for (i = 2; i <= n; i++){
		t = (struct king*)malloc(sizeof(struct king));
		t->data = i;
		t->next = NULL;
		p->next = t;
		p = p->next;
	}
	p->next = head;		//循环链表
	p = head;		 //删除链表
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
	printf("\n最后生存者:%d号\n", p->data);
	system("pause");
	return 0;
}



//写一个函数insert，用来向一个动态链表插入结点

//方法一
struct node{
	int data;
	struct node *next;
};
struct node *insert(struct node *head, struct node *p){	//将p指向的结点插入链表，并使链表保持有序 
	struct node *p1, *p2;
	if (head == NULL){	//如果原链表为空 
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
		if (head == p1)		//插在链表首部 
			head = p;
		else
			p2->next = p1;	//插在链表中间 
	}
	else{
		p1->next = p;		//插在链表尾结点之后 
		p->next = NULL;
	}
	return head;
}


//方法二
struct student{
	long num;
	float score;
	struct student *next;
};
int n;
struct student *insert(struct student *head, struct student *stud){
	struct student *p0, *p1, *p2;
	p1 = head;                          //使p1指向第一个结点
	p0 = stud;                          //指向要插入的结点
	if (head == NULL){                    //原来的链表是空表
		head = p0; p0->next = NULL;
	}          //使p0指向的结点作为头结点
	else{
		while ((p0->num > p1->num) && (p1->next != NULL)){
			p2 = p1;                           //使ｐ２指向刚才p１指向的结点
			p1 = p1->next;
		}                    //p1后移一个结点
		if (p0->num <= p1->num){
			if (head == p1) head = p0;           //插到原来第一个结点之前
			else p2->next = p0;               //插到p2指向的结点之后 
			p0->next = p1;
		}
		else{
			p1->next = p0;
			p0->next = NULL;                  //插到最后的结点之后
		}
	}
	n++;                         //结点数加１
	return (head);
}



//有3个学生，每个学生的数据包括学号、姓名、3门成绩，键入3个学生数据
//要求输出3门课程的总平均成绩，以及最高分学生的数据
#define S 3
struct Stu {
	int id;
	char name[1024];
	double score[3];
	double average;
}stu[3];

void input(struct Stu stu[]) {
	printf("请输入%d名学生的数据:\n", S);
	for (int i = 0; i < S; ++i) {
		scanf("%d %s %lf %lf %lf", &stu[i].id, stu[i].name,
			&stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
	}
}
void avg(struct Stu stu[]) {
	for (int i = 0; i < S; ++i) {
		stu[i].average = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
		printf("%s", stu[i].name);
		printf("的平均成绩为:%7.2lf\n", stu[i].average);
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
	printf("\n\n最高分成绩学生为%s\t他的3门成绩为:%7.2lf%7.2lf%7.2lf\n", stu[0].name,
		stu[0].score[0], stu[0].score[1], stu[0].score[2]);
}

int main() {
	input(stu);
	avg(stu);
	MaxScore(stu);
	system("pause");
	return 0;
}



//在上一题基础上，编写一个input函数输入2个学生的数据记录
struct Student {
	int num;
	char name[1024];
	double score[3];
}stu[2];
void input(struct Student *p) {
	for (int i = 0; i < 2; ++i) {
		printf("输入第%d位学生的信息:\n", i + 1);
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



//编写一个函数print,打印一个学生的成绩数组，该数组中有2个学生的数据记录，每个记录包括num，name，score[3]
//用主函数输入记录，用print函数输出
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
		printf("输入第%d位学生的信息:\n", i+1);
		scanf("%d %s %lf %lf %lf", &stu[i].num, stu[i].name,
			&stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
	}
	print(stu);
	system("pause");
	return 0;
}



//写一个函数days，实现上一题的计算，由主函数将年月日传递给days函数，计算后将日子数传回主函数输出
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
	printf("请输入年月日:\n");
	scanf("%d %d %d",&p->year, &p->month, &p->date);
	printf("%d\n",Func(p));
	system("pause");
	return 0;
}



//定义一个结构体变量，包括年月日，计算该日在本年中是第几天
struct Day{
	int year;
	int month;
	int date;
}day;
int main() {
	int count = 0;
	int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	printf("请输入年月日:\n");
	scanf("%d %d %d", &day.year, &day.month, &day.date);
	count += day.date;
	for (int i = 0; i < day.month; ++i) {
		count += arr[i];
	}
	if (((day.year % 4 == 0) && (day.year % 100 != 0)) || (day.year % 400 == 0)) {
			count++;
	}
	printf("%d年%d月%d日是该年的第%d天.\n", day.year, day.month, day.date, count);
	system("pause");
	return 0;
}



//口袋中有红、黄、蓝、白、黑五种颜色的球若干，每次从口袋中先后取出3个球
//问得到的3种不同颜色的球的可能取法，输出每种排列的情况
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
	printf("\n共有%d种情况!\n",n);
	system("pause");
	return 0;
}




//有若干人员的数据，其中有学生和教师。学生的数据包括：姓名、号码、性别、职业、班级
//教师数据包括：姓名、号码、性别、职业、职务，要求用同一个表格来处理，假设2 人
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
		printf("请输入信息:\n");
		scanf("%d %s %c %c", &person[i].num, person[i].name, &person[i].sex, &person[i].job);
		if (person[i].job == 's') {		//学生
			scanf("%d", &person[i].u.class);
		}
		else if (person[i].job == 't') {	//老师
			scanf("%s", person[i].u.zhiwu);
		}
		else {
			printf("输入错误!\n");
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



//编写一个 <输出链表> 的函数print
#define LEN sizeof(struct Student)
struct Student {
	long num;
	float score;
	struct Student *next;
};
void print(struct Student *head) {
	struct Student *p;
	printf("\n现在有%d条数据记录.\n", n);
	p = head;
	if (head != NULL) {
		do {
			printf("%ld %5.1lf\n", p->num, p->score);
			p = p->next;		//将p原来所指向的结点中next的值赋给p，使p指向下一个结点
		} while (p != NULL);
	}
}
