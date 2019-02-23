#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define CONTACT_MAX_SIZE 1000

//新建联系人结构体
typedef struct Contact {
	char name[1024];		//姓名
	char sex[5];			//性别
	int age;				//年龄
	char Cell_phone[1024];	//电话
	char address[50];		//住址
}Contact;

//联系人结构体数组
typedef struct telephone_directory {
	Contact person[CONTACT_MAX_SIZE];
	int size;	//描述前size个元素是有效的，[0 ,size)范围是数组的有效范围区间
}telephone_directory;

telephone_directory g_telephone_directory;	//声明一个全局变量作为设计的通讯录的实体


void Init(telephone_directory* telephone_directory) {	//这里通过指针传参，如果不使用指针，函数的形参就不会影响到实参
	assert(telephone_directory != NULL);//设置断言来校验传进来的指针的有效性
	telephone_directory->size = 0;
}

void Add_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	if (telephone_directory->size >= CONTACT_MAX_SIZE) {
		printf("当前通讯录已满");
		return;
	}
	printf("\n\n******开始新增联系人:******\n");
	Contact* p = &telephone_directory->person[telephone_directory->size];	//	取出结构体指针方便下面几行的代码可读性与简洁性
	printf("\n请输入新增联系人的姓名:");
	scanf("%s", p->name);
	printf("\n请输入新增联系人的性别:");
	scanf("%s", p->sex);
	printf("\n请输入新增联系人的年龄:");
	scanf("%d", &p->age);
	printf("\n请输入新增联系人的电话号码:");
	scanf("%s", p->Cell_phone);
	printf("\n请输入新增联系人的地址:");
	scanf("%s", p->address);
	++telephone_directory->size;
	printf("******插入联系人成功!******\n\n");
	printf("\n******当前通讯录中共有%d条数据******\n\n", telephone_directory->size);
}

void Delete_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	printf("请输入想要删除的联系人序号:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= telephone_directory->size) {
		printf("您输入的序号有误！删除失败！\n");
		return;
	}
	Contact* p = &telephone_directory->person[id];
	printf("序号\t姓名\t性别\t年龄\t联系方式\t家庭住址\n");
	printf("确认删除[%d]\t%s\t%s\t%d\t\t%s?(使用 Y 确认)", id, p->name, p->sex, p->age,p->Cell_phone);
	char choice[1024];		//	用户输入的内容
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
	printf("******开始修改联系人******\n\n");
	printf("请输入需要修改的联系人序号:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id > telephone_directory->size) {
		printf("您输入的序号有误！修改失败！\n");
		return;
	}
	Contact* p = &telephone_directory->person[id];
	char input[1024];
	int input_int;
	printf("请输入要修改的姓名:(不需要修改此项请输入 ！)");
	scanf("%s", input);
	if (strcmp(input, "!") != 0) {
		strcpy(p->name, input);
	}
	printf("请输入要修改的性别:(不需要修改此项请输入 ！)");
	scanf("%s", &input);
	if (strcmp(input, "!") != 0) {
		strcpy(p->sex, input);
	}
	printf("请输入要修改的年龄:(不需要修改此项请输入 -1 )");
	scanf("%d", &input_int);
	if (input_int != -1) {
		p->age = input_int;
	}
	printf("请输入要修改的电话号码:(不需要修改此项请输入 ！)");
	scanf("%s", input);
	if (strcmp(input, "!") != 0) {	//如果用户没有选择！，就是选择修改内容，把用户输入的内容写入结构体中。
		//如果用户输入了！，表示不修改内容，那么就不需要把输入替换原来的内容了，if条件中的语句就不执行了
		strcpy(p->Cell_phone, input);
	}
	printf("请输入要修改的家庭住址:(不需要修改此项请输入 ！)");
	scanf("%s", &input);
	if (strcmp(input, "!") != 0) {
		strcpy(p->address, input);
	}
	printf("******修改成功!******\n");
}

void Seek_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	printf("******开始进行查找******\n\n");
	printf("请输入要查找的姓名:");		//一般都是按照姓名进行查找，所以此处设置为姓名索引
	char name[1024] = { 0 };
	scanf("%s", name);
	int count = 0;
	for (int i = 0; i < telephone_directory->size; ++i) {
		Contact* p = &telephone_directory->person[i];
		if (strcmp(p->name, name) == 0) {	//表示找到了
			printf("序号\t姓名\t性别\t年龄\t联系方式\t家庭住址\n");
			printf("[%d]\t%s\t%s\t%d\t%s\t\t%s\n", i, p->name, p->sex, p->age, p->Cell_phone, p->address);
			++count;
		}
	}
	printf("\n\n******查找完毕！******\n");
	printf("******共显示了 %d 条数据！******\n", count);

}

void Print_all_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	for (int i = 0; i < telephone_directory->size; ++i) {
		Contact* p = &telephone_directory->person[i];
		printf("\n\n");
		printf("序号\t姓名\t性别\t年龄\t联系方式\t家庭住址\n");
		printf("[%d]\t%s\t%s\t%d\t%s\t\t%s\n", i, p->name, p->sex, p->age, p->Cell_phone, p->address);
	}
	printf("\n******以上共显示了%d条数据******\n\n", telephone_directory->size);
}

void Sort_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	//按照ascii码字典序排序
	printf("按照字母顺序排序如下:\n");
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
	printf("确认清空所有联系人:(输入 Y 表示确认)");	//防止用户误触点击清空
	char input[1024];
	scanf("%s", input);
	if (strcmp(input, "Y") != 0) {
		printf("\n******清空操作取消！******\n");
		return;
	}
	telephone_directory->size = 0;
	printf("\n******清空操作完成！******\n");
}

//文件写入函数 
void Save_Contact(telephone_directory* telephone_directory){
	assert(telephone_directory != NULL);
	FILE *fp;
	Contact* p1 = &telephone_directory->person[0];
	char tele_directory[30];
	
	printf("请输入保存后的文件名:");
	gets(tele_directory);
	fp = fopen("tele_directory.txt", "w");
	if (fp == NULL){
		printf("无法打开文件\n");
		exit(0);
	}
	fprintf(fp, "姓名  性别   年龄   家庭住址   联系方式\n");
	for (; p1 != NULL;){
		fprintf(fp, "%s    %s    %d    %s    %s\n", p1->name, p1->sex, p1->age,  p1->address, p1->Cell_phone );
		p1++;
	}
	printf("保存完毕!\n");
	fclose(fp);
}

int menu() {
	printf("=================\n");
	printf("|  < 选项列表 > |\n");
	printf("|		|\n");
	printf("|  1. 增加	|\n");
	printf("|  2. 删除	|\n");
	printf("|  3. 修改	|\n");
	printf("|  4. 查询	|\n");
	printf("|  5. 排序	|\n");
	printf("|  6. 显示全部	|\n");
	printf("|  7. 清空全部	|\n");
	printf("|  8. 保存	|\n"); 
	printf("|  0. 退出	|\n");
	printf("|		|\n");
	printf("=================\n");
	printf("\n请输入您的选项：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int main() {
	//1. 对通讯录进行初始化
	Init(&g_telephone_directory);
	//开始设置表驱动
	typedef void(*pfunc_t)(telephone_directory*);	//设置函数指针数组
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
		if (choice < 0 || choice >(int)(sizeof(table) / sizeof(table[0]))) {	//	这里不直接设置一个数字，而选择麻烦的去设
			printf("您的输入有误! 请重新输入:\n");
			continue;
		}
		if (choice == 0) {
			printf("\n感谢您的使用，再见~\n");
			break;
		}
		table[choice - 1](&g_telephone_directory);	//用户输入的值和函数指针数组中对应的选项相差 1 ，所以这里选择将用户输入的数字 -1 ，对应到数组中正确的值
	}
	system("pause");
	return 0;
}