class Solution {
public:
    string removeOuterParentheses(string s) {

        int count_l = 0;
        int count_r = 0;

        vector<int> remove;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                count_l++;

                if (count_l == count_r + 1) {
                    remove.push_back(i);
                }
            }
            else {

                count_r++;

                if (count_l == count_r) {
                    remove.push_back(i);

                    count_l = 0;
                    count_r = 0;
                }
            }
        }
        for (int i = remove.size() - 1; i >= 0; i--) {
            s.erase(remove[i], 1);
        }

        return s;
    }
};