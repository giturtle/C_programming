#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//��a��ͬѧ��ÿ��ѧ����b�ſγ̳ɼ���Ҫ�����û�����ѧ����ź��������ѧ����ȫ���ɼ�����ָ�뺯��ʵ��
int main(){
  double score[3][4] = {60,70,80,90,56,89,67,88,34,78,90,66};
  double *search(double (*p)[4],int n);
  double *p;
  int i,k;
  printf("enter the number of student:");
  scanf("%d",&k);
  printf("the score of No.%d are :\n",k);
  p = search(score,k);
  for(i = 0;i < 4;i++){
    printf("%5.2lf\t",p[i]);
  }
  printf("\n");
  return 0;
}

double *search(double (*p)[4],int n){
  double *pt;
  pt = *(p+n);
  return pt;
}


//������������ѧ�����ҳ������в�����γ̵�ѧ������ѧ����
int main(){
  double score[][4] = {{60,70,30,90},{56,89,67,88},{34,78,90,66}};
  double *search(double (*p)[4]);
  double *p;
  int i,j;
  for(i = 0;i < 3;++i){
    p = search(score+i);
    if(p == score[i]){
      printf("No.%d score:",i);
      for(j = 0;j < 4;++j){
        printf("%5.2lf ",p[j]);
      }
      printf("\n");
    }
  }
}
double *search(double (*p)[4]){
  int i = 0;
  double *pt;
  for(;i < 4;++i){
    if(*(*p+i) < 60){
      pt = *p;
    }
  }
  return pt;
}


//�������ַ�������ĸ˳����С�������
  int i;
  void sort(char *arr[]);
  char *name[4] = {"hehe","where","are","you"};
  sort(name);
  for(i = 0;i < 4;++i){
    printf("%s\n",name[i]);
  }
  return 0;
}
void sort(char *arr[]){
  int i,j,k;
  char *temp;
  for(i = 0;i < 3;i++){
    k = i;
    for(j = i + 1; j < 4;j++){
      if(strcmp(arr[k],arr[j]) > 0){
        k = j;
      }
    }
    if(k != i){
       temp = arr[i];
       arr[i] = arr[k];
      arr[k] = temp;
    }
  }
}


//��һ��ָ�����飬��Ԫ�طֱ�ָ��һ�����������Ԫ�أ���ָ��ָ�����ݵ�ָ�����������������и���Ԫ�ص�ֵ
int a[5] = { 3,4,5,6,7 };
int *num[5] = { &a[0],&a[1],&a[2],&a[3],&a[4] };
int **p, i;
p = num;
for (i = 0; i < 5; i++) {
	printf("%d ", **p++);
}
return 0;
}
