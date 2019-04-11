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
