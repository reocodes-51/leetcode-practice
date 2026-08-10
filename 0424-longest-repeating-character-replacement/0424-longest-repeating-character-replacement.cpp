class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0 ;
        int n = s.size() ;
        int len = 0 ;
        int mx = 0 ;
        map < char , int > hash ;

        for ( int right = 0 ; right < n ; right++ ) {
            hash[s[right]]++;
            mx = max(mx,hash[s[right]]) ;

            if ( right - left + 1 - mx > k ) {
                hash[s[left]] -= 1 ;
                left += 1 ;
            }
        }
        return n-left ;
    }
};