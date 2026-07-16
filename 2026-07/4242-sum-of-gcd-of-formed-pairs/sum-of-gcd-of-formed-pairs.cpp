class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd(n);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi  = max(nums[i], maxi);
            prefixGcd[i] = gcd(nums[i],maxi);
        }
        long long sum=0;
        sort(prefixGcd.begin(), prefixGcd.end());
        for(int i=0; i<n/2; i++){
            sum += gcd(prefixGcd[i], prefixGcd[n-1-i]);
        }
        return sum;
    }
};