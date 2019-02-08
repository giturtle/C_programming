#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>


//******************memcpy******************

void *Memcpy(void * dest, const void * src, size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	char *pdest = (char*)dest;
	char *psrc = (char*)src;//让系统按照字节来拷贝
	for (size_t i = 0; i < num; ++i) {
		//这里不可以dest[i] = src[i];
		//因为void*不可以解引用以及加上一个整数，上面这一句就是在进行两者。
		pdest[i] = psrc[i];
		//缓冲区重合问题
	}
	return dest;
}
int main() {
	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", arr2[i]);
	}
	system("pause");
	return 0;
}


//缓冲区重合问题发生原因：dest指针是否在src缓冲区之内
//避免memcpy缓冲区重合问题：

//******************memmove******************

void *Memmove(void * dest, const void * src, size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	char *pdest = (char*)dest;
	char *psrc = (char*)src;
	if (pdest >= psrc && pdest <= psrc + num) {		//标准库认为的缓冲区重合现象
		//解决方案：从后往前拷贝
		for (int64_t i = num - 1; i >= 0; --i) {	//int64_t解决了使用size_t2个问题：1. i>=0 恒成立 2.如果num传入为0，那么i就从很大的数开始运算
			pdest[i] = psrc[i];
		}
	}
	else {
		for (size_t i = 0; i < num; ++i) {
			//按照原来的memcpy方式进行操作
			pdest[i] = psrc[i];
		}
	}
	return dest;
}



//******************memcmp******************
int Memcmp(const void * ptr1,
	const void * ptr2,
	size_t num);
//和strncmp的使用非常相似。



//******************strerror******************

//默认情况下，errno值为 0 ，如果使用了某些库函数或者操作系统函数，这些函数在执行失败的时候就设置errno的值
//根据返回的错误码，返回对应的错误信息
int main() {
	FILE *fp = fopen("aaa.txt", "r");
	printf("%d\n", errno);	
	printf("%s\n", strerror(errno));
	system("pause");
	return 0;
}


int Tolower(int c) {
	if (c >= 'A' && c <= 'Z') {
		return c + ('a' - 'A');
	}
	return c;
}
int main() {
	printf("%c\n",Tolower('A'));
	system("pause");
	return 0;
}