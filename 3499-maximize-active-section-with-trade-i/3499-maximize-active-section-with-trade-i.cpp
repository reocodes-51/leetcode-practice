class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        vector<int> v;
        int n = s.size();

        int i = 0;
        while (i < n) {
            int cnt = 0;
            if (s[i] == '1') {
                while (i < n && s[i] == '1') {
                    cnt++;
                    i++;
                }
                v.push_back(cnt);
            }
            else {
                while (i < n && s[i] == '0') {
                    cnt++;
                    i++;
                }
                v.push_back(-cnt);
            }
        }

        int count_1 = 0;

        for (int x : v) {
            if (x > 0)
                count_1 += x;
        }

        int maxi = count_1;

        for (int i = 1; i < v.size() - 1; i++) {

            if (v[i] > 0) {
                int gain = abs(v[i - 1]) + abs(v[i + 1]);
                maxi = max(maxi, count_1 + gain);
            }
        }

        return maxi;
    }
};