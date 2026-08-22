class Solution {
public:
    int val ( int n ) {
        int product = 1 ;
        int sum = 0 ;
        while ( n > 0 ) {
            int rem = n%10 ;
            product *= rem ;
            sum += rem ;
            n=n/10 ;
        }
        return sum+product ;
    }
    bool checkDivisibility(int n) {
        int k = val(n) ;
        if ( n%k == 0 ) {
            return true ;
        }
        else {
            return false ;
        }
        return false ;
    }
};