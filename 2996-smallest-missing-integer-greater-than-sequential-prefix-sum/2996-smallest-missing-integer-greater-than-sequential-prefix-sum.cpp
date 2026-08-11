class Solution {
public:
    bool find ( vector<int>& nums , int x  ) {
        
        for ( int i = 0 ; i<nums.size() ; i++ ) {
            if ( x == nums[i] ) {
                return true ;
            }
        }
        return false ;
    }
    int missingInteger(vector<int>& nums) {

        int sum = nums[0] ;
        
        for ( int i = 1 ; i < nums.size() ; i++ ) {
            if ( nums[i] == nums[i-1]+1 ) {
                sum += nums[i] ;
            }
            else {
                break ;
            }
        }
        
        while ( find( nums , sum ) ) {
            sum++ ;
        }

        return sum ;
        
    }
};