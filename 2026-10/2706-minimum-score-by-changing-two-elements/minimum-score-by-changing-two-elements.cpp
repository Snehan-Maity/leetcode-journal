class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int c = nums[n-1] - nums[2];  // Leaving first 2 elements 
        int a = nums[n-2] - nums[1];  // Leaving last and first
        int b = nums[n-3] - nums[0];  // Leaving last 2 elements
        return min({a, b, c});
    }
};