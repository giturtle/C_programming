#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define LETTER 0
int main() {
	char str[20] = "C LANGUAGE", c;
	int i;
	i = 0;
	while ((c = str[i]) != '\0') {
		i++;
#if LETTER
		if (c >= 'a' && c <= 'z') {
			c = c - 32;
		}
#else
		if (c >= 'A' && c <= 'Z') {
			c = c + 32;
		}
#endif
		printf("%c", c);
		//c language
		//�����б��ʽ LETTER ��ֵΪ 0 
		//���Ա���if(c >= 'A' && c <= 'Z') c = c+32���
		//���ȫ�������Сд
	}
	system("pause");
	return 0;
}
//#if (�������ʽ)      //�������ʽ���㣬��������1�������������2��
//�����1           //�������ʽ���Բ������ţ�
//#else
//�����2
//#endif



#define N 4+1
#define M N*2+N
#define RE 5*M+M*N
int main() {
	printf("%d\n", RE / 2);
	// 41 = (5*4+1*2)+(4+1)+(4+1*2)+(4+1*4+1/2)
	system("pause");
	return 0;
}


#define N 2
#define M N+1
#define NUM 2*M+1
int main() {
	int i;
	for (i = 1; i < NUM; i++) {
		printf("%d\n", i);
		//ѭ������:6 
		//2*N +1+1
	}
	system("pause");
	return 0;
}



#define f(x) x*x
int main() {
	int a = 6, b = 2, c;
	c = f(a) / f(b);
	printf("%d\n", c);
	//36 = 6*6/2*2
	system("pause");
	return 0;
}