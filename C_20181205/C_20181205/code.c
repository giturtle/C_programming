//(�ݹ�)쳲���������
int fib(int x) {
	if (x <= 2) {
		return 1;
	}
	return fib(x - 1) + fib(x - 2);
}
//(�ǵݹ�)쳲���������
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Fib(int x) {
	if (x == 1 || x == 2) {
		return 1;
	}
	int f1 = 1;
	int f2 = 1;
	int c = 0;
	for (int i = 3; i <= x; i++) {
		c = f1 + f2;
		f1 = f2;
		f2 = c;
	}return c;
}




//�ǵݹ��дһ������ʵ��n^k
int CiFang(int n, int k) {
	int num = 1;
	if (n == 0) {
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		num *= n;
	}
	//����
	//	while (k--)
	//	{
	//		num *= n;
	//	}
	return num;
}
//�ݹ�ʵ��һ������n^k
int CiFang(int n, int k) {
	if (k < 0) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}
	return n * CiFang(n, k - 1);
}


//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�͡�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19��
int DigitSum(int n) {
	if (n < 10) {
		return n;
	}
	return n % 10 + DigitSum(n / 10);

	[�ҵĴ��]��
		int DigitSum(int n) {
		int sum = 0;
		int num = n / 10;
		sum += DigitSum(num % 10);
		return sum;
	}







	//��дһ������ reserve_string(char* string)(�ݹ�ʵ��)
	//ʵ��:�������ַ������ַ���������
	//Ҫ��:����ʹ��C�������е��ַ�����������
	// �� ��������һ������ �ڵ������
	// �� ָ�� : (ָ�������)��β���ݽ���,ͷָ��++,βָ��--

	//�����Լ���strlen,��ʹ�ÿ⺯����
	int mystrlen(char* str) {
		int count = 0;
		while (*str) {
			count++;
			str++;
		}
		return count;
	}

	//�ǵݹ�
	void reverse_string(char* str) {
		char* start = str;
		char* end = str + mystrlen(str) - 1;
		while (start < end) {
			char tmp;
			tmp = *start;
			*start = *end;
			*end = tmp;
			start++;
			end--;
		}
	}

	//�ݹ�
	void reverse(char* str) {
		if (*str) {
			char* start = str;
			char* end = str + mystrlen(str) - 1;
			//��β���ݻ���
			char temp = *start;
			*start = *end;
			//β��������ʱ��Ϊ������ʶ��
			*end = '\0';
			//��ת�Ӵ�
			reverse(start + 1);
			//�ָ�β������
			*end = temp;
		}
	}

	int main() {
		//char str[] = "abcdef";
		char str[100] = { 0 };
		scanf("%s", &str);

		reverse_string(str);
		printf("%s\n", str);

		reverse(str);
		printf("%s", str);

		system("pause");
		return 0;
	}





	//�ݹ�ʵ��strlen
	//��
	int Strlen(const char *str) {
		if (*str == '\0') {
			return 0;
		}
		else {
			return 1 + Strlen(str + 1);
		}
	}
	//�ݹ�
	int m_strlen(char* str) {
		if (*str)
			//�ȼ���if (*string != '\0')
		{
			return 1 + m_strlen(str + 1);
		}
		return 0;

	}
	//�ǵݹ�
	int feistrlen(char* str) {
		int count = 0;
		while (*str) {
			count++;
			str++;
		}
		return count;
	}





	//�ǵݹ�ʵ��n�Ľ׳�
	int JieCheng(int n) {
		if (n <= 1) {
			return  1;
		}
		int num = 1;
		for (int i = 1; i <= n; ++i) {
			num *= i;
		}
		return num;
	}
	//�ݹ�ʵ��n�Ľ׳�
	int JieCheng(int n) {
		if (n <= 1) {
			return 1;
		}
		return n * JieCheng(n - 1);



		//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
		int PrintNum(int x) {
			if (x > 9) {
				PrintNum(x / 10);
			}
			printf("%d\n", x % 10);
		}
		//�ǵݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ̫���� 




