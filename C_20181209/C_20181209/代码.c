//��������,����ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ.
unsigned int reserve_bit(unsigned int value) {
	int sum = 0;
	for (int i = 0; i < 32; i++) {
		sum += ((value >> i) % 2) * pow(2, 31 - i);
	}
	return sum;
}






//��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ
// �� :���������һ��Ӹ�����
//�ŵ�:���Լ��㸡����,������
double mean1(double x, double y) {
	double num = (x - y) / 2 + y;
	return num;
}

// �� :( a + b ) / 2 --> a / 2 + b / 2 -->a >>1 + b >>1
// ȱ��:ֻ�ܼ������ͱ���.
int mean2(int x, int y) {
	x = x >> 1;
	y = y >> 1;
}




//һ��������ֻ��һ�����ֳ�����һ�Ρ�
//�����������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩?���( ^ )�ܺý�� ������򱣳�ԭֵ����
int main() {
	int arr[] = { 1,1,2,2,3,4,3,5,5,6,6 };
	int	ret = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		ret = ret ^ arr[i];
	}
	printf("����һ�ε�������:%d\n", ret);
	system("pause");
	return 0;
}

//����:
//(��������ε�����)
int main()
{
	int arr[] = { 1, 2, 3, 6, 6, 1,1, 2, 7, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = 0;
	int inter = 0;
	int retA = 0;
	int retB = 0;
	for (int i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}
	/*��ret���ұߵ�1*/
	inter = ret - (ret&(ret - 1));
	for (int i = 0; i < len; i++)
	{
		int a = (arr[i] >> (inter - 1)) % 2;   //ȡ��arr[i]�ĵ�interλ
		if (a == 0)
		{
			retA ^= arr[i];
		}
		else
		{
			retB ^= arr[i];
		}
	}
	printf("���������ε�������Ϊ:> %d,%d\n", retA, retB);
	system("pause");
	return 0;
}
//��һ���ַ����������Ϊ:"student a am i", 
//���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ��:
//1.����ʹ�ÿ⺯��
	 //��˼��  [��Ҫ�Լ���������]
//2.ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ�
	 //��˼��  [������strlen,���Ծ�Ҫ�õ�ָ����]
//˼·:
//student a am i  -->  i ma a tneduts -->  i am a student



int my_strlen(const char* arr)
{
	const char* ret = arr;
	while ((*ret++) != '\0');
	return ret - arr - 1;
}
void* reverse(char* p, char* q)
{
	char tem;
	while (p <= q)
	{
		tem = *p;
		*p++ = *q;
		*q-- = tem;
	}
}
char* reverse_str(const char* p)
{
	int size = my_strlen(p);
	const char* q = p + size - 1;
	const char* t = p;
	reverse(p, q);
	q = t;
	while (q <= t + size)
	{
		if ((*q == ' ') || (*q == '\0'))
		{
			--q;
			reverse(p, q);
			q += 2;
			p = q;
		}
		else
			q++;
	}
	return t;
}
int main()
{
	char arr[] = "student a am i";
	printf("%s\n", reverse_str(arr));
	system("pause");
	return 0;
}

