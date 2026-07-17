class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0 ;
        int digitSum = 0 ;

        for ( int i=0 ; i<nums.size() ; i++ ) {
            elementSum += nums[i] ;
        }

        for ( int i=0 ; i<nums.size() ; i++ ) {
            while ( nums[i]>0 ) {
                int temp = nums[i]%10 ;
                digitSum += temp ;
                nums[i] = nums[i]/10 ;
            }
        }

        return abs(elementSum - digitSum ) ;
        
    }
};