class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1 ;
        int n = nums.size() ;
        int l = 0 ;
        int r = n-1 ;
        int mid = l + (r-l)/2 ;

        while ( l <= r ) {
            if ( nums[mid] == target ) {
                return mid ;
            }
            else if ( nums[mid] < target ) {
                l = mid + 1 ;
            }
            else {
                r = mid -1 ;
            }
            mid = l + (r-l)/2 ;
        } 
        return ans ;
    }
};