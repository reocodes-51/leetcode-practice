class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> rows;

        // Store reserved seats as bits
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << col);
        }

        int ans = 2 * (n - rows.size());

        // Masks for the three possible groups
        int left  = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, mask] : rows) {

            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                ans += 2;
            }
            else if (canLeft || canMiddle || canRight) {
                ans += 1;
            }
        }

        return ans;
    }
};