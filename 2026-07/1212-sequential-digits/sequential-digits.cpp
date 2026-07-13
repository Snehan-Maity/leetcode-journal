class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        string l = to_string(low), h=to_string(high);
        vector<int> ans;
        for(int i=l.size(); i<=h.size(); i++){
            for(int j=0; j<=9-i; j++){
                string no = str.substr(j,i);
                int num = stoi(no);
                if(num>=low && num<=high)    ans.push_back(num);
            }
        }
        return ans;
    }
};