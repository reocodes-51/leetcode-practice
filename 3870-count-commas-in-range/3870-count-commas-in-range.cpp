class Solution {
public:

    int digit ( int n ) {
        int count = 0 ;
        while ( n > 0 ) {
            int temp = n%10 ;
            count++;
            n=n/10 ;
        }
        return count ;
    }

    int countCommas(int n) {

        int ans = 0 ;

        if ( digit(n) <= 3 ) {
            return 0 ;
        }
        ans = n-1000+1;


         return ans ;
    }
};