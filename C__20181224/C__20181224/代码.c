#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



#define N 3
#define Y(n)((N+1)*n)
int main() {
	int z;
	z = 2 * (N + Y(5 + 1));
	//48 = 2*(N+ (N+1)*5+1)
	printf("%d\n", z);
	system("pause");
	return 0;
}



#define SQR(X) X*X
int main() {
	int a = 10, k = 2, m = 1;
	a /= SQR(k + m) / SQR(k + m);
	printf("%d\n", a);
	// 10 / 7 = 1
	system("pause");
	return 0;
}



#define SUB(X,Y)(X)*Y
int main() {
	int a = 3, b = 4;
	printf("%d", SUB(a++, b++));
	//12 = 3*4
	system("pause");
	return 0;
}



#define N 5
#define M1 N*3
#define M2 N*2
int main() {
	int i;
	i = M1 + M2;
	printf("%d\n", i);
	//25
	system("pause");
	return 0;
}


#define M(x,y,z) x*y+z
int main() {
	int a = 1, b = 2, c = 3;
	printf("%d\n", M(a + b, b + c, c + a));
	//12 = a+ b*b +c+c+a
	system("pause");
	return 0;
}



#define MA(x)x*(x-1)
int main() {
	int a = 1, b = 2;
	printf("%d\n", MA(1 + a + b));
	//8
	//1+a+ b*(1+a+b-1)
	system("pause");
	return 0;
}



#define MIN(x,y)(x)<(y)?(x):(y)
int main() {
	int i, j, k;
	i = 10; j = 15;
	k = 10 * MIN(i, j);
	printf("%d\n", k);
	//15
	//k = (10*i) < (j)?(i):(j);	
	system("pause");
	return 0;
}


#define R 3.0
#define PI 3.1415926
#define L 2*PI*R
#define S PI*R*R
int main() {
	printf("L = %f S = %f\n", L, S);
	//L = 18.849556 S = 28.274333
	system("pause");
	return 0;
}