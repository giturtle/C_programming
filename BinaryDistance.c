
//给定一个正整数 N，找到并返回 N 的二进制表示中两个连续的 1 之间的最长距离。 
//如果没有两个连续的 1，返回 0 。

//输入：22
//输出：2
//解释：
//22 的二进制是 0b10110 。
//在 22 的二进制表示中，有三个 1，组成两对连续的 1 。
//第一对连续的 1 中，两个 1 之间的距离为 2 。
//第二对连续的 1 中，两个 1 之间的距离为 1 。
//答案取两个距离之中最大的，也就是 2 。


int binaryGap(int N) {
	int ret = 0, tmp = 0;
	while ((N & 0x1) != 1) {
		N >>= 1;
	}
	while (N > 0) {
		if ((N & 0x1) == 1) {
			ret = tmp > ret ? tmp : ret;
			tmp = 0;
		}
		tmp++;
		N >>= 1;
	}
	return ret;
}
void test1() {
	printf("%d\n", binaryGap(22));
	system("pause");
}
