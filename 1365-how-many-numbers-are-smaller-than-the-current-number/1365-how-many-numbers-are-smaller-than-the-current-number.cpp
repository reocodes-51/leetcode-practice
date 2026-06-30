class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> ans ;
        int n = nums.size() ;

        for ( int i = 0 ; i<n ; i++ ) {
            int small_count = 0 ;
                for ( int j=0 ; j<n ; j++ ) {
                    if ( nums[i] > nums[j] && nums[i] != nums[j] ) {
                        small_count++;
                    }
                }
                ans.push_back(small_count);
        }
        return ans ;
    }
};