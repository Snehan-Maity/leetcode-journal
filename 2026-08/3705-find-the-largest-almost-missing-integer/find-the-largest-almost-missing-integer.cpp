class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n)  return *max_element(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for(int x : nums)
            freq[x]++;
            
        if(k == 1){
            int maxi = -1;
            for(auto it : freq){
                if(it.second == 1)  maxi = max(maxi, it.first);
            }
            return maxi;
        }
        int maxi = -1;
        if(freq[nums[0]] == 1)
            maxi = nums[0];
        if(freq[nums[n - 1]] == 1)
            maxi = max(maxi, nums[n - 1]);
        return maxi;
    }
};