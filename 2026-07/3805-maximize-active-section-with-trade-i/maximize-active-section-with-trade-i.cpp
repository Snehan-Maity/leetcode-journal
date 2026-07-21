class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size(), cnt=0;
        for(int i=0; i<n; i++)  if(s[i]=='1')   cnt++;
        int prevZeros = -1, ans=0, i=0;
        while(i<n){
            int j=i;
            while(j<n && s[j]==s[i])    j++;
            int len=j-i;
            if(s[i] == '0'){
                if(prevZeros != -1)     ans = max(ans, prevZeros+len);
                prevZeros = len;
            }
            i=j;
        }
        return cnt+ans;
    }
};