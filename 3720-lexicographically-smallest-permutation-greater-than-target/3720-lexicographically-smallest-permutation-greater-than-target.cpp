class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> original(26, 0);

        for (char c : s) {
            original[c - 'a']++;
        }

        for (int i = n - 1; i >= 0; i--) {

            vector<int> freq = original;
            bool possible = true;

            for (int j = 0; j < i; j++) {
                if (freq[target[j] - 'a'] == 0) {
                    possible = false;
                    break;
                }

                freq[target[j] - 'a']--;
            }

            if (!possible)
                continue;

            for (int j = target[i] - 'a' + 1; j < 26; j++) {

                if (freq[j] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + j);

                    freq[j]--;

                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};