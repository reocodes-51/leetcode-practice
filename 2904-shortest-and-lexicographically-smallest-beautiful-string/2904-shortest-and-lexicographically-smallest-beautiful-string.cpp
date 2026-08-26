class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int left = 0;
        int cnt = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1') {
                cnt++;
            }
            while (cnt > k) {
                if (s[left] == '1') {
                    cnt--;
                }
                left++;
            }
            while (left <= right && s[left] == '0' && cnt == k) {
                left++;
            }
            if (cnt == k) {

                string temp = s.substr(left, right - left + 1);

                if (ans == "" ||
                    temp.size() < ans.size() ||
                    (temp.size() == ans.size() && temp < ans)) {

                    ans = temp;
                }
            }
        }

        return ans;
    }
};