class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int ans = -1 ;
        int mx = -1 ;
        int n = nums.size() ;
        
        map <int , int> freq ;

        for ( int i=0 ; i<n ; i++ ) {
            freq[nums[i]]++;
        }

        if ( k == 1 ) {
            for ( auto it : freq ) {
                if ( it.second == 1 ) {
                    mx = max ( mx , it.first ) ;
                }
            }
            return mx ;
        }
        else if ( k==n ) {
            for ( auto it : freq ) {
                if ( it.first > mx ) {
                    mx = max ( mx , it.first ) ;
                }
            }
            return mx ;
        }
        else {
            if ( freq[nums[0]] == 1 ) {
                ans = nums[0];
            }
            if ( freq[nums[n-1]] == 1 ) {
                mx = nums[n-1] ;
            }
            ans = max ( ans , mx ) ;
            return ans ;
        }

        return -1 ;
    }
};