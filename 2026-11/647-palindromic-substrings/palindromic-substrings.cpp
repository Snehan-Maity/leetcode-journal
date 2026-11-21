class Solution {
private:
    int helper(string s, int left, int right, int n){
        int cnt=0;
        while(left>=0 && right<n && s[left]==s[right]){
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int cnt=0, n=s.size();
        for(int i=0; i<n; i++){
            cnt += helper(s, i, i, n);
            cnt += helper(s, i, i+1, n);
        }
        return cnt;
    }
};