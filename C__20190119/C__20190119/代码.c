
//瀑布式开发模型：最开始先背景调研，确定主题，做那些功能，不做哪些功能。	(PM)
//需求分析	(PM)
//程序员部分: 
//1. 概要设计：包含哪些大的部分，部分之间如何联系
//2. 详细设计：在概要设计前提下，进行更加深入和详细的设计
//3. 编码


//通讯录：
//管理很多联系人
//每个联系人的信息：姓名 + 电话
//增删改查
//和用户通过控制台进行交互

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define CONTACT_MAX_SIZE 500  //最大联系人的宏定义，可以随时在这里修改影响程序

//新建联系人结构体
typedef struct Contact {
	char name[1024];
	char Cell_phone[1024];
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
	//这个结构体数组是通过 size 控制数组元素的有效个数
	//当把 size 设为 0 ，证明无论数组元素内容是什么都是无效的，等同于清空。
}

void Add_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	if (telephone_directory->size >= CONTACT_MAX_SIZE) {
		printf("当前通讯录已满");
		return;
	}
	printf("\n\n******开始新增联系人:******\n");
	//每次都把这个新的联系人放到有效数组的最后一个元素上
	Contact* p = &telephone_directory->person[telephone_directory->size];	//	取出结构体指针方便下面几行的代码可读性与简洁性
	//这里如果取结构体变量，不使用结构体指针：Contact p = telephone_directory->person[telephone_directory->size];
	//这个结构体变量相当于数组中对应元素的一份拷贝，修改结构体变量时只会对副本修改，不会影响到原来的数组
	printf("请输入新增联系人的姓名:");
	scanf("%s", p->name);
	printf("\n请输入新增联系人的电话号码:");
	scanf("%s", p->Cell_phone);
	//新增完成后，需要更新 size
	++telephone_directory->size;
	printf("******插入联系人成功!******\n\n");
	printf("\n******当前通讯录中共有%d条数据******\n\n", telephone_directory->size);
}

void Delete_Contact(telephone_directory* telephone_directory) {
	//1. 将删除对象之后的所有元素都往前挪一位，然后将最后一位设为无效位，即--size;
	//这样的方法局限性太强，如果是一个大型公司的通讯录，之后的元素如果也是数以亿计，那么这样多次搬运方法就显得很笨拙
	//也可以使用链表，这里主要讲解下面这种方法

	//2. 将最后一个元素覆盖掉删除对象元素，之后--size;
	//这种方法是顺序表的思路，因为顺序表是有顺序的，不可以打断其中元素的顺序关系。此时通讯录的情况，就不要求实实在在的顺序，对该方法的一个拓展可以很好地解决现在等问题
	assert(telephone_directory != NULL);
	//如果通过姓名删除，操作很危险，因为存在重名风险，可能删除多个联系人
	//如果通过电话号码删除，虽然是唯一的，但是号码太长难以记忆，不太科学
	//所以此时选择 通过通讯录序号 进行删除.
	printf("请输入想要删除的联系人序号:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= telephone_directory->size) {
		printf("您输入的序号有误！删除失败！\n");
		return;
	}
	Contact* p = &telephone_directory->person[id];
	printf("确认删除[%d]\t%s\t%s?(使用 Y 确认)", id, p->name, p->Cell_phone);
	char choice[1024];		//	用户输入的内容
	scanf("%s", &choice);
	if (strcmp(choice, "Y") != 0) {
		return;
	}
	//开始删除逻辑
	//1. 取出最后一个数组元素的结构体指针
	Contact* from = &telephone_directory->person[telephone_directory->size - 1];
	//2. 取出被删除元素结构体指针
	Contact* to = p;
	//3. 替换被删除元素
	//【结构体之间允许同类型结构体的直接赋值】【相当于from结构体中的内容拷贝到to结构体中】
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
	printf("请输入要修改的姓名;(不需要修改此项请输入 ！)");
	scanf("%s", input);
	if (strcmp(input, "!") != 0) {	
		strcpy(p->name, input);
	}
	printf("请输入要修改的电话号码;(不需要修改此项请输入 ！)");
	scanf("%s", input);
	if (strcmp(input, "!") != 0) {	//如果用户没有选择！，就是选择修改内容，把用户输入的内容写入结构体中。
		//如果用户输入了！，表示不修改内容，那么就不需要把输入替换原来的内容了，if条件中的语句就不执行了
		strcpy(p->Cell_phone, input);
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
	for(int i = 0;i < telephone_directory->size;++i){
		Contact* p = &telephone_directory->person[i];
		if (strcmp(p->name, name) == 0) {	//表示找到了
			printf("[%d]\t%s\t%s\n", i, p->name, p->Cell_phone);
			//姓名是有可能重复的 所以此时不可以加上break;，展示所有内容
			++count;
		}
	}
	printf("\n\n******查找完毕！******\n");
	printf("******共显示了 %d 条数据！******\n",count);

}

void Sort_Contact(telephone_directory* telephone_directory) {

}

void Print_all_Contact(telephone_directory* telephone_directory) {
	assert(telephone_directory != NULL);
	for (int i = 0; i < telephone_directory->size; ++i) {
		Contact* p = &telephone_directory->person[i];
		//这时如果不设置为指针，其实是可以的，因为此时不涉及更改元素内容，而是简单的读取查看，无论是副本还是原始数据都是一个值
		//但是这个过程涉及对实参进行拷贝，如果实参结构体大小很小影响不大，如果结构体占存许多个G，那么不使用指针的这个行为开销就太大了，还是推荐使用指针
		printf("\n\n");
		printf("序号\t姓名\t联系方式\n");
		printf("[%d]\t%s\t%s\n", i, p->name, p->Cell_phone);
	}
	printf("\n******以上共显示了%d条数据******\n\n", telephone_directory->size);
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
		Clear_all_Contact
	};
	while (1) {
		int choice = menu();
		if (choice < 0 || choice >(int)(sizeof(table) / sizeof(table[0]))) {	//	这里不直接设置一个数字，而选择麻烦的去设
			//sizeof 的返回值是无符号整数，而choice变量我们设置的是有符号的整数，我们选择使无符号类型强制类型转换为有符号的类型
			//笔者建议尽量少使用无符号整数，因为unsigned的使用有很多注意点，比如两个无符号整型作差，被减数如果小于减数就会变成一个非常大的数超乎平常预期等等，感兴趣的读者可以自行了解
			printf("您的输入有误! 请重新输入:\n");
			continue;
		}
		if (choice == 0) {
			printf("\n感谢您的使用，再见~\n");
			break;
		}
		table[choice - 1](&g_telephone_directory);	//用户输入的值和函数指针数组中对应的选项相差 1 ，所以这里选择将用户输入的数字 -1 ，对应到数组中正确的值

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
		//如果这样设计，“圈复杂度”过高，通过使用函数指针数组实现的“表驱动”解决

	}
	system("pause");
	return 0;
}