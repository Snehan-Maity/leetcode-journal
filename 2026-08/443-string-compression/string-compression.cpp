class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0, l=0, r=0;
        while(r < n){
            int cnt=0;
            while(r<n && chars[l] == chars[r]){
                cnt++;
                r++;
            }
            chars[i++] = chars[l];
            if(cnt>1){
                string s = to_string(cnt);
                int j=0;
                while(j < s.size()){
                    chars[i++] = s[j];
                    j++;
                }
            }
            l = r;
        }
        return i;
    }
};