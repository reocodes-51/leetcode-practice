class Solution {
public:
    string reverseWords(string s) {
        int n = s.size() ;
        string temp = "" ;
        string ans = "" ;
        int count = 0 ;
        for ( int i=n-1 ; i>=0 ; i--  ) {

            if ( s[i] != ' ' ) {
                temp += s[i] ;
                count = 0 ;
            }
            else {
                count++;
                if ( count == 1 && temp.size() != 0) {
                    reverse( temp.begin() , temp.end() ) ;
                    ans += temp ;
                    ans += " " ;
                    temp = "" ;
                }
            }
        }
        if (temp.size() != 0) {
        reverse(temp.begin(), temp.end());
        ans += temp;
        }
        if (!ans.empty() && ans.back() == ' ')
        ans.pop_back();
        
        return ans ;
        
    }
};