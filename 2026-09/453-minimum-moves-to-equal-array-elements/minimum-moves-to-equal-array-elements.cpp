class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end()), cnt=0;
        for(int x: nums)    cnt += x-mini;
        return cnt;
    }
};