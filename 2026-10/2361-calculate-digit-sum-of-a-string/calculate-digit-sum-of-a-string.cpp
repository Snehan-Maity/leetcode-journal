class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int n=s.size();
            string str;
            for(int i=0; i<n; i+=k){
                int val=0;
                for(int j=i; j<min(i+k, n); j++)
                    val += s[j]-'0';
                str.append(to_string(val));
            }
            s=str;
        }
        return s;
    }
};