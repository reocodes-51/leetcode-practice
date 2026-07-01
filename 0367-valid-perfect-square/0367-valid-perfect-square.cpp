class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1 ;
        long long high = num ;
        long long mid = low + ( high-low)/2 ;
        while ( low <= high ) {

            if ( 1LL*mid*mid == num) {
                return true ;
            }
            else if (1LL*mid*mid < num ) {
                low = mid + 1 ;
            }
            else {
                high = mid -1 ;
            }
            mid = low + ( high-low)/2 ;
        }
        return false ;
    }
};