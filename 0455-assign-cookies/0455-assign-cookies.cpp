class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;  // child pointer
        int j = 0;  // cookie pointer
        int count = 0;

        while (i < g.size() && j < s.size()) {

            if (s[j] >= g[i]) {
                // Cookie can satisfy this child
                count++;
                i++;
                j++;
            }
            else {
                // Cookie is too small
                j++;
            }
        }

        return count;
    }
};