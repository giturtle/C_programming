
//������һ����λ����0000 ~ 9999������Ƴ���ǧλ����λ��ʮλ����λ���ֱ����
//2014 --> ǧλ����2����λ����0����
#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "������һ��ǧλ����" << endl;
	cin >> num;
	cout << num << "��ǧλ���ǣ�" << num / 1000 % 10 << endl;
	cout << num << "�İ�λ���ǣ�" << num / 100 % 10 << endl;
	cout << num << "��ʮλ���ǣ�" << num / 10 % 10 << endl;
	cout << num << "�ĸ�λ���ǣ�" << num % 10 << endl;
	system("pause");
	return 0;
}


//����������ı��ʽ
#include <iostream>
using namespace std;
int main() {
	float a, b, c, temp;
	char oper1, oper2;
	cout << "��������ʽ(��1+2*3)��" << endl;
	cin >> a >> oper1 >> b >> oper2 >> c;
	switch (oper1) {
	case '+': {
		switch (oper2) {
		case '+': cout << a << oper1 << b << oper2 << c << '=' << a + b + c << endl; break;
		case '-': cout << a << oper1 << b << oper2 << c << '=' << a + b - c << endl; break;
		case '*': cout << a << oper1 << b << oper2 << c << '=' << a + (b * c) << endl; break;
		case '/': if (c != 0) { cout << a << oper1 << b << oper2 << c << '=' << a + (b * c) << endl; break; }
				  else { cout << "�������" << endl; break; }
			break;
		}
		break;
	}
	case '-': {
		switch (oper2) {
		case '+': cout << a << oper1 << b << oper2 << c << '=' << a - b + c << endl; break;
		case '-': cout << a << oper1 << b << oper2 << c << '=' << a - b - c << endl; break;
		case '*': cout << a << oper1 << b << oper2 << c << '=' << a - (b * c) << endl; break;
		case '/': if (c != 0) { cout << a << oper1 << b << oper2 << c << '=' << a - (b / c) << endl; break; }
				  else {cout << "�������" << endl; break;}
			break;
		}
		break;
	}
	case '*': {
		temp = a * b;
		switch (oper2) {
		case '+': cout << a << oper1 << b << oper2 << c << '=' << temp + c << endl; break;
		case '-': cout << a << oper1 << b << oper2 << c << '=' << temp - c << endl; break;
		case '*': cout << a << oper1 << b << oper2 << c << '=' << temp * c << endl; break;
		case '/': if (c != 0) { cout << a << oper1 << b << oper2 << c << '=' << temp / c << endl; break; }
				  else { cout << "�������" << endl; break; }
			break;
		}
		break;
	}
	case '/': {
		if (b != 0) {
			temp = a / b;
		}
		else {
			cout << "�������" << endl; break;
		}
		switch (oper2) {
		case '+': cout << a << oper1 << b << oper2 << c << '=' << temp + c << endl; break;
		case '-': cout << a << oper1 << b << oper2 << c << '=' << temp - c << endl; break;
		case '*': cout << a << oper1 << b << oper2 << c << '=' << temp * c << endl; break;
		case '/': if (b != 0 && c != 0) { cout << a << oper1 << b << oper2 << c << '=' << temp / c << endl; break; }
				  else { cout << "�������" << endl; break; }
			break;
		}
		break;
	}
	}
	system("pause");
	return 0;
}
//���Զ����һ�� <cstdlib>ͷ�ļ�����exit(1);����  �滻�������ڲ��break;���ֱ������
#include <cstdlib>
//ÿ��case��������ݾ�������ʾ��
//������ת˲���ţ��޷�������ʾ���ݣ�system("pause");û������
case '+': {
	switch (oper2) {
	case '+': cout << a << oper1 << b << oper2 << c << '=' << a + b + c << endl; exit(1);
	case '-': cout << a << oper1 << b << oper2 << c << '=' << a + b - c << endl; exit(1);
	case '*': cout << a << oper1 << b << oper2 << c << '=' << a + (b * c) << endl; exit(1);
	case '/': if (c != 0) { cout << a << oper1 << b << oper2 << c << '=' << a + (b * c) << endl; exit(1); }
			  else { cout << "�������" << endl; exit(1); }
	}
}


//������ʽ
#include <iostream>
using namespace std;
int main() {
	float a, b;
	char oper;
	cout << "������һ�����ʽ(��1+2)��" << endl;
	cin >> a >> oper >> b;
	//��
	if (oper == '+') {
		cout << a << oper << b << '=' << a + b << endl;
	}
	else if (oper == '-') {
		cout << a << oper << b << '=' << a - b << endl;
	}
	else if (oper == '*') {
		cout << a << oper << b << '=' << a * b << endl;
	}
	else if (oper == '/' && b != 0) {
		cout << a << oper << b << '=' << a / b << endl;
	}
	else {
		cout << "�������!" << endl;
	}
	////��ͬ�ڢ�
	//switch (oper) {
	//case '+': cout << a << oper << b << '=' << a + b << endl; break;
	//case '-': cout << a << oper << b << '=' << a - b << endl; break;
	//case '*': cout << a << oper << b << '=' << a * b << endl; break;
	//case '/': if (b != 0) { cout << a << oper << b << '=' << a / b << endl; break; }
	//		  else {cout << "�������!" << endl; break; }
	//default: cout << "�������!" << endl;
	//}
	system("pause");
	return 0;
}



#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cout << "������ax^2 + bx + c = 0������ϵ��a,b,c��" << endl;
	cin >> a >> b >> c;
	if (a == 0) {
		cout << "��һԪ���η��̣�" << endl;
	}
	else if (b*b - 4 * a*c >= 0) {
		cout << "��ʵ���⣡" << endl;
	}
	else
		cout << "��ʵ���⣡" << endl;
	system("pause");
	return 0;
}


#include <iostream>
using namespace std;
int main() {
	cout << 0 && !2 + 5 || 1 && !(2 + !0);
	cout << (1 || 0) && 0;
	system("pause");
	return 0;
}



#include <iostream>
using namespace std;
int main() {
	int mark;
	cout << "������ɼ�(0 ~ 100):" << endl;
	cin >> mark;
	if (mark >= 90 && mark <= 100) cout << "����" << endl;
	else if (mark >= 80 && mark < 90) cout << "����" << endl;
	else if (mark >= 70 && mark < 80) cout << "����" << endl;
	else if (mark >= 60 && mark < 70) cout << "����" << endl;
	else if (mark < 0 || mark > 100) cout << "�������" << endl;
	else cout << "������" << endl;
	system("pause");
	return 0;
}


//�򵥵Ĳ�����С��Ϸ
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


#include <iostream>
using namespace std;
int main() {
	int a, b;
	cout << "��������������"<<endl;
	cin >> a >> b;
	if (a > b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	cout << "����������С�������Ϊ:";
	cout << a << " " << b << endl;
	system("pause");
	return 0;
}
