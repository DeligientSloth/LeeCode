class Solution {
public:
    vector<int> get_next(string needle){
        int len=needle.length();
        vector<int> next(len,-1);
        int i=0,j=-1;
        while(i<len-1){
            if(j==-1||needle[i]==needle[j]) next[++i]=++j;
            else j=next[j];
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        //if(haystack.empty()||needle.empty()) return -1;
        vector<int> next=get_next(needle);
        int i=0,j=0,len_h=haystack.length(),len_n=needle.length();
        while(i<len_h&&j<len_n){
            if(j==-1||haystack[i]==needle[j]){
                ++i;++j;
            }
            else j=next[j];
        }
        if(j>=len_n) return i-j;
        return -1;
    }
};