class Solution {
private:
    void rec(vector<int> nums, int i, int n, vector<vector<int>> &res){
        if(i == n-1){
            res.push_back(nums);
            return;
        }
        for(int j=i; j<n; j++){
            if(i != j && nums[i]==nums[j])  continue;
            swap(nums[i], nums[j]);
            rec(nums, i+1, n, res);
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        rec(nums, 0, nums.size(), res);
        return res;
    }
};