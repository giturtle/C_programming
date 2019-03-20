#include <stdio.h>
#include <stdlib.h>
int main(){
  int a[3][4] = {1,3,5,7,9,11,13,15,17,19,21,21};
  int (*p)[4],i,j;
  p = a;
  printf("please enter row and column:");
  scanf("%d %d",&i,&j);
  printf("a[%d,%d] = %d\n",i,j,p[i][j]);
  return 0;
}

int main(){
  int a[4] = {1,3,5,7};
  int (*p)[4];
  p = &a;
  printf("%d\n",(*p)[3]);
  return 0;
}

//有一个班，3个学生，各学4门课，计算总平均分以及第n个学生的成绩
int main(){
  void avg(double *p,int n);
  void Find(double (*p)[4],int n);
  double score[3][4] = {{12,23,34,45},{23,34,45,56},{34,45,56,67}};
  avg(*score,12);
  Find(score,2);
  return 0;
}

void avg(double *p,int n){
  double *p_end;
  double sum = 0,avger;
  p_end = p+n-1;
  for(;p<=p_end;p++){
    sum = sum+(*p);
  }
  avger = sum/n;
  printf("avg = %lf\n",avger);
}

void Find(double (*p)[4],int n){
  int i;
  printf("The score of No.%d are:\n",n);
  for(i = 0;i < 4;++i){
    printf("%5.2lf ",p[n][i]);
  }
  printf("\n");
}
