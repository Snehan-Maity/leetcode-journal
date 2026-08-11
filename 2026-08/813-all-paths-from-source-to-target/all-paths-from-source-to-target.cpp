class Solution {
private:
    void dfs(vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans, int node){
        path.push_back(node);
        if(node == graph.size()-1){
            ans.push_back(path);
        }
        for(auto it: graph[node])   dfs(graph, path, ans, it);
        path.pop_back();
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph, path, ans, 0);
        return ans;
    }
};