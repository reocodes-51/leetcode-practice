class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> ans(2*n , 0) ;

        for ( int i=0 ; i<n ; i++  ) {
            ans[2*i] = nums[i] ;
        }
        int temp = 1 ;
         for ( int i=n ; i<2*n ; i++ ) {
            ans[temp] = nums[i] ;
            temp += 2;
        }
        return ans ;
        
    }
};