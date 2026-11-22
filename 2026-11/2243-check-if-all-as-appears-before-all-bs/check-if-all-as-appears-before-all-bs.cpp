class Solution {
public:
    bool checkString(string s) {
        bool flagB=false;
        for(char ch: s){
            if(flagB && ch=='a')   return false;
            else if(ch == 'b')   flagB=true;
        }
        return true;
    }
};