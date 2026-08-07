class Solution {
public:
    using A = array<int, 4>;

    A factorDigit(int d) {
        A r = {0, 0, 0, 0};
        while (d % 2 == 0) r[0]++, d /= 2;
        while (d % 3 == 0) r[1]++, d /= 3;
        while (d % 5 == 0) r[2]++, d /= 5;
        while (d % 7 == 0) r[3]++, d /= 7;
        return r;
    }

    string smallestNumber(string num, long long t) {
        A need = {0, 0, 0, 0};
        int primes[4] = {2, 3, 5, 7};

        for (int k = 0; k < 4; k++) {
            while (t % primes[k] == 0) {
                need[k]++;
                t /= primes[k];
            }
        }

        if (t != 1) return "-1";

        A gain[10];
        for (int d = 1; d <= 9; d++) gain[d] = factorDigit(d);

        int E2 = need[0], E3 = need[1];
        const int INF = 1e9;
        vector<vector<int>> dp(E2 + 1, vector<int>(E3 + 1, INF));
        dp[0][0] = 0;

        int useful[] = {2, 3, 4, 6, 8, 9};
        for (int a = 0; a <= E2; a++) {
            for (int b = 0; b <= E3; b++) {
                if (dp[a][b] == INF) continue;

                for (int d : useful) {
                    int na = min(E2, a + gain[d][0]);
                    int nb = min(E3, b + gain[d][1]);
                    dp[na][nb] = min(dp[na][nb], dp[a][b] + 1);
                }
            }
        }

        auto minDigitsNeeded = [&](A rem) {
            return dp[rem[0]][rem[1]] + rem[2] + rem[3];
        };

        auto subtractDigit = [&](A rem, int d) {
            for (int k = 0; k < 4; k++) {
                rem[k] = max(0, rem[k] - gain[d][k]);
            }
            return rem;
        };
        auto buildSuffix = [&](A rem, int len) {
            string suffix;

            for (int pos = 0; pos < len; pos++) {
                for (int d = 1; d <= 9; d++) {
                    A next = subtractDigit(rem, d);

                    if (minDigitsNeeded(next) <= len - pos - 1) {
                        suffix.push_back(char('0' + d));
                        rem = next;
                        break;
                    }
                }
            }

            return suffix;
        };

        int n = (int)num.size();
        vector<A> pref(n + 1);
        vector<int> zeroCount(n + 1, 0);
        pref[0] = {0, 0, 0, 0};

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            zeroCount[i + 1] = zeroCount[i];

            int d = num[i] - '0';
            if (d == 0) {
                zeroCount[i + 1]++;
            } else {
                for (int k = 0; k < 4; k++) {
                    pref[i + 1][k] += gain[d][k];
                }
            }
        }

        bool enough = (zeroCount[n] == 0);
        for (int k = 0; k < 4; k++) {
            if (pref[n][k] < need[k]) enough = false;
        }
        if (enough) return num;
        for (int i = n - 1; i >= 0; i--) {
            if (zeroCount[i] > 0) continue; 

            int current = num[i] - '0';

            for (int d = max(1, current + 1); d <= 9; d++) {
                A rem = need;

                for (int k = 0; k < 4; k++) {
                    rem[k] = max(0, rem[k] - pref[i][k]);
                }
                rem = subtractDigit(rem, d);

                int suffixLen = n - i - 1;
                if (minDigitsNeeded(rem) <= suffixLen) {
                    return num.substr(0, i) +
                           char('0' + d) +
                           buildSuffix(rem, suffixLen);
                }
            }
        }
        int length = max(n+1 , minDigitsNeeded(need));
        return buildSuffix(need, length);
    }
};