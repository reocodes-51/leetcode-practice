class Solution {
public:

    int product ( int x ) {
        int val = 1 ;
        while ( x > 0 ) {
            int temp = x%10 ;
            val = val*temp  ;
            x=x/10 ;
        }
        return val ;

    }

    int smallestNumber(int n, int t) {
        

        while ( product(n) % t != 0 ) {
            n++;
        }
        return n ;
    }
};