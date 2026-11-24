class Solution {
public:
    int maxLength(vector<int>& nums) {
        int left=0, prod=1, best=2, n=nums.size();
        for(int right=0; right<n; right++){
            int x = nums[right];
            while(gcd(prod, x) > 1)
                prod /= nums[left++];
            prod *= x;
            best = max(best, right-left+1);
        }
        return best;
    }
};