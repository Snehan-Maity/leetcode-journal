class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mpp;
        int n=logs.size();
        for(int i=0; i<n; i++)  mpp[logs[i][0]].insert(logs[i][1]);
        vector<int> res(k);
        for(auto it: mpp)   res[it.second.size()-1]++;
        return res;
    }
};