/*
1. we have to fill each empty cell
2. for each empty cell we have 9 choices, from '1' to '9'
3. we try to put chars in cell if it is valid
4. for validity:
    - check if char present in row
    - check if char present in col
    - check if char present in that subgrid(find subgrid start row and col using
row - row%3 and col - col%3)
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        memset(boxes, false, sizeof(boxes));

        // initialize the memoizing arrays
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // skip the empty cell
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[giveBoxIndex(i, j)][num] = true;
            }
        }

        // solve the board
        solve(board, 0, 0);
    }

private:
    bool solve(vector<vector<char>>& board, int row, int col) {

        // when we have filled all the rows means we got the answer
        if (row >= board.size())
            return true;

        // move to next row if all the cols are filled in this row
        if (col >= board.size()) {
            return solve(board, row + 1, 0);
        }

        // skip the cell if it is prefilled
        if (board[row][col] != '.')
            return solve(board, row, col + 1);

        // we have 9 choices to put in this particular cell
        for (char ch = '1'; ch <= '9'; ch++) {
            if (isValid(board, row, col, ch)) {

                // putting that char
                board[row][col] = ch;
                addNum(row,col,ch);

                // when board solves using this char then go as it is
                if (solve(board, row, col + 1))
                    return true;

                // backtrack to apply another char
                board[row][col] = '.';
                removeNum(row,col,ch);
            }
        }

        // we failed to solve the board for any choice from '1' to '9'
        return false;
    }

    bool isValid(const vector<vector<char>>& board, const int row,
                 const int col, const char& ch) {
        int num = ch - '0';
        return !rows[row][num] && !cols[col][num] &&
               !boxes[giveBoxIndex(row, col)][num];
    }

    void removeNum(int row, int col, const char& ch) {

        // skip invalid chars
        if (ch < '1' || ch > '9')
            return;

        int num = ch - '0';
        rows[row][num] = false;
        cols[col][num] = false;
        boxes[giveBoxIndex(row, col)][num] = false;
    }

    void addNum(int row, int col, const char& ch) {
        // skip invalid chars
        if (ch < '1' || ch > '9')
            return;

        int num = ch - '0';
        rows[row][num] = true;
        cols[col][num] = true;
        boxes[giveBoxIndex(row, col)][num] = true;
    }

    inline int giveBoxIndex(int row, int col) {
        return (row - row % 3) + (col - col % 3) / 3;
    }

    bool rows[10][10];
    bool cols[10][10];
    bool boxes[10][10];
};