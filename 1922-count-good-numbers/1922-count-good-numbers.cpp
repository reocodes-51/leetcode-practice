class Solution {
public:

    long long power ( long long x , long long n ) {
        long long ans = 1 ;
        long long mod = 1000000007; 

        while ( n>0 ) {

            if ( n%2 == 1 ) {
                ans = ( ans*x)%mod ;
            }
            x=(x*x)%mod ;
            n=n/2 ;
        }
        return ans ;
    }
    int countGoodNumbers(long long n) {
        long long evenpos = (n+1)/2 ;
        long long oddpos = n/2 ;

        long long evenways  = power(5,evenpos) ;
        long long oddways = power(4,oddpos) ;

        return ( evenways*oddways)%1000000007;
    }
};