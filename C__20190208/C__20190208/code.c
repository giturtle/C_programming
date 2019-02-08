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
	char *psrc = (char*)src;//��ϵͳ�����ֽ�������
	for (size_t i = 0; i < num; ++i) {
		//���ﲻ����dest[i] = src[i];
		//��Ϊvoid*�����Խ������Լ�����һ��������������һ������ڽ������ߡ�
		pdest[i] = psrc[i];
		//�������غ�����
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


//�������غ����ⷢ��ԭ��destָ���Ƿ���src������֮��
//����memcpy�������غ����⣺

//******************memmove******************

void *Memmove(void * dest, const void * src, size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	char *pdest = (char*)dest;
	char *psrc = (char*)src;
	if (pdest >= psrc && pdest <= psrc + num) {		//��׼����Ϊ�Ļ������غ�����
		//����������Ӻ���ǰ����
		for (int64_t i = num - 1; i >= 0; --i) {	//int64_t�����ʹ��size_t2�����⣺1. i>=0 ����� 2.���num����Ϊ0����ôi�ʹӺܴ������ʼ����
			pdest[i] = psrc[i];
		}
	}
	else {
		for (size_t i = 0; i < num; ++i) {
			//����ԭ����memcpy��ʽ���в���
			pdest[i] = psrc[i];
		}
	}
	return dest;
}



//******************memcmp******************
int Memcmp(const void * ptr1,
	const void * ptr2,
	size_t num);
//��strncmp��ʹ�÷ǳ����ơ�



//******************strerror******************

//Ĭ������£�errnoֵΪ 0 �����ʹ����ĳЩ�⺯�����߲���ϵͳ��������Щ������ִ��ʧ�ܵ�ʱ�������errno��ֵ
//���ݷ��صĴ����룬���ض�Ӧ�Ĵ�����Ϣ
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