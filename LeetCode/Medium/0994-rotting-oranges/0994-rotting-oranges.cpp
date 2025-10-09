/*

1. Multi source BFS problem
2. wherever a rotten orange, parallely every adjacent fresh orange becomes rotten
3. 4 edges -> up, right, left, down
4. since every rotten orange parallely rotts others means initially all initial rotten oranges will be pushed

*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        queue<RottenPair> q;
        const vector<pair<int,int>> directions = {
            {-1,0},
            {0,1},
            {1,0},
            {0,-1}
        };

        // checks if the row and col are valid
        const auto isValid = [&grid](const int& row,const int& col){
            return row >= 0 && row < grid.size() && col >=0 && col < grid[row].size();
        };

        // push all the initial rotten oranges with time = 0
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){

                if(grid[i][j] == 2)
                    q.push(RottenPair(i,j,0));
            }
        }

        int mins = 0;

        // rott all the fresh oranges
        while(!q.empty()){
            const auto& rtp = q.front();

            mins = max(mins,rtp.min);

            // rott all it's adjacent oranges         
            for(const auto& d: directions){

                int adjrow = d.first + rtp.row;
                int adjcol = d.second + rtp.col;

                // take the cell only when valid + fresh orange, + not pushed yet
                if(isValid(adjrow,adjcol) && grid[adjrow][adjcol] == 1 && !visited[adjrow][adjcol]){
                    q.push(RottenPair(adjrow, adjcol, rtp.min+1));
                    visited[adjrow][adjcol] = true;
                    grid[adjrow][adjcol] = 2;
                }
            }

            q.pop();
        }

        // check if any fresh orange left
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){

                if(grid[i][j] == 1)
                   return -1;
            }
        }

        return mins;
    }

private:
    struct RottenPair{
        int row;
        int col;
        int min;

        RottenPair(int row,int col,int min):row(row),col(col),min(min){}
    };
};