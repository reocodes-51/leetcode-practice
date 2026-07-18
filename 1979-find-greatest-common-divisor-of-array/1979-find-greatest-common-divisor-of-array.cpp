class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin() , nums.end() ) ;
        int n = nums.size() ;
        int smallest = nums[0] ;
        int largest = nums[n-1] ;
        
        int gcd = 1 ;
        gcd = __gcd(smallest , largest);

        return gcd ;
    }
};