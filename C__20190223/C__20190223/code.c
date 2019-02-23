#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define CONTACT_MAX_SIZE 1000

//�½���ϵ�˽ṹ��
typedef struct Contact {
	char name[1024];		//����
	char sex[5];			//�Ա�
	int age;				//����
	char Cell_phone[1024];	//�绰
	char address[50];		//סַ
}Contact;

//��ϵ�˽ṹ������
typedef struct telephone_directory {
	Contact person[CONTACT_MAX_SIZE];
	int size;	//����ǰsize��Ԫ������Ч�ģ�[0 ,size)��Χ���������Ч��Χ����
}telephone_directory;

telephone_directory g_telephone_directory;	//����һ��ȫ�ֱ�����Ϊ��Ƶ�ͨѶ¼��ʵ��


void Init(telephone_directory* telephone_directory) {	//����ͨ��ָ�봫�Σ������ʹ��ָ�룬�������βξͲ���Ӱ�쵽ʵ��
	assert(telephone_directory != NULL);//���ö�����У�鴫������ָ�����Ч��
	telephone_directory->size = 0;
}

void Add_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	if (telephone_directory->size >= CONTACT_MAX_SIZE) {
		printf("��ǰͨѶ¼����");
		return;
	}
	printf("\n\n******��ʼ������ϵ��:******\n");
	Contact* p = &telephone_directory->person[telephone_directory->size];	//	ȡ���ṹ��ָ�뷽�����漸�еĴ���ɶ���������
	printf("\n������������ϵ�˵�����:");
	scanf("%s", p->name);
	printf("\n������������ϵ�˵��Ա�:");
	scanf("%s", p->sex);
	printf("\n������������ϵ�˵�����:");
	scanf("%d", &p->age);
	printf("\n������������ϵ�˵ĵ绰����:");
	scanf("%s", p->Cell_phone);
	printf("\n������������ϵ�˵ĵ�ַ:");
	scanf("%s", p->address);
	++telephone_directory->size;
	printf("******������ϵ�˳ɹ�!******\n\n");
	printf("\n******��ǰͨѶ¼�й���%d������******\n\n", telephone_directory->size);
}

void Delete_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	printf("��������Ҫɾ������ϵ�����:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= telephone_directory->size) {
		printf("��������������ɾ��ʧ�ܣ�\n");
		return;
	}
	Contact* p = &telephone_directory->person[id];
	printf("���\t����\t�Ա�\t����\t��ϵ��ʽ\t��ͥסַ\n");
	printf("ȷ��ɾ��[%d]\t%s\t%s\t%d\t\t%s?(ʹ�� Y ȷ��)", id, p->name, p->sex, p->age,p->Cell_phone);
	char choice[1024];		//	�û����������
	scanf("%s", &choice);
	if (strcmp(choice, "Y") != 0) {
		return;
	}
	Contact* from = &telephone_directory->person[telephone_directory->size - 1];
	Contact* to = p;
	*to = *from;
	--telephone_directory->size;
}

void Modify_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	printf("******��ʼ�޸���ϵ��******\n\n");
	printf("��������Ҫ�޸ĵ���ϵ�����:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id > telephone_directory->size) {
		printf("���������������޸�ʧ�ܣ�\n");
		return;
	}
	Contact* p = &telephone_directory->person[id];
	char input[1024];
	int input_int;
	printf("������Ҫ�޸ĵ�����:(����Ҫ�޸Ĵ��������� ��)");
	scanf("%s", input);
	if (strcmp(input, "!") != 0) {
		strcpy(p->name, input);
	}
	printf("������Ҫ�޸ĵ��Ա�:(����Ҫ�޸Ĵ��������� ��)");
	scanf("%s", &input);
	if (strcmp(input, "!") != 0) {
		strcpy(p->sex, input);
	}
	printf("������Ҫ�޸ĵ�����:(����Ҫ�޸Ĵ��������� -1 )");
	scanf("%d", &input_int);
	if (input_int != -1) {
		p->age = input_int;
	}
	printf("������Ҫ�޸ĵĵ绰����:(����Ҫ�޸Ĵ��������� ��)");
	scanf("%s", input);
	if (strcmp(input, "!") != 0) {	//����û�û��ѡ�񣡣�����ѡ���޸����ݣ����û����������д��ṹ���С�
		//����û������ˣ�����ʾ���޸����ݣ���ô�Ͳ���Ҫ�������滻ԭ���������ˣ�if�����е����Ͳ�ִ����
		strcpy(p->Cell_phone, input);
	}
	printf("������Ҫ�޸ĵļ�ͥסַ:(����Ҫ�޸Ĵ��������� ��)");
	scanf("%s", &input);
	if (strcmp(input, "!") != 0) {
		strcpy(p->address, input);
	}
	printf("******�޸ĳɹ�!******\n");
}

void Seek_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	printf("******��ʼ���в���******\n\n");
	printf("������Ҫ���ҵ�����:");		//һ�㶼�ǰ����������в��ң����Դ˴�����Ϊ��������
	char name[1024] = { 0 };
	scanf("%s", name);
	int count = 0;
	for (int i = 0; i < telephone_directory->size; ++i) {
		Contact* p = &telephone_directory->person[i];
		if (strcmp(p->name, name) == 0) {	//��ʾ�ҵ���
			printf("���\t����\t�Ա�\t����\t��ϵ��ʽ\t��ͥסַ\n");
			printf("[%d]\t%s\t%s\t%d\t%s\t\t%s\n", i, p->name, p->sex, p->age, p->Cell_phone, p->address);
			++count;
		}
	}
	printf("\n\n******������ϣ�******\n");
	printf("******����ʾ�� %d �����ݣ�******\n", count);

}

void Print_all_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	for (int i = 0; i < telephone_directory->size; ++i) {
		Contact* p = &telephone_directory->person[i];
		printf("\n\n");
		printf("���\t����\t�Ա�\t����\t��ϵ��ʽ\t��ͥסַ\n");
		printf("[%d]\t%s\t%s\t%d\t%s\t\t%s\n", i, p->name, p->sex, p->age, p->Cell_phone, p->address);
	}
	printf("\n******���Ϲ���ʾ��%d������******\n\n", telephone_directory->size);
}

void Sort_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	//����ascii���ֵ�������
	printf("������ĸ˳����������:\n");
	for (int bound = 0; bound < telephone_directory->size; ++bound){
		for (int cur = telephone_directory->size - 1; cur > bound; --cur) {
			Contact* p = &telephone_directory->person[cur - 1];
			Contact* q = &telephone_directory->person[cur];
			if (strcmp(p->name,q->name) > 0) {
				Contact temp = *p;
				*p = *q;
				*q = temp;
			}
		}
	}
	Print_all_Contact(telephone_directory);
}

void Clear_all_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	printf("ȷ�����������ϵ��:(���� Y ��ʾȷ��)");	//��ֹ�û��󴥵�����
	char input[1024];
	scanf("%s", input);
	if (strcmp(input, "Y") != 0) {
		printf("\n******��ղ���ȡ����******\n");
		return;
	}
	telephone_directory->size = 0;
	printf("\n******��ղ�����ɣ�******\n");
}

//�ļ�д�뺯�� 
void Save_Contact(telephone_directory* telephone_directory){
	assert(telephone_directory != NULL);
	FILE *fp;
	Contact* p1 = &telephone_directory->person[0];
	char tele_directory[30];
	
	printf("�����뱣�����ļ���:");
	gets(tele_directory);
	fp = fopen("tele_directory.txt", "w");
	if (fp == NULL){
		printf("�޷����ļ�\n");
		exit(0);
	}
	fprintf(fp, "����  �Ա�   ����   ��ͥסַ   ��ϵ��ʽ\n");
	for (; p1 != NULL;){
		fprintf(fp, "%s    %s    %d    %s    %s\n", p1->name, p1->sex, p1->age,  p1->address, p1->Cell_phone );
		p1++;
	}
	printf("�������!\n");
	fclose(fp);
}

int menu() {
	printf("=================\n");
	printf("|  < ѡ���б� > |\n");
	printf("|		|\n");
	printf("|  1. ����	|\n");
	printf("|  2. ɾ��	|\n");
	printf("|  3. �޸�	|\n");
	printf("|  4. ��ѯ	|\n");
	printf("|  5. ����	|\n");
	printf("|  6. ��ʾȫ��	|\n");
	printf("|  7. ���ȫ��	|\n");
	printf("|  8. ����	|\n"); 
	printf("|  0. �˳�	|\n");
	printf("|		|\n");
	printf("=================\n");
	printf("\n����������ѡ�");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int main() {
	//1. ��ͨѶ¼���г�ʼ��
	Init(&g_telephone_directory);
	//��ʼ���ñ�����
	typedef void(*pfunc_t)(telephone_directory*);	//���ú���ָ������
	pfunc_t table[] = {
		Add_Contact,
		Delete_Contact,
		Modify_Contact,
		Seek_Contact,
		Sort_Contact,
		Print_all_Contact,
		Clear_all_Contact,
		Save_Contact
	};
	while (1) {
		int choice = menu();
		if (choice < 0 || choice >(int)(sizeof(table) / sizeof(table[0]))) {	//	���ﲻֱ������һ�����֣���ѡ���鷳��ȥ��
			printf("������������! ����������:\n");
			continue;
		}
		if (choice == 0) {
			printf("\n��л����ʹ�ã��ټ�~\n");
			break;
		}
		table[choice - 1](&g_telephone_directory);	//�û������ֵ�ͺ���ָ�������ж�Ӧ��ѡ����� 1 ����������ѡ���û���������� -1 ����Ӧ����������ȷ��ֵ
	}
	system("pause");
	return 0;
}