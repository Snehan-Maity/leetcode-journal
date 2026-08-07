class Solution {
private:
    void dfs(int i, vector<int> adjList[], vector<int> &vis){
        vis[i] = 1;
        for(auto it : adjList[i]){
            if(!vis[it])     dfs(it, adjList, vis);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjList, vis);
            }
        }
        return cnt;
    }
};