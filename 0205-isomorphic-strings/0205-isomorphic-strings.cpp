class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for (int i = 0; i < s.size(); i++) {

            if (s_map[s[i]] != t_map[t[i]]) {
                return false;
            }

            s_map[s[i]] = i + 1;
            t_map[t[i]] = i + 1;
        }

        return true;
    }
};