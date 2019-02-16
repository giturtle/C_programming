#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//有n个结构体变量，内含学生学号、姓名和3门课程的成绩，要求输出平均成绩最高的学生的信息
#define N 3
typedef struct Student {
	int num;
	char name[1024];
	double score[3];
	double average;
}S;
void input(S stu[]) {
	int i;
	printf("请输入各个学生的信息：\n");
	for (i = 0; i < N; ++i) {
		scanf("%d %s %lf %lf %lf",
			&stu[i].num, stu[i].name,
			&stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		stu[i].average = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
	}
}
S Max(S stu[]) {
	int i, m = 0;
	for (i = 0; i < N; ++i) {
		if (stu[i].average > stu[m].average) {
			m = i;
		}
	}
	return stu[m];
}
void print(S student) {
	printf("\n成绩最高的学生是:\n");
	printf("学号:%d\n姓名:%s\n三门课成绩为:%5.1lf,%5.1lf,%5.1lf\n平均成绩为:%5.1lf\n",
		student.num,student.name,student.score[0], student.score[1], student.score[2], student.average);
}

int main() {
	S stu[N], *p = stu;
	input(stu);
	print(Max(stu));
	system("pause");
	return 0;
}



//通过指向结构体变量的指针变量输出结构体变量中成员的信息
int main() {
	struct Stu {
		long num;
		char name[1024];
		char sex;
		double score;
	};
	struct Stu stu;
	struct Stu *p;
	p = &stu;
	stu.num = 100;
	strcpy(stu.name, "bob");
	stu.sex = 'M';
	stu.score = 90.5;
	printf("No.:%ld\nname:%s\nsex:%c\nscore:%5.1lf\n", stu.num, stu.name, stu.sex, stu.score);
	printf("\n");
	printf("No.:%ld\nname:%s\nsex:%c\nscore:%5.1lf\n", p->num, p->name, p->sex, p->score);
	system("pause");
	return 0;
}



//有5个学生的信息，学号姓名成绩，要求按照成绩的高低顺序输出各个学生的信息
struct Student {
	int id;
	char name[1024];
	double score;
};
int main() {
	struct Student stu[5] = { {1,"bob",95.7},{2,"bot",98.3},{3,"tom",90.9},{4,"mary",40.9},{5,"jobs",100} };
	struct Student temp;
	for (int i = 0; i < 5; ++i) {
		for (int j = 4; j > i; --j) {
			if (stu[j - 1].score < stu[j].score) {
				temp = stu[j - 1];
				stu[j - 1] = stu[j];
				stu[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; ++i) {
		printf("%5s:%d,%6.2lf分\n", stu[i].name, stu[i].id, stu[i].score);
	}
	system("pause");
	return 0;
}



//有三个候选人，5个选民每个选民只能投票选一人，要求编一个统计选票的程序，先后输入被选人的名字，最后输出个人得票结果
#define VOTER 5		//选民个数
struct Person {
	char name[1024];
	int vote;
}candidate[3] = { {"Li",0},{"Zhang",0},{"Lu",0} };
int main() {
	int i, j;
	char name[20];
	for (i = 1; i <= VOTER; ++i) {
		scanf("%s", name);
		for (j = 0; j < 3; ++j) {
			if (strcmp(name, candidate[j].name) == 0) {
				candidate[j].vote++;
			}
		}
	}
	printf("结果为:\n");
	for (i = 0; i < 3; ++i) {
		printf("%5s:%d votes\n", candidate[i].name, candidate[i].vote);
	}
	system("pause");
	return 0;
}



int main() {
	typedef struct Student {
		int id;
		char name[1024];
		double score;
	}Stu;
	Stu student1, student2;
	printf("请输入学生一的信息:\n");
	scanf("%d %s %lf", &student1.id, student1.name, &student1.score);
	printf("请输入学生二的信息:\n");
	scanf("%d %s %lf", &student2.id, student2.name, &student2.score);
	if (student1.score > student2.score) {
		printf("%d\n%s\n%6.2lf\n", student1.id, student1.name, student1.score);
	}
	else if (student1.score < student2.score) {
		printf("%d\n%s\n%6.2lf\n", student2.id, student2.name, student2.score);
	}
	else {
		printf("%d\n%s\n%6.2lf\n", student1.id, student1.name, student1.score);
		printf("%d\n%s\n%6.2lf\n", student2.id, student2.name, student2.score);
	}
	system("pause");
	return 0;
}