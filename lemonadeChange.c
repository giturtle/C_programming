
//在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
//顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
//注意，一开始你手头没有任何零钱。
//如果你能给每位顾客正确找零，返回 true ，否则返回 false 。



//输入：[5,5,5,10,20]
//输出：true

//输入：[5,5,10,10,20]
//输出：false
//解释：
//前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
//对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
//对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
//由于不是每位顾客都得到了正确的找零，所以答案是 false。

bool lemonadeChange(int* bills, int billsSize) {
    int five = 0,ten = 0;
    for(int i = 0;i < billsSize;i++){
        if(bills[i] == 5){
            five++;
        }
        else if(bills[i] == 10){
            if(five == 0){
                return false;
            }
            five--;
            ten++; 
        }
        else{
            if(ten > 0){
                ten--;
                if(five == 0){
                    return false;
                }
                else{
                    five--;
                }
            }
            else{
                five = five - 3;
                if(five < 0){
                    return false;
                }
            }
        }
    }
    return true;
}
