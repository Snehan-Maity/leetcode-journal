class Solution {
public:
    int minimumPushes(string word) {
        int sz = word.size();
        if(sz>24)     return 8*1 + 8*2 + 8*3 + (sz-24)*4;
        else if(sz>16)    return 8*1 + 8*2 + (sz-16)*3;
        else if((sz>8))     return 8*1 + (sz-8)*2;
        else    return sz; 
    }
};