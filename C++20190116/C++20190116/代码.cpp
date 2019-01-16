
//猜数字小游戏
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	srand((unsigned int)time(NULL));
	int num = rand() % 5 + 1, input;
	cout << "请在 1 ~ 6中随便猜一个数字" << endl;
	cin >> input;
	if (input == num) {
		cout << "猜对了！" << endl;
		system("pause");
		return 0;
	}
	cout << "猜错了，还有2次机会！"<<endl << "请输入：" << endl;
	cin >> input;
	if (input == num) {
		cout << "猜对了！" << endl;
		system("pause");
		return 0;
	}
	cout << "猜错了，还有1次机会！" << endl << "请输入：" << endl;
	cin >> input;
	if (input == num) {
		cout << "猜对了！" << endl;
		system("pause");
		return 0;
	}
	cout << "挑战失败！答案是:" << num << endl;
	system("pause");
	return 0;
}





//#include <iostream>
//using namespace std;
//int main() {
//	int a, b;
//	cout << "请输入两个数："<<endl;
//	cin >> a >> b;
//	if (a > b) {
//		int temp;
//		temp = a;
//		a = b;
//		b = temp;
//	}
//	cout << "这两个数从小到大输出为:";
//	cout << a << " " << b << endl;
//	system("pause");
//	return 0;
//}