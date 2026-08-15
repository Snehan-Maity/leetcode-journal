class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int tot=0, nonZero=0;
        for(auto it:nums){
            nonZero |= it>0;
            tot ^= it;
        }
        return nonZero * (nums.size() - !tot);
    }
};