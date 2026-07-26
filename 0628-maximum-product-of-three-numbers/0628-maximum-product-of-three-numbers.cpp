class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end() ) ;
        int n = nums.size() ;

        int l = n-1 ;
        int sl = n-2 ;
        int tl = n-3 ;
        int smallest = 0 ;
        int sec_smallest = 1 ;
        
        int p1 = nums[l]*nums[sl]*nums[tl];
        int p2 = nums[l]*nums[smallest]*nums[sec_smallest];

        return max(p1,p2);
    }
};