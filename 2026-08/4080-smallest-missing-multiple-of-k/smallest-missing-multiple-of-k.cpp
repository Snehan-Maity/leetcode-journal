class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int it: nums)   st.insert(it);
        int n=nums.size();
        int i=0;
        for(i=1; i<=n; i++){
            if(st.find(k*i) == st.end())    break;
        }
        return k*i;
    }
};