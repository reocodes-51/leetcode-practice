class Solution {
public:

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] != '(' ||
            grid[m - 1][n - 1] != ')') {
            return false;
        }
        int pathLength = m + n - 1;

        if (pathLength % 2 != 0) {
            return false;
        }

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n, -1)
            )
        );

        return rec(grid, 0, 0, 0, dp);
    }

    bool rec(
        vector<vector<char>>& grid,
        int i,
        int j,
        int brac,
        vector<vector<vector<int>>>& dp
    ) {

        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }

        if (grid[i][j] == '(') {
            brac++;
        }
        else {

            if (brac > 0) {
                brac--;
            }
            else {
                return false;
            }
        }
        int remaining = (m - i) + (n - j) - 1;

        if (brac > remaining) {
            return false;
        }

        if (i == m - 1 && j == n - 1) {

            return brac == 0;
        }

        if (dp[i][j][brac] != -1) {
            return dp[i][j][brac];
        }
        bool down = rec(
            grid,
            i + 1,
            j,
            brac,
            dp
        );

        bool right = rec(
            grid,
            i,
            j + 1,
            brac,
            dp
        );
        dp[i][j][brac] = down || right;

        return dp[i][j][brac];
    }
};