
//������С��Ϸ
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	srand((unsigned int)time(NULL));
	int num = rand() % 5 + 1, input;
	cout << "���� 1 ~ 6������һ������" << endl;
	cin >> input;
	if (input == num) {
		cout << "�¶��ˣ�" << endl;
		system("pause");
		return 0;
	}
	cout << "�´��ˣ�����2�λ��ᣡ"<<endl << "�����룺" << endl;
	cin >> input;
	if (input == num) {
		cout << "�¶��ˣ�" << endl;
		system("pause");
		return 0;
	}
	cout << "�´��ˣ�����1�λ��ᣡ" << endl << "�����룺" << endl;
	cin >> input;
	if (input == num) {
		cout << "�¶��ˣ�" << endl;
		system("pause");
		return 0;
	}
	cout << "��սʧ�ܣ�����:" << num << endl;
	system("pause");
	return 0;
}





//#include <iostream>
//using namespace std;
//int main() {
//	int a, b;
//	cout << "��������������"<<endl;
//	cin >> a >> b;
//	if (a > b) {
//		int temp;
//		temp = a;
//		a = b;
//		b = temp;
//	}
//	cout << "����������С�������Ϊ:";
//	cout << a << " " << b << endl;
//	system("pause");
//	return 0;
//}