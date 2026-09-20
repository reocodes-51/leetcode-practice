class Solution {
public:
    int reverseDegree(string s) {
        vector <int> rev ( 26 , 0 ) ;
        string x = "abcdefghijklmnopqrstuvwxyz" ;
        int ans = 0 ;

        for ( int i = 0 ; i < x.size() ; i++ ) {
            rev[i] = 26 - i ; 
        }

        for ( int i=0 ; i<s.size() ; i++ ) {
            ans += rev[s[i]-'a']*(i+1) ;
        }

        return ans ;
    }
};