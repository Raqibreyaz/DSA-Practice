/*

1. for putting X in place of O, O and its adjacent neghbours should be
sorrounded by X
2. means no O should be at the edge and it's direct or indirect neghbours too!
3. mark all the Os as not possible which are directly/indirectly connected with
O at edge or edge
4. now traverse only for those which are actually sorrounded by X

*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board[0].size(), false));

        // mark impossible for first row
        for (int j = 0; j < board[0].size(); j++)
            markImpossible(board, 0, j, visited);

        // mark impossible for last row
        for (int j = 0; j < board[0].size(); j++)
            markImpossible(board, board.size() - 1, j, visited);

        // mark impossible for first column
        for (int i = 0; i < board.size(); i++)
            markImpossible(board, i, 0, visited);

        // mark impossible for last column
        for (int i = 0; i < board.size(); i++)
            markImpossible(board, i, board[0].size() - 1, visited);

        // replace each valid sorrounded O with X
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (visited[i][j])
                    continue;

                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

private:
    void markImpossible(vector<vector<char>>& board, int row, int col,
                        vector<vector<bool>>& visited) {
        if (row < 0 || row >= board.size() || col < 0 ||
            col >= board[row].size() || visited[row][col] ||
            board[row][col] == 'X')
            return;

        visited[row][col] = true;

        for (const auto& d : directions) {
            int r = d[0] + row;
            int c = d[1] + col;

            markImpossible(board, r, c, visited);
        }
    }

    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};