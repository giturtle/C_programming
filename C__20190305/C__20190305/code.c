#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//汉诺塔问题

int main() {
	void hanoi(int n, char one, char two, char three);		//将n个盘子从one座借助two座移到three座
	int m;
	printf("input the number of diskes:");
	scanf("%d", &m);
	printf("the step to move %d diskes:\n", m);
	hanoi(m, 'A', 'B', 'C');
	system("pause");
	return 0;
}

void hanoi(int n, char one, char two, char three) {
	void move(char x, char y);
	if (n == 1) {
		move(one, three);
	}
	else {
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}

void move(char x, char y) {
	printf("%c --> %c\n", x, y);
}