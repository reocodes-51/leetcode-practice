class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size() ;
        int left = 0 ;
        int right = 0 ;
        long long sum = 0 ;
        long long max_sum = LLONG_MIN ;
    
        for ( int i=0 ; i<k ; i++ ) {
            sum += nums[i] ;
        }
        max_sum = max(max_sum , sum);
        for ( int i=k ; i<n ; i++ ) {
            sum += nums[i] ;
            sum -= nums[i-k] ;
            max_sum = max(max_sum , sum);
        }
        return (double)max_sum/k ;

    }
};