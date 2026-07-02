class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size() - 1 ;


        vector <int> ans { -1 , -1 } ;

        while ( low <= high ) {
            int mid = low + ( high-low)/2 ;
            if ( nums[mid] == target ) {
                ans[0] = mid ;
                if ( mid > 0 && nums[mid-1] == target) {
                     high = mid -1 ;
                }
                else {
                    break ;
                }
            }
            else if ( nums[mid] > target ) {
                high = mid -1 ;
            }
            else {
                low = mid + 1 ;
            }   
        }
        low = 0 ;
        high = nums.size()-1 ;

        while ( low <= high ) {
            int mid = low + ( high-low)/2 ;
            if ( nums[mid] == target ) {
                ans[1] = mid ;
                if ( mid < nums.size() - 1 && nums[mid+1] == target) {
                     low = mid+1 ;
                }
                else {
                    break ;
                }
            }
            else if ( nums[mid] > target ) {
                high = mid -1 ;
            }
            else {
                low = mid + 1 ;
            }   
        }
        return ans ;
    }
};