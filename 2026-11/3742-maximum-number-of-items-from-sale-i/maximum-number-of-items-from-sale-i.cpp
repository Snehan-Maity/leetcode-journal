class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int mult[1501] = {};
        for(auto &it: items){
            int fact = it[0];
            for(int f=1; f<=1500; f++){
                if(fact % f == 0)   mult[f]++;
            }
        }

        vector<int> dp(budget+1, 0);
        for(auto &it: items){
            int fact=it[0], price=it[1];
            vector<int> ndp = dp;
            for(int i=budget; i>=price; i--){
                ndp[i] = max(ndp[i], dp[i-price]+mult[fact]);
            }
            for(int i=price; i<=budget; i++){
                ndp[i] = max(ndp[i], ndp[i-price]+1);
            }
            dp = move(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};