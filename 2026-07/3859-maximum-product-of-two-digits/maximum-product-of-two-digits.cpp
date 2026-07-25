class Solution {
public:
    int maxProduct(int n) {
        int maxi1=-1, maxi2=-1;
        while(n!=0){
            int rem=n%10;
            if(rem > maxi1){
                maxi2 = maxi1;
                maxi1 = rem;
                n /= 10;
                continue;
            }
            maxi2 = max(rem, maxi2);
            n /= 10;
        }
        return maxi1*maxi2;
    }
};