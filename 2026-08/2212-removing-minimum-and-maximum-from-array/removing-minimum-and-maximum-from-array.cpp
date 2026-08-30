class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minInd=0, maxInd=0, maxi=INT_MIN, mini=INT_MAX, n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxInd = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                minInd = i;
            }
        }
        if(minInd > maxInd)     swap(minInd, maxInd);
        int a = maxInd+1;
        int b = n-minInd;
        int both = (minInd+1) + (n-maxInd);
        return min({a,b,both});
    }
};