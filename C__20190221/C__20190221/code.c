#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Ӽ��̶������ɵ��ַ����������ǰ�����ĸ��С��˳������Ȼ����ź�����ַ����͵������ļ��б���
int main() {
	FILE *fp;
	char str[3][10], temp[10];
	int i, j, k;
	int n = 3;
	printf("�������ַ���:\n");
	for (i = 0; i < n; ++i) {
		gets(str[i]);
	}
	for (i = 0; i < n - 1; ++i) {
		k = i;
		for (j = i + 1; j < n; ++j) {
			if (strcmp(str[k], str[j]) > 0)
				k = j;
		}
		if (k != i) {
			strcpy(temp, str[i]);
			strcpy(str[i],str[k]);
			strcpy(str[k],temp);
		}
	}
	if ((fp = fopen("D:\\CC\\string.dat", "w")) == NULL) {
		printf("can't open this file!\n");
		exit(0);
	}
	printf("\n the new sequence:\n");
	for (i = 0; i < 3; ++i) {
		fputs(str[i], fp);
		fputs("\n", fp);
		printf("%s\n", str[i]);
	}
	system("pause");
	return 0;
}


//��һ�������ļ��е���Ϣ���Ƶ���һ�������ļ��У���Ҫ������file1.dat�ļ��е����ݸ��Ƶ���һ�������ļ�file2.dat��
int main() {
	FILE *in, *out;
	char ch, infile[10], outfile[10];
	printf("��������ļ�������:");
	scanf("%s", infile);
	printf("��������ļ�������:");
	scanf("%s", outfile);
	if ((in = fopen(infile, "r")) == NULL) {
		printf("�޷����ļ�!\n");
		exit(0);
	}
	if ((out = fopen(outfile, "w")) == NULL) {
		printf("�޷����ļ�!\n");
		exit(0);
	}
	while (!feof(in)) {		//���δ���������ļ��Ľ�����־
		ch = fgetc(in);		//�������ļ�����һ���ַ����ݷ��ڱ���ch��
		fputc(ch, out);		//��chд������ļ���
		putchar(ch);		//��ch��ʾ����Ļ��
	}
	putchar(10);
	fclose(in);
	fclose(out);
	system("pause");
	return 0;
}


//�Ӽ�������һЩ�ַ�������������͵�������ȥ��ָ���û�����һ��"#"Ϊֹ
int main() {
	FILE *fp;
	char filename[20], ch;
	printf("���������õ��ļ���:\n");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("�޷��򿪴��ļ�!\n");
		exit(0);
	}
	ch = getchar();
	printf("������һ��׼�����浽���̵��ַ���(��#��β):\n");
	ch = getchar();
	while (ch != '#') {
		fputc(ch, fp);
		putchar(ch);
		ch = getchar();
	}
	fclose(fp);
	putchar(10);
	system("pause");
	return 0;
}
