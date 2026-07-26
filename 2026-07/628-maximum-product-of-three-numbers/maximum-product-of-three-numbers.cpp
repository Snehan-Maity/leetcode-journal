class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi1=-1001, maxi2=-1001, maxi3=-1001;
        int mini1=0, mini2=0;
        for(int &it: nums){
            if(it >= maxi1){
                maxi3 = maxi2;
                maxi2 = maxi1;
                maxi1 = it;
            }
            else if(it >= maxi2){
                maxi3 = maxi2;
                maxi2 = it;
            }
            else if(it >= maxi3)     maxi3 = it;
            if(it <= mini1){
                mini2 = mini1;
                mini1 = it;
            }
            else if(it <= mini2)     mini2 = it;
        }
        return max(maxi1*maxi2*maxi3, mini1*mini2*maxi1);
    }
};