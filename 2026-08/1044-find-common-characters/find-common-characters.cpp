class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end());
        for(char ch: words[0]){
            bool same = true;
            for(int i=1; i<words.size(); i++){
                if(words[i].find(ch) == string::npos){
                    same = false;
                    break;
                }
                else    words[i].erase(words[i].find(ch), 1);

            }
            if(same)    res.push_back(string(1,ch));
        }
        return res;
    }
};