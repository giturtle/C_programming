#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//定义一个结构体变量，包括年月日，计算该日在本年中第几天，注意闰年问题

//解法一
struct {
	int year;
	int month;
	int day;
}date;//定义结构体变量 date
int main() {
	int days;
	printf("请输入年月日：\n");
	scanf("%d %d %d", &date.year, &date.month, &date.day);
	switch (date.month) {
	case 1:days = date.day; break;
	case 2:days = date.day + 31; break;
	case 3:days = date.day + 59; break;
	case 4:days = date.day + 90; break;
	case 5:days = date.day + 120; break;
	case 6:days = date.day + 151; break;
	case 7:days = date.day + 181; break;
	case 8:days = date.day + 212; break;
	case 9:days = date.day + 243; break;
	case 10:days = date.day + 273; break;
	case 11:days = date.day + 304; break;
	case 12:days = date.day + 334; break;
	}
	if ((date.year % 4 == 0 && date.year % 100 != 0)
		|| date.year % 400 == 0 ) {
		days += 1;
	}
	printf("\n%d月%d日是%d年的第%d天", date.month, date.day, date.year, days);
	system("pause");
	return 0;
}

//解法二
struct date {
	int year;
	int month;
	int day;
}date;
int main() {
	int i, days;
	int day_list[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("请输入年月日：\n");
	scanf("%d %d %d", &date.year, &date.month, &date.day);
	days = 0;
	for (i = 1; i < date.month; i++) {
		days += day_list[i];
	}
	//不同点
	days += date.day;
	if ((date.year % 4 == 0 && date.year % 100 != 0)
		|| date.year % 400 == 0 ) {
		days += 1;
	}
	printf("\n%d月%d日是%d年的第%d天", date.month, date.day, date.year, days);
	system("pause");
	return 0;
}