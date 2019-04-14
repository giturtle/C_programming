char* countAndSay(int n) {
	if (n == 1)return "1";
	if (n == 2)return "11";
	char shuzu[10000], shu[10000] = "11";
	int a = 1, b = 1, c = 0, s;
	for (int number = 3; number <= n; number++)
	{
		memcpy(shuzu, shu, sizeof(shu));
		a = b = 1;
		c = 0;
		s = strlen(shu);
		while (a < s)
		{
			if (shuzu[a - 1] == shuzu[a])b++;
			else {
				shu[c] = b + '0';
				shu[++c] = shuzu[a - 1];
				c++;
				b = 1;
			}
			a++;
		}
		if (a == s) {
			shu[c] = b + '0';
			shu[c + 1] = '1';
		}
	}
	return shu;
}

char *countAndSay(int n)
{
	int a[5000] = { 0 }; // 初始或上一个项的报数序列，现在是int型
	a[0] = 1;         //  第一个项是1
	int b[5000] = { 0 }; // 目前的或下一个项的报数序列，现在是int型

	int i = 0; // a[]数组的下标
	int count = 0;
	int j = 0; // b[]数组的下标
	for (int h = 1; h < n; h++)
	{
		i = 0;
		j = 0;
		int t = a[0]; // 临时中间量，用于存放相邻的相同的数值，以及对比
		while (0 != a[i])
		{
			if (t == a[i])
			{
				count++; // 这个数的数量统计
				i++;
			}
			else
			{
				b[j] = count; // 遇到了不相同的数了，需要把之前相同的数的个数、值寄存到b[]数组中
				b[j + 1] = t;
				b[j + 3] = a[i];
				j = j + 2;
				t = a[i];
				i++;
				count = 1; // 下一个数的个数，需要重新统计
			}
		}
		b[j] = count;
		b[j + 1] = t;
		count = 0;

		// 把 b[]全部交给a[]，开始下一项的取值
		int m = 0;
		while (0 != b[m])
		{
			a[m] = b[m];
			m++;
		}
	}

	char *c = (char *)malloc(5000);
	if (NULL == c)
	{
		printf("char *c malloc failed.\n");
		exit(1);
	}
	int m = 0;
	while (0 != a[m])
	{
		c[m] = a[m] + 48; // 数字0的ASCII码是48
		m++;
	}
	c[m] = '\0';
	return c;
}


bool* prefixesDivBy5(int* A, int ASize, int* returnSize) {
	if (NULL == A || ASize <= 0 || ASize > 30000 || NULL == returnSize)
		return NULL;
	int iMantissa = 0, i = 0;

	//申请结点空间，全部初始化为false
	bool *pResult = malloc(sizeof(bool) * ASize);
	memset(pResult, false, sizeof(*pResult));

	*returnSize = ASize;
	while (i < ASize) {
		//iMantissa <<= 1;
		iMantissa *= 2;
		if (iMantissa > 10)
			iMantissa %= 10;
		if (A[i] != 0)
			iMantissa += 1;
		pResult[i++] = (iMantissa == 5 || iMantissa == 0 || iMantissa == 10);
	}
	return pResult;
}




int* shortestToChar(char* S, char C, int* returnSize) {
	int i = 0;
	int len = strlen(S);
	int *buff = malloc(sizeof(int)*len);
	char *p = S, *q = S;

	for (i = 0; i < len; i++) {
		p = &S[i];
		q = &S[i];
		while (p >= &S[0] && q <= &S[len - 1]) {
			if (*p == C || *q == C) break;
			if (p > &S[0])            p--;
			if (q < &S[len - 1])        q++;
		}

		if (*p == C) {
			buff[i] = abs(&S[i] - p);
		}
		else if (*q == C) {
			buff[i] = abs(&S[i] - q);
		}
		else
			continue;
	}

	*returnSize = len;
	return buff;
}
