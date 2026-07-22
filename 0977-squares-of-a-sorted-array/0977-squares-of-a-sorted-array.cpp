class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector <int> sq(nums.size(), 0);
        for ( int i=0 ; i<nums.size() ; i++ ) {
            sq[i] = nums[i]*nums[i] ;
        }
        sort(sq.begin() , sq.end() ) ;
        return sq ;
        
    }
};