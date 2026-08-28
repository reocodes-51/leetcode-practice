class Solution {
public:
    string makePalindrome(string half, char mid) {
        string ans = half;
        if (mid != '#')
            ans += mid;
        
        reverse(half.begin(), half.end());
        ans += half;
        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd = 0;
        char mid = '#';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        // A palindrome cannot have more than one odd-frequency character
        if (odd > 1)
            return "";

        // 1. Check exact match of the first half first
        vector<int> cnt = freq;
        string half = "";
        bool possible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (cnt[x] < 2) {
                possible = false;
                break;
            }

            cnt[x] -= 2;
            half += target[i];
        }

        if (possible) {
            string ans = makePalindrome(half, mid);
            if (ans > target)
                return ans;
        }

        // 2. Check by diverging at a pivot, looking for the smallest valid character strictly greater than target[pivot]
        for (int pivot = m - 1; pivot >= 0; pivot--) {
            vector<int> cnt_p = freq;
            bool ok = true;

            // Fulfill the matching prefix up to the pivot
            for (int i = 0; i < pivot; i++) {
                int x = target[i] - 'a';

                if (cnt_p[x] < 2) {
                    ok = false;
                    break;
                }

                cnt_p[x] -= 2;
            }

            if (!ok)
                continue;

            // Find the smallest character strictly greater than target[pivot]
            for (int c = target[pivot] - 'a' + 1; c < 26; c++) {
                if (cnt_p[c] < 2)
                    continue;

                cnt_p[c] -= 2;
                string half_p = "";

                // Construct half_p: matched prefix + greater character + remaining sorted characters
                for (int i = 0; i < pivot; i++) {
                    half_p += target[i];
                }
                
                half_p += char('a' + c);

                for (int x = 0; x < 26; x++) {
                    while (cnt_p[x] >= 2) {
                        half_p += char('a' + x);
                        cnt_p[x] -= 2;
                    }
                }

                return makePalindrome(half_p, mid);
            }
        }

        return "";
    }
};