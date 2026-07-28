class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        string left = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {

            while (freq[i] >= 2) {
                left += char(i + 'a');
                freq[i] -= 2;
            }

            if (freq[i] == 1 && mid == "")
                mid += char(i + 'a');
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};