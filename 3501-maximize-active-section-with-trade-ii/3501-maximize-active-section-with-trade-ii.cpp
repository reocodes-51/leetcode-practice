class Solution {
public:

    struct Block {
        int u, v;
        int x, y;
        int gain;
    };

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int totalOne = 0;
        for (char ch : s) {
            if (ch == '1')
                totalOne++;
        }
        vector<Block> blocks;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                i++;
                continue;
            }
            int u = i;
            while (i < n && s[i] == '1')
                i++;
            int v = i - 1;
            int x = u - 1;
            while (x >= 0 && s[x] == '0')
                x--;
            x++;
            int y = v + 1;
            while (y < n && s[y] == '0')
                y++;
            y--;
            if (x < u && y > v) {
                Block temp;
                temp.u = u;
                temp.v = v;
                temp.x = x;
                temp.y = y;
                temp.gain = (u - x) + (y - v);
                blocks.push_back(temp);
            }
        }

        int m = blocks.size();
        int LOG = 0;
        while ((1 << LOG) <= m)
            LOG++;

        vector<vector<int>> st(m, vector<int>(LOG));

        for (int i = 0; i < m; i++)
            st[i][0] = blocks[i].gain;
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= m; i++) {
                st[i][j] = max(st[i][j - 1],
                               st[i + (1 << (j - 1))][j - 1]);
            }
        }

        vector<int> ans;

        for (int q = 0; q < queries.size(); q++) {
            int L = queries[q][0];
            int R = queries[q][1];
            int left = -1;
            int low = 0;
            int high = m - 1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (blocks[mid].u > L) {
                    left = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }

            int right = -1;

            low = 0;
            high = m - 1;

            while (low <= high) {

                int mid = (low + high) / 2;

                if (blocks[mid].v < R) {

                    right = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }

            int maxi = 0;

            if (left != -1 && right != -1 && left <= right) {

                auto calc = [&](int idx) {

                    int gain1 = blocks[idx].u - max(L, blocks[idx].x);

                    int gain2 = min(R, blocks[idx].y) - blocks[idx].v;

                    return gain1 + gain2;
                };

                if (left == right) {

                    maxi = calc(left);
                }
                else {

                    maxi = max(calc(left), calc(right));

                    if (left + 1 <= right - 1) {

                        int len = right - left - 1;

                        int k = 31 - __builtin_clz(len);

                        maxi = max(maxi,
                                   max(st[left + 1][k],
                                       st[right - (1 << k)][k]));
                    }
                }
            }

            ans.push_back(totalOne + maxi);
        }

        return ans;
    }
};