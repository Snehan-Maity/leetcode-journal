class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(char &it: word)     freq[it-'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        int res=0, i=0;
        while(i<26 && freq[i]!=0){
            if(i<8) res += freq[i] * 1;
            else if(i<16)   res += freq[i] * 2;
            else if(i<24)   res += freq[i] * 3;
            else    res += freq[i] * 4;
            i++;
        }
        return res;
    }
};