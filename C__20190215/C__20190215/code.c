#define _cRT_sECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main() {
	union IP {
		uint32_t a;
		struct {		//匿名结构体
			char d1;
			char d2;
			char d3;
			char d4;
		}b;
	}ip;
	ip.a = 0x1;
	printf("%d.%d.%d.%d\n", ip.b.d1, ip.b.d2, ip.b.d3, ip.b.d4);
	system("pause");
	return 0;
}


union Un1{
	char c[5];
	int i;
};
union Un2{
	short c[7];
	int i;
};
int main() {
	printf("%d\n", sizeof(union Un1));	//8
	printf("%d\n", sizeof(union Un2));	//16
	system("pause");
	return 0;
}


//字节序验证
int Little() {
	int a = 0x11223344;
	char *b = (char*)&a;
	if (*b == 0x11) {
		return 0;
	}
	return 1;
}
//使用联合体
int little() {
	union Un {
		char a;
		int b;
	}u;
	u.b = 0x11223344;
	if (u.a == 0x11) {
		return 0;
	}
	return 1;
}



union Un {
	char c;
	int i;	
};
struct S {
	char c;
	int i;
};
int main() {
	union Un u;
	struct S s;
	printf("%lu\n", sizeof(u));
	printf("%lu\n", sizeof(s));

	system("pause");
	return 0;
}


enum Color{
	red = 1,
	green = 4,
	blue = 5,
};
int main() {
	enum Color c = green;
	c = 4;
	system("pause");
	return 0;
}