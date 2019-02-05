#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//****************** strstr ******************
const char *Strstr(const char *str1, const char *str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	//��� str2 �ǿ��ַ������Ͳ����бȽ���:

	//ֻ���� 1 ���жϾ���ɱȽϣ��ţ�
	//ʱ�临�Ӷ� O( 1 )
	if (*str2 == '\0' || *str1 == '\0') {
		return NULL;
	}

	/*ֻ���� N ���жϾ���ɱȽ�
	ʱ�临�Ӷ� O( N )
	if (strlen(*str2) == '\0' || strlen(*str1) == '\0') {
		return NULL;
	}*/
	const char *black_ptr = str1;
	while (*black_ptr != '\0') {
		const char *red_ptr = black_ptr;
		const char *sub_ptr = str2;
		while (*red_ptr != '\0' && *sub_ptr != '\0' && (*red_ptr == *sub_ptr)) {
			++red_ptr;
			++sub_ptr;
		}
		if (*sub_ptr == '\0') {
			//�ҵ��Ӵ�������ָ��str1λ�õ�ָ��
			return black_ptr;
		}
		++black_ptr;
	}
	return NULL;
}

int main() {
	char str1[] = "mayamimyna";
	char str2[] = "ya";
	const char *p = Strstr(str1, str2);
	strncpy(p, "ga", 2);
	printf("%s\n", str1);
	system("pause");
	return 0;
}