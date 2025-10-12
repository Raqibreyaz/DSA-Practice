class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));

        // marking all 0s +
        // take all the 0s
        queue<pair<int,int>> q;
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;

                    q.push({i,j});
                }
            }
        }

        // applying multi-source BFS
        BFS(ans,q);

        return ans;
    }

private:

    // multi source BFS
    void BFS(vector<vector<int>>& grid, queue<pair<int,int>> &q){
   
        while(!q.empty()){
            const auto& p = q.front();

            for(const auto& d: directions){
                int r = p.first + d[0];
                int c = p.second + d[1];

                // propagate the distance of 0 at each cell
                if(isValid(r,c,grid.size(), grid[0].size()) && grid[r][c] == -1){
                    grid[r][c] = grid[p.first][p.second] +1;

                    q.push({r,c});
                }
            }

            q.pop();
        }
    }

    bool isValid(int row,int col,int nrows, int ncols){
        return row >= 0 && row < nrows && col >= 0 && col < ncols;
    }

    vector<vector<int>> directions = {
        {-1,0},
        {0,1},
        {1,0},
        {0,-1}
    };
};