class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        const int MAXX = 2048;

        vector<int> pair(MAXX, 0);
        vector<int> ans(MAXX, 0);

        int n = nums.size();

        // All possible pair XORs
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pair[nums[i] ^ nums[j]] = 1;
            }
        }

        // Add third element
        for (int xr = 0; xr < MAXX; xr++) {

            if (!pair[xr])
                continue;

            for (int x : nums) {
                ans[xr ^ x] = 1;
            }
        }

        int cnt = 0;

        for (int i = 0; i < MAXX; i++)
            cnt += ans[i];

        return cnt;
    }
};