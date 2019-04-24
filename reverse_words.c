
//https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

//示例 1:
//输入: "Let's take LeetCode contest"
//输出: "s'teL ekat edoCteeL tsetnoc" 
//注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。



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
