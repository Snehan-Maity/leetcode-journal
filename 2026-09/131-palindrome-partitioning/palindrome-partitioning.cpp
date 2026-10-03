class Solution {
private:
    bool isPalindrome(string str){
        int sz = str.size();
        for(int i=0; i<sz/2; i++)
            if(str[i] != str[sz-1-i])   return false;
        return true;
    }

    void check(string s, int st, int n, vector<string> &temp, vector<vector<string>> &res){
        if(st == n){
            res.push_back(temp);
            return;
        }
        for(int i=st; i<n; i++){
            string str = s.substr(st, i-st+1);
            if(isPalindrome(str)){
                temp.push_back(str);
                check(s, i+1, n, temp, res);
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int n=s.size();
        check(s, 0, n, temp, res);
        return res;
    }
};