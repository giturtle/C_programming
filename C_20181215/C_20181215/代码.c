#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//����ö������ money ,��ö��Ԫ�ش�������ҵ���ֵ
//�������ֵ����1/2/5�� , 1/2/5�� , 1/2/5/10/20/50/100Ԫ
enum money {
	fen1,fen2,fen5,
	jiao1,jiao2,jiao5,
	yuan1,yuan2,yuan5,yuan10,yuan20,yuan50,yuan100
};

//��һ��unsigned long ��������,�ֱ���ǰ 2 ���ֽںͺ� 2 ���ֽ� ->
//  -> ��Ϊ����unsigned int�����������
//��һ��int������ռ 2 ���ֽ�
int main() {
	union {
		unsigned long k;
		unsigned a[2];
	}u;
	u.k = 0xef3d6ab9;
	//��������滹��Ҫ˼��
	printf("%x,%x\n", u.a[0], u.a[1]);
	system("pause");
	return 0;
}


//����һ�����������ճ�Ա�Ľṹ�����,����ת������һ��ĵڼ��첢���
//Ӧע������Ķ�����29��,���ʽ"(year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))"
//��ֵΪ��,��Ϊ����,����year��ʾ���
int main() {
	struct hehe{
		unsigned year, month, day;
	}x;
	int maxday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, n = 0;
	do {
		printf("�������� �� ��:\n");
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
	printf("%d���%d��%d���Ǹ���ĵ�%d��.\n", x.year, x.month, x.day, n);
	system("pause");
	return 0;
}

//���ýṹ�����ͱ���һ������,ʵ����������ѧ����ѧ���Լ���ѧ/����/Ӣ��ɼ�
//Ȼ�����ÿλѧ�����ܳɼ��Լ�ƽ���ɼ������ܷ��ɴ�С����ɼ���
int main() {
	struct Student {
		char num[15];
		unsigned int english , math ,chinese;
		int total, average;
	};//Ҫ�����������Stu��������,��Student����ʽ��Ҫ���Ϲؼ���typedef
	struct Student stu[3], temp;
	int i, j, k;
	for (i = 1; i <= 3; ++i) {
		printf("�������%dλѧ����ѧ��:\n", i);
		scanf("%s", &stu[i].num);
		printf("�������%dλѧ������ѧ�ɼ�, ���ĳɼ�, Ӣ��ɼ�:\n", i);
		scanf("%d %d %d", &stu[i].math, &stu[i].chinese, &stu[i].english);
		stu[i].total = stu[i].math + stu[i].chinese + stu[i].english;
		stu[i].average = stu[i].total / 3;
	}
	//ʵ���ܷ��ɴ�С����ɼ���
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
	printf("%10s%10s%10s%10s%10s%10s\n", "ѧ��", "��ѧ", "����", "Ӣ��", "�ܷ�", "ƽ����");
	for (i = 1; i <= 3; ++i) {
		printf("%10s%10d%10d%10d%10d%10d\n", stu[i].num, stu[i].math, stu[i].chinese,
			stu[i].english, stu[i].total, stu[i].average);
	}
	system("pause");
	return 0;
}