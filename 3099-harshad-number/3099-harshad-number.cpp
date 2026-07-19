class Solution {
public:
    int sumOfDigit (int x ) {
        if (x==0) return 0 ;
        int ans = 0 ;
        while ( x>0 ) {
            ans +=  x%10 ;
            x=x/10;
        }
        return ans ;
    }
    int sumOfTheDigitsOfHarshadNumber(int x) {

        int ans = -1 ;

        if ( x % (sumOfDigit(x)) == 0 ) {
            return sumOfDigit(x) ;
        }
        else {
            return ans ;
        }
        
    }
};