class Solution {
public:
    int numTrees(int n) {
        vector<int> unique(n+1, 1);
        for(int i=2; i<=n; i++){
            int total=0;
            for(int root=1; root<=i; root++)
                total += unique[root-1]*unique[i-root];
            unique[i] = total;
        }
        return unique[n];
    }
};