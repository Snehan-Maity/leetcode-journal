class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        unordered_set<int> vis;
        q.push(0);
        vis.insert(0);
        int depth=0;
        while(!q.empty()){
            int sz=q.size();
            depth++;
            while(sz-- > 0){
                int u=q.front();
                q.pop();
                for(int i=1; i*i <= n; i++){
                    int v = u + i*i;
                    if(v == n)  return depth;
                    if(v > n)   break;
                    if(!vis.contains(v)){
                        q.push(v);
                        vis.insert(v);
                    }
                }
            }
        }
        return depth;
    }
};