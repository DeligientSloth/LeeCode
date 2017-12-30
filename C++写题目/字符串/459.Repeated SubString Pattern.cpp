class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.length();//长度
        int l,i;//可能的长度,以及字符串遍历指针
        for(l=1;l<=len/2;l++){
            if(len%l) continue;
            for(i=l;i<len;i++){
                if(s[i]!=s[i%l]) break;
            }
            if(i==len) return true;
        }
        return false;
    }
};