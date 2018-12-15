#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//定义枚举类型 money ,用枚举元素代表人民币的面值
//人民币面值包括1/2/5分 , 1/2/5角 , 1/2/5/10/20/50/100元
enum money {
	fen1,fen2,fen5,
	jiao1,jiao2,jiao5,
	yuan1,yuan2,yuan5,yuan10,yuan20,yuan50,yuan100
};

//有一个unsigned long 类型整数,分别将其前 2 个字节和后 2 个字节 ->
//  -> 作为两个unsigned int类型整数输出
//设一个int型整数占 2 个字节
int main() {
	union {
		unsigned long k;
		unsigned a[2];
	}u;
	u.k = 0xef3d6ab9;
	//这个语句后面还需要思考
	printf("%x,%x\n", u.a[0], u.a[1]);
	system("pause");
	return 0;
}


//定义一个包括年月日成员的结构体变量,将其转换成这一年的第几天并输出
//应注意闰年的二月有29天,表达式"(year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))"
//的值为真,即为闰年,其中year表示年号
int main() {
	struct hehe{
		unsigned year, month, day;
	}x;
	int maxday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, n = 0;
	do {
		printf("请输入年 月 日:\n");
		scanf("%d %d %d", &x.year, &x.month, &x.day);
		if (x.month == 2) {
			if (x.year % 4 == 0 && x.year % 100 != 0 || (x.year % 400 == 0)) {
				maxday[2] = 29;
			}
		}
	} 
	while (x.year < 0 || x.month < 1 || x.day > 31 || x.day < 1 || (x.day > maxday[x.month]));
	for (i = 1; i < (x.month); ++i) {
		n += maxday[i];
	}
	n += x.day;
	printf("%d年的%d月%d日是该年的第%d天.\n", x.year, x.month, x.day, n);
	system("pause");
	return 0;
}

//利用结构体类型编制一个程序,实现输入三个学生的学号以及数学/语文/英语成绩
//然后计算每位学生的总成绩以及平均成绩并按总分由大到小输出成绩表
int main() {
	struct Student {
		char num[15];
		unsigned int english , math ,chinese;
		int total, average;
	};//要是在这里加上Stu的重命名,则Student定义式首要加上关键词typedef
	struct Student stu[3], temp;
	int i, j, k;
	for (i = 1; i <= 3; ++i) {
		printf("请输入第%d位学生的学号:\n", i);
		scanf("%s", &stu[i].num);
		printf("请输入第%d位学生的数学成绩, 语文成绩, 英语成绩:\n", i);
		scanf("%d %d %d", &stu[i].math, &stu[i].chinese, &stu[i].english);
		stu[i].total = stu[i].math + stu[i].chinese + stu[i].english;
		stu[i].average = stu[i].total / 3;
	}
	//实现总分由大到小输出成绩表
	for (i = 1; i <= 3; ++i) {
		k = i;
		for (j = i + 1; j <= 3; ++j) {
			if (stu[k].total < stu[j].total) {
				k = j;
			}
		}
		if (k != i) {
			temp = stu[i];
			stu[i] = stu[k];
			stu[k] = temp;
		}
	}
	printf("%10s%10s%10s%10s%10s%10s\n", "学号", "数学", "语文", "英语", "总分", "平均分");
	for (i = 1; i <= 3; ++i) {
		printf("%10s%10d%10d%10d%10d%10d\n", stu[i].num, stu[i].math, stu[i].chinese,
			stu[i].english, stu[i].total, stu[i].average);
	}
	system("pause");
	return 0;
}