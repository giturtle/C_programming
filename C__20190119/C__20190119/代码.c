
//�ٲ�ʽ����ģ�ͣ��ʼ�ȱ������У�ȷ�����⣬����Щ���ܣ�������Щ���ܡ�	(PM)
//�������	(PM)
//����Ա����: 
//1. ��Ҫ��ƣ�������Щ��Ĳ��֣�����֮�������ϵ
//2. ��ϸ��ƣ��ڸ�Ҫ���ǰ���£����и����������ϸ�����
//3. ����


//ͨѶ¼��
//����ܶ���ϵ��
//ÿ����ϵ�˵���Ϣ������ + �绰
//��ɾ�Ĳ�
//���û�ͨ������̨���н���

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define CONTACT_MAX_SIZE 500  //�����ϵ�˵ĺ궨�壬������ʱ�������޸�Ӱ�����

//�½���ϵ�˽ṹ��
typedef struct Contact {
	char name[1024];
	char Cell_phone[1024];
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
	//����ṹ��������ͨ�� size ��������Ԫ�ص���Ч����
	//���� size ��Ϊ 0 ��֤����������Ԫ��������ʲô������Ч�ģ���ͬ����ա�
}

void Add_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	if (telephone_directory->size >= CONTACT_MAX_SIZE) {
		printf("��ǰͨѶ¼����");
		return;
	}
	printf("\n\n******��ʼ������ϵ��:******\n");
	//ÿ�ζ�������µ���ϵ�˷ŵ���Ч��������һ��Ԫ����
	Contact* p = &telephone_directory->person[telephone_directory->size];	//	ȡ���ṹ��ָ�뷽�����漸�еĴ���ɶ���������
	//�������ȡ�ṹ���������ʹ�ýṹ��ָ�룺Contact p = telephone_directory->person[telephone_directory->size];
	//����ṹ������൱�������ж�ӦԪ�ص�һ�ݿ������޸Ľṹ�����ʱֻ��Ը����޸ģ�����Ӱ�쵽ԭ��������
	printf("������������ϵ�˵�����:");
	scanf("%s", p->name);
	printf("\n������������ϵ�˵ĵ绰����:");
	scanf("%s", p->Cell_phone);
	//������ɺ���Ҫ���� size
	++telephone_directory->size;
	printf("******������ϵ�˳ɹ�!******\n\n");
	printf("\n******��ǰͨѶ¼�й���%d������******\n\n", telephone_directory->size);
}

void Delete_Contact(telephone_directory* telephone_directory) {
	//1. ��ɾ������֮�������Ԫ�ض���ǰŲһλ��Ȼ�����һλ��Ϊ��Чλ����--size;
	//�����ķ���������̫ǿ�������һ�����͹�˾��ͨѶ¼��֮���Ԫ�����Ҳ�������ڼƣ���ô������ΰ��˷������Եúܱ�׾
	//Ҳ����ʹ������������Ҫ�����������ַ���

	//2. �����һ��Ԫ�ظ��ǵ�ɾ������Ԫ�أ�֮��--size;
	//���ַ�����˳����˼·����Ϊ˳�������˳��ģ������Դ������Ԫ�ص�˳���ϵ����ʱͨѶ¼��������Ͳ�Ҫ��ʵʵ���ڵ�˳�򣬶Ը÷�����һ����չ���Ժܺõؽ�����ڵ�����
	assert(telephone_directory != NULL);
	//���ͨ������ɾ����������Σ�գ���Ϊ�����������գ�����ɾ�������ϵ��
	//���ͨ���绰����ɾ������Ȼ��Ψһ�ģ����Ǻ���̫�����Լ��䣬��̫��ѧ
	//���Դ�ʱѡ�� ͨ��ͨѶ¼��� ����ɾ��.
	printf("��������Ҫɾ������ϵ�����:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= telephone_directory->size) {
		printf("��������������ɾ��ʧ�ܣ�\n");
		return;
	}
	Contact* p = &telephone_directory->person[id];
	printf("ȷ��ɾ��[%d]\t%s\t%s?(ʹ�� Y ȷ��)", id, p->name, p->Cell_phone);
	char choice[1024];		//	�û����������
	scanf("%s", &choice);
	if (strcmp(choice, "Y") != 0) {
		return;
	}
	//��ʼɾ���߼�
	//1. ȡ�����һ������Ԫ�صĽṹ��ָ��
	Contact* from = &telephone_directory->person[telephone_directory->size - 1];
	//2. ȡ����ɾ��Ԫ�ؽṹ��ָ��
	Contact* to = p;
	//3. �滻��ɾ��Ԫ��
	//���ṹ��֮������ͬ���ͽṹ���ֱ�Ӹ�ֵ�����൱��from�ṹ���е����ݿ�����to�ṹ���С�
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
	printf("������Ҫ�޸ĵ�����;(����Ҫ�޸Ĵ��������� ��)");
	scanf("%s", input);
	if (strcmp(input, "!") != 0) {	
		strcpy(p->name, input);
	}
	printf("������Ҫ�޸ĵĵ绰����;(����Ҫ�޸Ĵ��������� ��)");
	scanf("%s", input);
	if (strcmp(input, "!") != 0) {	//����û�û��ѡ�񣡣�����ѡ���޸����ݣ����û����������д��ṹ���С�
		//����û������ˣ�����ʾ���޸����ݣ���ô�Ͳ���Ҫ�������滻ԭ���������ˣ�if�����е����Ͳ�ִ����
		strcpy(p->Cell_phone, input);
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
	for(int i = 0;i < telephone_directory->size;++i){
		Contact* p = &telephone_directory->person[i];
		if (strcmp(p->name, name) == 0) {	//��ʾ�ҵ���
			printf("[%d]\t%s\t%s\n", i, p->name, p->Cell_phone);
			//�������п����ظ��� ���Դ�ʱ�����Լ���break;��չʾ��������
			++count;
		}
	}
	printf("\n\n******������ϣ�******\n");
	printf("******����ʾ�� %d �����ݣ�******\n",count);

}

void Sort_Contact(telephone_directory* telephone_directory) {

}

void Print_all_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	for (int i = 0; i < telephone_directory->size; ++i) {
		Contact* p = &telephone_directory->person[i];
		//��ʱ���������Ϊָ�룬��ʵ�ǿ��Եģ���Ϊ��ʱ���漰����Ԫ�����ݣ����Ǽ򵥵Ķ�ȡ�鿴�������Ǹ�������ԭʼ���ݶ���һ��ֵ
		//������������漰��ʵ�ν��п��������ʵ�νṹ���С��СӰ�첻������ṹ��ռ������G����ô��ʹ��ָ��������Ϊ������̫���ˣ������Ƽ�ʹ��ָ��
		printf("\n\n");
		printf("���\t����\t��ϵ��ʽ\n");
		printf("[%d]\t%s\t%s\n", i, p->name, p->Cell_phone);
	}
	printf("\n******���Ϲ���ʾ��%d������******\n\n", telephone_directory->size);
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
		Clear_all_Contact
	};
	while (1) {
		int choice = menu();
		if (choice < 0 || choice >(int)(sizeof(table) / sizeof(table[0]))) {	//	���ﲻֱ������һ�����֣���ѡ���鷳��ȥ��
			//sizeof �ķ���ֵ���޷�����������choice�����������õ����з��ŵ�����������ѡ��ʹ�޷�������ǿ������ת��Ϊ�з��ŵ�����
			//���߽��龡����ʹ���޷�����������Ϊunsigned��ʹ���кܶ�ע��㣬���������޷�������������������С�ڼ����ͻ���һ���ǳ����������ƽ��Ԥ�ڵȵȣ�����Ȥ�Ķ��߿��������˽�
			printf("������������! ����������:\n");
			continue;
		}
		if (choice == 0) {
			printf("\n��л����ʹ�ã��ټ�~\n");
			break;
		}
		table[choice - 1](&g_telephone_directory);	//�û������ֵ�ͺ���ָ�������ж�Ӧ��ѡ����� 1 ����������ѡ���û���������� -1 ����Ӧ����������ȷ��ֵ

		//if (choice == 1) {
		//	AddContact(&g_telephone_directory);
		//}
		//else if (choice == 2) {
		//	DelContact(&g_telephone_directory);
		//}
		//else if (choice == 3) {
		//	ModifyContact(&g_telephone_directory);
		//}
		//// ...
		//���������ƣ���Ȧ���Ӷȡ����ߣ�ͨ��ʹ�ú���ָ������ʵ�ֵġ������������

	}
	system("pause");
	return 0;
}