//构建函数,返回值value的二进制位模式从左到右翻转后的值.
unsigned int reserve_bit(unsigned int value) {
	int sum = 0;
	for (int i = 0; i < 32; i++) {
		sum += ((value >> i) % 2) * pow(2, 31 - i);
	}
	return sum;
}






//不使用（a+b）/2这种方式，求两个数的平均值
// ① :二者作差分一半加给减数
//优点:可以计算浮点数,负数等
double mean1(double x, double y) {
	double num = (x - y) / 2 + y;
	return num;
}

// ② :( a + b ) / 2 --> a / 2 + b / 2 -->a >>1 + b >>1
// 缺点:只能计算整型变量.
int mean2(int x, int y) {
	x = x >> 1;
	y = y >> 1;
}




//一组数据中只有一个数字出现了一次。
//其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）?异或( ^ )很好解决 两次异或保持原值不变
int main() {
	int arr[] = { 1,1,2,2,3,4,3,5,5,6,6 };
	int	ret = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		ret = ret ^ arr[i];
	}
	printf("出现一次的数字是:%d\n", ret);
	system("pause");
	return 0;
}

//延伸:
//(输出奇数次的数字)
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
	/*找ret最右边的1*/
	inter = ret - (ret&(ret - 1));
	for (int i = 0; i < len; i++)
	{
		int a = (arr[i] >> (inter - 1)) % 2;   //取出arr[i]的第inter位
		if (a == 0)
		{
			retA ^= arr[i];
		}
		else
		{
			retB ^= arr[i];
		}
	}
	printf("出现奇数次的两个数为:> %d,%d\n", retA, retB);
	system("pause");
	return 0;
}
//有一个字符数组的内容为:"student a am i", 
//请你将数组的内容改为"i am a student". 
//要求:
//1.不能使用库函数
	 //意思是  [需要自己构建函数]
//2.只能开辟有限个空间（空间个数和字符串的长度无关）
	 //意思是  [不能用strlen,所以就要用到指针了]
//思路:
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

