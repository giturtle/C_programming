

//自主实现sqrt函数

int mySqrt(int x) {
    //牛顿迭代法
    double last = 0,res = 1;
    while(last != res){
        last = res;
        res = (res + x/res)/2;
    }
    return (int)res;
}
