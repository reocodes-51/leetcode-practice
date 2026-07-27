class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort( nums.begin() , nums.end() ) ;
        int maxi = 0 ;
        int n = nums.size() ;
        int p1 = (nums[0]-1)*(nums[1]-1);
        int p2 = (nums[n-1]-1)*(nums[n-2]-1);
        maxi = max(p1,p2);
        return maxi ;
    }
};