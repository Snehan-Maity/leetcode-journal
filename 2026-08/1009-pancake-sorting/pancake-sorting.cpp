class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        int j;
        for(int i=n; i>0; i--){
            for(j=0; arr[j]!=i; j++);
            reverse(arr.begin(), arr.begin() + j+1);
            res.push_back(j+1);
            reverse(arr.begin(), arr.begin() + i);
            res.push_back(i);
        }
        return res;
    }
};