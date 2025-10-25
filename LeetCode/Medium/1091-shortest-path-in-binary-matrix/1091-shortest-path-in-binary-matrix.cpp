class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid.size(), false));
        queue<vector<int>> q;

        q.push({0, 0, 1});
        visited[0][0] = true;

        while (!q.empty()) {
            const auto& node = q.front();
            const int& row = node[0];
            const int& col = node[1];
            const int& count = node[2];

            if (row == (n - 1) && col == (n - 1))
                return count;

            for (const auto& [r_side, c_side] : directions) {
                const int& r = row + r_side;
                const int& c = col + c_side;

                if (!isValid(grid, visited, r, c, n))
                    continue;

                q.push({r, c, count + 1});
                visited[r][c] = true;
            }

            q.pop();
        }

        return -1;
    }

private:
    bool isValid(const vector<vector<int>>& graph,
                 const vector<vector<bool>>& visited, const int& row,
                 const int& col, const int& n) {
        if (row < 0 || row >= n || col < 0 || col >= n || visited[row][col] ||
            graph[row][col] == 1)
            return false;

        return true;
    }

    const vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
};