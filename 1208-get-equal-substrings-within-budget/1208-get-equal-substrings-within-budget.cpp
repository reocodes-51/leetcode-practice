class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.size() ;
        int left = 0 ;
        int cost = 0 ;
        int ans = 0 ;
        
        for ( int right = 0 ; right < n ; right++ ) {

            int diff = abs( ( s[right] - 'a')-( t[right] - 'a' ) ) ;
            cost += diff ;

            while ( cost > maxCost ) {

                cost -= abs ( (s[left] - 'a' ) - ( t[left] - 'a' ) ) ;
                left++;
                
            }

            ans = max(ans , right-left+1);
        }

        return ans ;
    }
};