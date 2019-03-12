#include <stdio.h>
#include <stdlib.h>
//查找有一门以上课程不及格的学生，输出他们的全部课程成绩
int main(){
  void search(float (*p)[4],int n) ;
  float score[3][4] = {{23,45,64,23},{23,76,98,22},{54,98,21,83}};
  search(score,3);
  return 0;
}

void search(float (*p)[4],int n){
  int i,j,flag;
  for(i = 0;i < n;++i){
    flag = 0;
    for(j = 0;j < 4;++j){
      if(*(*(p+i)+j) < 60){
        flag = 1;
      }
    }
    if(flag == 1){
      printf("No.%d fails,his scores are:\n",i+1);
      for(j = 0; j < 4;++j){
        printf("%5.1f ",*(*(p+i)+j));
      }
      printf("\n");
    }
  }
}

