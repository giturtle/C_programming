#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\test.txt", "r");
	if (fp != NULL) {
		fputs("fopen example", fp);
		fclose(fp);
	}
	system("pause");
	return 0;
}


//�ı��ļ�
int main(){
	int c;//��char��Ҫ����EOF
	FILE* fp = fopen("test.txt", "r");
	if (!fp) {
		perror("File opening failed");
		return EXIT_FAILURE;
	}
	//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
	while ((c = fgetc(fp)) != EOF){ // ��׼C I/O��ȡ�ļ�ѭ��
		putchar(c);
	}
	//�ж���ʲôԭ�������
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");

	fclose(fp);
	return 0;
}


//�������ļ�
enum {SIZE = 5};
int main() {
	double a[SIZE] = { 1.0,2.0,3.0,4.0,5.0 };
	double b[SIZE] = { 0.0 };
	size_t ret_code = 0;
	FILE *fp = fopen("test.bin", "wb");//ʹ�õ��Ƕ�����ģʽ
	fwrite(a, sizeof(*a), SIZE, fp);
	fclose(fp);

	fp = fopen("test.bin", "rb");
	ret_code = fread(b, sizeof *b, SIZE, fp); // �� double ������
	if (ret_code == SIZE) {
		puts("Array read successfully, contents: ");
		for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
		putchar('\n');
	}
	else { // error handling
		if (feof(fp))
			printf("Error reading test.bin: unexpected end of file\n");
		else if (ferror(fp)) {
			perror("Error reading test.bin");
		}
	}
	fclose(fp);
	return 0;
}
