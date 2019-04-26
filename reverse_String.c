
//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

//示例 1:
//输入: "Let's take LeetCode contest"
//输出: "s'teL ekat edoCteeL tsetnoc" 


//解法一
void reverse(char *s,int begin,int index){
    while(begin < index){
        char t = s[begin];
        s[begin] = s[index];
        s[index] = t;
        begin++;
        index--;
    }
}
char* reverseWords(char* s) {
    if(s == NULL){
        return NULL;
    }
    int begin = 0;
    int i = 0;
    int len = strlen(s);
    for(;i < len;i++){
        if(s[i] != ' ' && i != len - 1){
            continue;
        }
        if(i != len - 1){
            reverse(s,begin,i-1);
            begin = i + 1;
        }
        else{
            reverse(s,begin,i);
        }
    }
    return s;
  
    
      
    /*解法二*/
    /*
    char[] str=s.toCharArray();
        int start=0,i=0;
        while(i<str.length)
        {
            while(i<str.length&&str[i]!=' ') //顺序不能颠倒
            {
                i++;
            }
            int end=i-1;  //此时i指向空格或者str.length
            while(start<end)
            {
                char c=str[start];
                str[start++]=str[end];
                str[end--]=c;
            }
            start=++i;
        }
        return new String(str); 
    
    
    */
    
    
    
    //超出时间限制
    /*
    char *str = s;
    while(*str != '\0') {
        char *start = str;
        char *end = str;
        while(*end != ' '){
            end++;
        }
        while(start < (end - 1)){
           char t = *start;
            *start = *end;
            *end = t;
            start++;
            end--;
        }
        str = end + 1;
    }
    return s;
    */
}
