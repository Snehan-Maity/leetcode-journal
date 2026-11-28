class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVisited, vector<int> &check){
        vis[node]=1;
        pathVisited[node]=1;
        check[node]=1;
        for(auto &it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVisited, check)){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathVisited[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVisited[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj = graph;
        vector<int> vis(n,0), pathVisited(n,0), check(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(i, adj, vis, pathVisited, check);
        }
        vector<int> ans;
        for(int i=0; i<check.size(); i++){
            if(check[i] == 1)   ans.push_back(i);
        }
        return ans;
    }
};