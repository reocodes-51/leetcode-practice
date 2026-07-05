class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0] ;
        for ( int i=1 ; i < strs.size() ; i++ ) {
                    string ans = "";
            for ( int j=0 ; j< min(strs[i].size(),temp.size() ) ; j++ ) {
                if (temp[j] == strs[i][j] ) {
                    ans +=temp[j];
                }
                else {
                    break;
                }

            }
            temp = ans ;
        }
        return temp ;
    }
};