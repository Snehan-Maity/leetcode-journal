class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mpp;
        for(auto it: matches){
            int loser = it[1];
            mpp[loser]++;
        }
        vector<int> allWon;
        vector<int> onceLost;
        for(auto it: matches){
            if(mpp.find(it[0]) == mpp.end()){
                allWon.push_back(it[0]);
                mpp[it[0]] = 2;
            }
            if(mpp[it[1]] == 1)     onceLost.push_back(it[1]);
        }
        sort(allWon.begin(), allWon.end());
        sort(onceLost.begin(), onceLost.end());
        return {allWon, onceLost};
    }
};