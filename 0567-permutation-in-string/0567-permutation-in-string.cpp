class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size() ;
        int m = s2.size() ;

        vector <int> hash1(26,0) ;
        vector <int> hash2(26,0) ;

        for ( char ch : s1 ) {
            hash1[ch-'a']++ ;
        }

        int left = 0 ;
        for ( int right = 0 ; right < m ; right++ ) {
            hash2[ s2[right] - 'a' ]++;

            if ( right - left + 1 > n ) {
                hash2[s2[left] - 'a']-- ;
                left++ ;
            }

            if ( right - left + 1 == n ) {
                if ( hash1 == hash2 ) {
                    return true ;
                }
            }
        }
        return false ;
    }
};