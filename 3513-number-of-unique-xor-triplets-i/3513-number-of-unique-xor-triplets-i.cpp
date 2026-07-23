class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size() ;
        int msb = 0 ;
        int ans = 0 ;

        if ( n==1 ) return 1 ;

        if ( n == 2 ) return 2 ;

        if ( n >= 3 ) {
            
            for ( int i=0 ; pow(2,i)<=n ; i++ ) {
                msb = i ;
            }
            ans = pow( 2 , msb+1 ) - 1 ;
            return ans + 1 ;

        }
        return -1 ;
        
    }
};