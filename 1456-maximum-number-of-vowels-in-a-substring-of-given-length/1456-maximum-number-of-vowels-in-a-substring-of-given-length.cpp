class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size() ;
        int len = 0 ;
        int ans = 0 ;

        for ( int i=0 ; i<k ; i++ ) {

            if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                len++;
                ans = max(ans , len) ;
            }
        }

        for ( int i=k ; i<n ; i++ ) {

            if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                len++;
            }
            if ( s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') {
                len--;
            }
            ans = max( ans , len) ;
        }
        return ans ;
    }
};