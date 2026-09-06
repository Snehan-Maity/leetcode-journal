class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(vector<int>& row: image){
            reverse(row.begin(), row.end());
            for(int& p: row)     p ^= 1;
        }
        return image;
    }
};