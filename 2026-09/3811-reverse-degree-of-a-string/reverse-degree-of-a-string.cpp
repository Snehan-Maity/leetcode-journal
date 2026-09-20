class Solution {
public:
    int reverseDegree(string s) {
        int i=0, ans=0;
        while(s[i] != '\0'){
            ans += (123-s[i])*(i+1);
            i++;
        }
        return ans;
    }
};