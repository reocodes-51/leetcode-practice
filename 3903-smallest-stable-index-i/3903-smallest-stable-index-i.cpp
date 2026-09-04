class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int index = -1 ;
        int mx = INT_MIN ;
        int mn = INT_MAX ;
        int n = nums.size() ;
        int temp = 0 ;

        for ( int i=0 ; i<nums.size() ; i++ ) {
            
            for ( int j=0 ; j<=i ; j++ ) {
                if ( nums[j] > mx ) {
                    mx = nums[j] ;
                    temp = j ;
                }
            }
            for ( int l=n-1 ; l>=i ; l-- ) {
                mn = min( mn , nums[l] ) ;
            }

            if ( mx - mn <= k ) {
                index = i  ;
                return index ;
            }
            mx = INT_MIN ;
            mn = INT_MAX ;
        }
        return index ;
    }
};