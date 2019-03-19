#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//有a个同学，每个学生有b门课程成绩，要求在用户输入学生序号后，能输出该学生的全部成绩，用指针函数实现
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


//针对上面程序中学生，找出其中有不及格课程的学生及其学生号
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


//将若干字符串按字母顺序由小到大输出
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


//有一个指针数组，其元素分别指向一个整型数组的元素，用指向指针数据的指针变量输出整型数组中各个元素的值
int a[5] = { 3,4,5,6,7 };
int *num[5] = { &a[0],&a[1],&a[2],&a[3],&a[4] };
int **p, i;
p = num;
for (i = 0; i < 5; i++) {
	printf("%d ", **p++);
}
return 0;
}
