
//给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

//在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
//注意:
//假设字符串的长度不会超过 1010。

//示例 1:
//输入:
//"abccccdd"
//输出:
//7
//解释:
//我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。



//思路一
int longestPalindrome(char * s){
    int len = strlen(s);   
    int mark[128];      //128个ASCII码值，数组进行存储
    for(int i = 0;i < 128;++i){
        mark[i] = 0;
    }
    for(int i = 0;i < len;++i){
        mark[(int)s[i]] += 1;
    }
    int ans = 0;
    for(int i = 0;i < 128;++i){
        if(mark[i] % 2 == 0){
            ans += mark[i];
        }
        else{
            ans += (mark[i] - 1);
        }
    }
    if(ans < len){
        return ans + 1;
    }
    return ans;
}



//思路二
int longestPalindrome(char* s) {
    int i;
    int m = 1;    //当个数为奇数时第一个数需要加一，之后的数都不需要加一
    int count = 0;
    int x[58] = { 0 };    //小写a为97，大写A为65
    for(i = 0;s[i] != '\0';i++){
        x[s[i] - 'A']++;       //统计每个字符出现的个数
    }
    for(i = 0;i < 58;i++){
        if(x[i] > 1 && x[i] % 2 == 0)
            count += x[i];
        if(x[i] % 2 == 1){
            count += x[i] - 1 + m;
            m = 0;
        }
    }
    return count;
}
