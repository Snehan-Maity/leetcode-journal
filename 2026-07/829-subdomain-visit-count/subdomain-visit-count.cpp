class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mpp;
        for(auto str: cpdomains){
            int ind = str.find(' ');
            int n=stoi(str.substr(0, ind));
            string s=str.substr(ind+1);
            for(int i=0; i<s.size(); i++){
                if(s[i] == '.')     mpp[s.substr(i+1)] += n;
            }
            mpp[s] += n;
        }
        vector<string> res;
        for(auto k: mpp){
            res.push_back(to_string(k.second) + " " + k.first);
        }
        return res;
    }
};