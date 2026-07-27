class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=-1, maxi2=-1;
        for(int &it: nums){
            if(it >= maxi1){
                maxi2 = maxi1;
                maxi1 = it;
            }
            else if(it >= maxi2)    maxi2 = it;
        }
        maxi1 -= 1;
        maxi2 -= 1;
        return (maxi1 * maxi2);
    }
};