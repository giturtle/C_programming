#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//编写一个函数print，打印一个学生的成绩数组，该数组有5个学生的数据记录
//每个记录包括num、name、score[3]，用主函数输入这些记录，用print函数输出这些记录
#define N 5

struct student {
	char num[6];
	char name[100];
	double score[3];
}stu[N];

void print(struct student *stu) {
	int i, j;
	printf("\n NO.  name  score1  score2  score3\n");
	for (i = 0; i < N; i++) {
		printf("%3s%6s", stu[i].num, stu[i].name);
		for (j = 0; j < 3; j++) {
			printf("%8.2lf", stu[i].score[j]);
		}
		printf("\n");
	}
}

int main() {
	int i, j;
	for (i = 0; i < N; i++) {
		printf("请输入第%d个学生的学号，姓名\n", i + 1);
		scanf("%s %s", &stu[i].num, &stu[i].name);
		printf("请输入该学生的三门成绩：\n\n");
		for (j = 0; j < 3; j++) {
			printf("第%d门成绩：\n", j + 1);
			scanf("%lf", &stu[i].score[j]);
		}
		printf("\n");
		print(stu);
	}
	system("pause");
	return 0;
}


//显示工资表
struct staff {
	char name[20];
	int salary;
};
main() {
	struct staff *p;
	struct staff teacher[3] = {
		{"Xu",900},
		{"Lu",800},
		{"Mao",200}
	};
	for (p = teacher; p < teacher + 3; p++) {
		printf("%s的工资是%d元\n", p->name, p->salary);
	}
	system("pause");
	return 0;
}


//显示某人工资信息的程序如下，分析显示结果
main() {
	struct staff {
		char name[20];
		char department[20];
		int salary;
	};
	struct staff w1, *p;
	p = &w1;
	strcpy(w1.name, "Li-Li");//个人信息
	strcpy((*p).department, "part1");
	p->salary = 1000;
	printf("%s，%s，%d\n", w1.name,w1.department,w1.salary);
	printf("%s，%s，%d\n", (*p).name,(*p).department,(*p).salary);
	printf("%s，%s，%d\n", p ->name,p ->department,p ->salary);
	//三者输出都为 Li-Li，part，11000
	//这就是通过不同成员访问方式传参，结构体变量传参/结构体指针传参
	system("pause");
	return 0;
}


//建立10名学生的信息表，每个学生的数据包括学号、姓名及一门课的成绩。
//要求从键盘输入这10名学生的信息，并按照每一行显示一名学生信息的形式显示出来
#define student 3
typedef struct Student {
	int sn;
	char name[100];
	double score;
}Stu;
int main(){
	Stu s[10];
	int i = 1;
	for (; i <= student; i++) {
		printf("请输入%d号学生的学号，姓名，单科成绩：\n",i);
		scanf("%d %s %lf", &s[i].sn, &s[i].name, &s[i].score);
	}
	printf("\n");
	for (i = 1; i <= student; i++) {
		printf("第%d号学生的学号，姓名，单科成绩为：\n", i);
		printf("%d %s %5.2lf\n", s[i].sn, s[i].name, s[i].score);
	}
	system("pause");
	return 0;
}


//建立一个学生的简单信息表，其中包括学号、年龄、性别及一门课的成绩
//要求从键盘为此学生信息输入数据，并显示出来
//一个信息表可以由结构体来定义，表中的内容可以通过结构体中的成员来表示
struct Student {
	int sn;
	char gender;
	int age;
	double score;
}Stu;
int main() {
	printf("请输入学生的学号，性别，年龄，单科成绩:\n");
	printf("（性别：'1'代表男，'2'代表女）\n");
	scanf("%d %c %d %lf", &Stu.sn, &Stu.gender, &Stu.age, &Stu.score);
	printf("该学生的学号为：%d\n", Stu.sn);
	if (Stu.gender == '1') {
		printf("该学生的性别为：男\n");
	}
	else {
		printf("该学生的性别为：女\n");
	}
	printf("该学生的年龄为：%d\n", Stu.age);
	printf("该学生的单科成绩为：%5.2lf\n", Stu.score);
	system("pause");
	return 0;
}


int main() {
	short num = 32767;
	short int a = num + 1;
	printf("%d\n", a);
	system("pause");
	return 0;
	//0111 1111 1111 1111 -> 1000 0000 0000 0000 
	//(系统直接识别为最小值，不进行解码)
}