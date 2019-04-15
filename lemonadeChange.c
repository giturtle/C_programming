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
