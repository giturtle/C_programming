#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



��1��25����Ȼ������˳�����һ��5��5�Ķ�ά������,Ȼ���������������ϰ�����
int main() {
	int a[5][5], i, j, k = 1;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			a[i][j] = k++;
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i > j) {
				printf("%4s", " ");
			}
			else {
				printf("%4d", a[i][j]);
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
}



//�Ӽ�������һ��Ӣ������,ͳ��������ĸ(�����ִ�Сд)����Ŀ
int main() {
	char str[300];
	int i, j;
	printf("������һ��Ӣ������:\n");
	gets(str);
	for (i = 0, j = 0; str[i]; i++) {
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
			j++;
		}
	}
	printf("�ַ����й���%d��Ӣ����ĸ.\n", j);
	system("pause");
	return 0;
}




//��д����,���������ַ���str��substr,ɾ�����ַ���str�е��������ַ���substr
int main() {
	char str[300], substr[300];
	int i, i1, j;
	printf("���������ַ���:\n");
	gets(str);
	printf("���������ַ���:\n");
	gets(substr);
	for (i = 0, i1 = 0; str[i1] != '\0';) {
		j = 0;
		while (str[i1] && substr[j] && str[i1] == substr[j]) {
			i1++;
			j++;
		}
		if (substr[j] == '\0') {
			continue;
		}
		else {
			i1 -= j;
			str[i++] = str[i1++];
		}
	}
	str[i] = '\0';
	printf("ɾ�����ַ�����,���ַ��������%s\n", str);
	system("pause");
	return 0;
}



//��д����,��һ���ַ���������
int main() {
	char str[256], temp;
	int i, j,len;
	printf("�������ַ���:");
	gets(str);
	len = strlen(str);
	for (i = 0, j = len - 1; i <= len / 2; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	printf("�������ַ�����:%s\n",str);
	system("pause");
	return 0;
}





//�Ӽ�������һ���ַ���,�����ַ����е��ַ�����
//Ȼ��������һ���ַ�,�����۰���ҷ����ҳ����ַ�����������ַ����е�λ��
//�����ַ������ַ�����,�����ʾ��Ϣ.
int main() {
	char arr[10];
	printf("������һ���ַ���:\n");
	scanf("%s", &arr);
	int left, right, mid;
	int i, j, k;
	for (i = 0; i < strlen(arr); i++) {
		k = i;
		for (j = i + 1; j < strlen(arr); j++) {
			if (arr[k] > arr[j]) {
				k = j;
			}
		}
		if (k != i) {
			int temp = 0;
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
	printf("�������ַ���:\n");
	printf("%s", arr);
	printf("������һ��Ҫ���ҵ��ַ�:\n");
	char to_find = getchar();
	left = 0;
	right = strlen(arr) - 1;
	if (to_find > arr[left] && to_find < arr[right]) {
		for (i = 0; i <= strlen(arr) - 1; i++) {
			mid = (left + right) / 2;
			if (to_find > arr[mid]) {
				left = mid + 1;
			}
			else if (to_find < arr[mid]) {
				right = mid - 1;
			}
			else {
				break;
			}
		}
	}
	if (left < right && mid != 0) {
		printf("�����±���%d\n", mid);
	}
	else {
		printf("û�ҵ�!\n");
	}
	system("pause");
	return 0;
}