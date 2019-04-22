

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

//示例 1:
//输入: s = "anagram", t = "nagaram"
//输出: true

//示例 2:
//输入: s = "rat", t = "car"
//输出: false


bool isAnagram(char* s, char* t) {
    //s串字符出现记正数，t串字符出现记负数，然后判断是否计数数组是否为零（s串、t串各个字符出现的次数抵消）
    //相当于数组实现哈希
    int i, x[26] = { 0 }, y[26] = { 0 };
	for (i = 0; s[i] != '\0'; i++)	x[s[i] - 'a']++;	//建立 s 的字符表 x
	for (i = 0; t[i] != '\0'; i++)	y[t[i] - 'a']++;	//建立 t 的字符表 y
	for (i = 0; i < 26; i++)							//比较两字符表是否相同
	if (x[i] != y[i])	return false;
	return true;
}
