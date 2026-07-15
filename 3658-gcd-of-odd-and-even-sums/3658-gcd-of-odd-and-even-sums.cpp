class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int oddSum = 0 ;
        int evenSum = 0 ;

        for ( int i=1 ; i<=2*n-1 ; i+=2 ) {
            oddSum += i ;
        }

        for ( int i=2 ; i<=2*n ; i+=2 ) {
            evenSum += i ;
        }

        int gcd = __gcd( oddSum , evenSum ) ;
        return gcd ;
        
    }
};