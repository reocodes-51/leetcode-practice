class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        ll ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            ll L = 1;
            int bits = 0;
            bool tooLarge = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    L = lcm(L, (ll)coins[i]);
                    if (L > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge)
                continue;

            ll ways = x / L;

            if (bits & 1)
                ans += ways;
            else
                ans -= ways;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {
        vector<int> filtered;

        sort(coins.begin(), coins.end());

        for (int c : coins) {
            bool redundant = false;

            for (int d : filtered) {
                if (c % d == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant)
                filtered.push_back(c);
        }

        coins = filtered;

        ll lo = 1;
        ll hi = 1LL * coins[0] * k;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (count(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};