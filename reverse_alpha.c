

//编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

//示例 1:
//输入: "hello"
//输出: "holle"

//示例 2:
//输入: "leetcode"
//输出: "leotcede"




bool isYY(char *ch){
    if((*ch == 'a')||(*ch == 'e')||(*ch == 'i')||(*ch == 'o')||(*ch == 'u') || (*ch == 'A') || (*ch == 'E') ||(*ch == 'I')
      ||(*ch == 'O') || (*ch == 'U')){
        return true;
    }
    return false;
}
char* reverseVowels(char* s) {
    /*写法一*/
    /*
    if(s == NULL){
        return false;
    }
    int i = 0,j = strlen(s) - 1;
    while(i < j){
        for(;i < j;i++){
            if(isYY(&s[i])){
                break;
            }
        }
        for(;i < j;j--){
            if(isYY(&s[j])){
                break;
            }
        }
        if(i < j){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
    return s;
    */
    
    /*写法二*/
    
    char *start = s;
    char *end = s + strlen(s) - 1;
    while(start < end){
        for(;start < end;start++){
            if(isYY(start)){
                break;
            }
        }
        for(;start < end;end--){
            if(isYY(end)){
                break;
            }
        }
        if(start < end){
            char t = *start;
            *start = *end;
            *end = t;
            start++;
            end--;
        }
    }
    return s;
}
