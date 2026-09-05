class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size() ;

        vector <int> maxi ( n , 0 ) ;
        vector <int> mini ( n , 0 ) ;
        int mx = INT_MIN ;
        int mn = INT_MAX ;
        int index = -1 ;

        for ( int i=0 ; i<n ; i++ ) {
            if ( nums[i] > mx ) {
                mx = nums[i] ;
                
            }
            maxi[i] = mx ;
        }

        for ( int i=n-1 ; i>=0 ; i-- ) {
            if ( nums[i] < mn ) {
                mn = nums[i] ;
                
            }
            mini[i] = mn ;
        }

        for ( int i=0 ; i<n ; i++ ) {
            if ( maxi[i] - mini[i] <= k ) {
                index = i ;
                return index ;
            }
        }
        return index ;
        
    }
};