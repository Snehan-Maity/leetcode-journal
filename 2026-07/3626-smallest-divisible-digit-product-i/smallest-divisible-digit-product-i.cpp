class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(1){
            int mul = 1;
            int copy = i;
            while(copy>0){
                mul = mul*(copy%10);
                copy /= 10;
            }
            if(mul%t == 0)     break;
            i++;
        }
        return i;
    }
};