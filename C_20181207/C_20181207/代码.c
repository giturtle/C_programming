#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//дһ���������ز����������� 1 �ĸ���
//���磺 15: 0000 1111    4 �� 1

int BitOneCount(unsigned int num) {
	int count = 0;
	while (num) {
		if (num % 2 == 1) {
			++count;
		}
		num /= 2;
	}
	return count;
}
//������
//n = n & (n - 1)
//�� n �Ķ����ƴӵ�λ����λ���ΰ� 1 ��� 0
//���� n = 10 (1010),  n - 1 --> 1001,  n & (n - 1) --> 1000;  count++
//n = 1000,   n - 1 =   0111,  n & (n - 1) --> 0000;  count++;
int count_one(unsigned int n) {
	int count = 0;
	while (n) {
		count++;
		n = n & (n - 1);
	}
	return count;
}





//��ȡһ�������������������е�ż��λ/����λ
//�ֱ��������������.
��	��������������
void print_bits(int n) {
	int i = 0;
	//�����λ��
	// 1. ��ӡż��λ
	for (i = 31; i > 0; i -= 2) {
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	// 2. ��ӡ����λ
	for (i = 30; i >= 0; i -= 2) {
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
}

//��΢��̫����������������������
int main() {
	int num, count = 0;
	int a1[16];
	int a2[16];
	scanf("%d", &num);
	while (count < 32) {
		a1[count / 2] = num % 2;
		num = num >> 1;
		++count;
		a2[(count - 1) / 2] = num % 2;
		num = num >> 1;
		++count;
	}
	printf("������:\n");
	for (count = 15; count >= 0; count--) {
		printf("%d", a1[count]);
	}
	printf("\nż����:\n");
	for (count = 15; count >= 0; count--) {
		printf("%d", a2[count]);
	}
	system("pause");
	return 0;
}



//���һ��������ÿһλ��
int print(int x) {
	if (x > 9) {
		print(x / 10);
	}
	printf("%d\n", x % 10);
}
int main() {
	int num = 1234;
	print(num);
	system("pause");
	return 0;
}

//�ж�����������λ�ж��ٲ�ͬ
//�ٰ�λ�Ƚ�		(m >> (i - 1) & 1 ) == (n >> (i  - 1) & 1)

int bijiao(int m, int n) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (((m >> i) & 0x1) != ((n >> i) & 0x1)) {
			++count;
		}
	}
	return count;
}

//�����Ƚ�
//m 1999 -> 011111001111
//n 2299 -> 100011111011
//m ^ n -> 111100110100

int main() {
	uint32_t  m = 1999;
	uint32_t  n = 2299;
	int count = 0, chu = m ^ n;
	for (int i = 1; i <= 32; ++i) {
		if (chu % 2 == 1) {
			++count;
		}
		chu /= 2;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}


//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ�������� 
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�

//�������������,ֻ�üӷ�   ���ǻ��ж��ֿ���,���Ǳ�û������Լ��������
//���ֻ�ó˷�,����ֱ�����
//�˷��ͼӷ�һ��ʹ��һ���������

int main() {
	int a, b, c, d, e, c1, c2, c3, c4, c5;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						c1 = (b == 2) + (a == 3) == 1;
						c2 = (b == 2) + (e == 4) == 1;
						c3 = (c == 1) + (d == 2) == 1;
						c4 = (c == 5) + (d == 3) == 1;
						c5 = (e == 4) + (a == 1) == 1;
						if (c1 + c2 + c3 + c4 + c5 == 5 && a + b + c + d + e == 15 && a*b*c*d*e == 120)
						{
							printf("A:%d\nB:%d\nC:%d\nD:%d\nE:%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}









//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

int main() {
	char killer;
	for (killer = 'A'; killer <= 'K'; killer++) {
		if ((killer != 'A') + (killer == 'C') + (killer == 'D')
			+ (killer != 'D') == 3) {
			printf("killer is %c\n", killer);
		}
	}
	system("pause");
	return 0;
}


//�������

int main() {
	int s = 1, h;                    // ��ֵ�͸߶�
	int i, j;                        // ѭ������
	scanf("%d", &h);                 // �������
	printf(" 1\n");                   // �����һ�� 1
	for (i = 2; i <= h; s = 1, i++) {         // ���� i �� 2 �����	
		printf("1 ");                // ��һ�� 1
		for (j = 1; j <= i - 2; j++) // ��λ�� j �ƹ���һ��ֱ�ӿ�ʼѭ��
			//printf("%d ", (s = (i - j) / j * s));
			printf("%d ", (s = (i - j) * s / j));
		printf("1\n");               // ���һ�� 1������
	}
	system("pause");
	return 0;
}


//��������������ʵ�����鲿,������������������ʵ�����鲿
int main(){
	int a,b,c,d;
	printf("��������������ʵ�����鲿:\n(��ʽ:��һ������ʵ�����鲿,�ڶ�������ʵ�����鲿)\n");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int num1 = a * c - b * d;
	int num2 = a * d + b * c;
	printf("����������ʵ��Ϊ:%d\n�鲿Ϊ%d\n", num1, num2);
    system("pause");
    return 0;
}



//��������,����ת����Сʱ����������ʾ
//��������7278��,���:2Сʱ1��18��
int main(){
	int second = 0;
	printf("��������:\n");
	scanf("%u", &second);
	int minute, hour;
	hour = second / 3600;
	second %= 3600;
	minute = second / 60;
	second %= 60;
	printf("%dСʱ %d���� %d��\n", hour, minute, second);
    system("pause");
    return 0;
}

//����2Сд��ĸ��ֵ��ch1,ch2,ת��Ϊ��д,��������ֵ,���ch1,ch2
int main(){
	char ch1, ch2;
	printf("����������Сд��ĸ:\n");
	scanf("%c %c", &ch1, &ch2);
	ch1 = ch1 + ('A' - 'a');
	ch2 = ch2 + ('A' - 'a');
	char ret = 0;
	ret = ch1;
	ch1 = ch2;
	ch2 = ret;
	printf("ch1��%c,ch2��%c\n", ch1, ch2);
    system("pause");
    return 0;
}