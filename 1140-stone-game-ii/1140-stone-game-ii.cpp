class Solution {
public:

    int solve(int i, int M, vector<int>& piles,
              vector<vector<int>>& dp,
              vector<int>& suffix) {

        int n = piles.size();
        if (i >= n)
            return 0;

        if (i + 1 * M >= n)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int maxi = INT_MIN;
        int sum = 0;

        for (int x = 1; x <= 2 * M && i + x <= n; x++) {

            sum += piles[i + x - 1];
            int nextM = max(M, x);
            int opponent = solve(i + x, nextM,
                                 piles, dp, suffix);
            int current = sum - opponent;
            maxi = max(maxi, current);
        }

        return dp[i][M] = maxi;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int difference = solve(0, 1, piles, dp, suffix);
        int total = suffix[0];
        return (total + difference) / 2;
    }
};