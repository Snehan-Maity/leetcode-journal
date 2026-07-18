class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        unordered_map<int,  vector<int>> mpp;
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            int val=groupSizes[i];
            mpp[val].push_back(i);
            if(mpp[val].size() == val){
                res.push_back(mpp[val]);
                mpp[val].clear();
            }
        }
        return res;
    }
};