#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//��дһ������print����ӡһ��ѧ���ĳɼ����飬��������5��ѧ�������ݼ�¼
//ÿ����¼����num��name��score[3]����������������Щ��¼����print���������Щ��¼
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
		printf("�������%d��ѧ����ѧ�ţ�����\n", i + 1);
		scanf("%s %s", &stu[i].num, &stu[i].name);
		printf("�������ѧ�������ųɼ���\n\n");
		for (j = 0; j < 3; j++) {
			printf("��%d�ųɼ���\n", j + 1);
			scanf("%lf", &stu[i].score[j]);
		}
		printf("\n");
		print(stu);
	}
	system("pause");
	return 0;
}


//��ʾ���ʱ�
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
		printf("%s�Ĺ�����%dԪ\n", p->name, p->salary);
	}
	system("pause");
	return 0;
}


//��ʾĳ�˹�����Ϣ�ĳ������£�������ʾ���
main() {
	struct staff {
		char name[20];
		char department[20];
		int salary;
	};
	struct staff w1, *p;
	p = &w1;
	strcpy(w1.name, "Li-Li");//������Ϣ
	strcpy((*p).department, "part1");
	p->salary = 1000;
	printf("%s��%s��%d\n", w1.name,w1.department,w1.salary);
	printf("%s��%s��%d\n", (*p).name,(*p).department,(*p).salary);
	printf("%s��%s��%d\n", p ->name,p ->department,p ->salary);
	//���������Ϊ Li-Li��part��11000
	//�����ͨ����ͬ��Ա���ʷ�ʽ���Σ��ṹ���������/�ṹ��ָ�봫��
	system("pause");
	return 0;
}


//����10��ѧ������Ϣ��ÿ��ѧ�������ݰ���ѧ�š�������һ�ſεĳɼ���
//Ҫ��Ӽ���������10��ѧ������Ϣ��������ÿһ����ʾһ��ѧ����Ϣ����ʽ��ʾ����
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
		printf("������%d��ѧ����ѧ�ţ����������Ƴɼ���\n",i);
		scanf("%d %s %lf", &s[i].sn, &s[i].name, &s[i].score);
	}
	printf("\n");
	for (i = 1; i <= student; i++) {
		printf("��%d��ѧ����ѧ�ţ����������Ƴɼ�Ϊ��\n", i);
		printf("%d %s %5.2lf\n", s[i].sn, s[i].name, s[i].score);
	}
	system("pause");
	return 0;
}


//����һ��ѧ���ļ���Ϣ�����а���ѧ�š����䡢�Ա�һ�ſεĳɼ�
//Ҫ��Ӽ���Ϊ��ѧ����Ϣ�������ݣ�����ʾ����
//һ����Ϣ������ɽṹ�������壬���е����ݿ���ͨ���ṹ���еĳ�Ա����ʾ
struct Student {
	int sn;
	char gender;
	int age;
	double score;
}Stu;
int main() {
	printf("������ѧ����ѧ�ţ��Ա����䣬���Ƴɼ�:\n");
	printf("���Ա�'1'�����У�'2'����Ů��\n");
	scanf("%d %c %d %lf", &Stu.sn, &Stu.gender, &Stu.age, &Stu.score);
	printf("��ѧ����ѧ��Ϊ��%d\n", Stu.sn);
	if (Stu.gender == '1') {
		printf("��ѧ�����Ա�Ϊ����\n");
	}
	else {
		printf("��ѧ�����Ա�Ϊ��Ů\n");
	}
	printf("��ѧ��������Ϊ��%d\n", Stu.age);
	printf("��ѧ���ĵ��Ƴɼ�Ϊ��%5.2lf\n", Stu.score);
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
	//(ϵͳֱ��ʶ��Ϊ��Сֵ�������н���)
}