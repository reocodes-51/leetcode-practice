class Solution {
public:
    int mySqrt(int x) {
        long long int ans = 0 ;
        long long int i = 1 ;
        while ( 1LL*i*i <= x ) {
            ans = i ;
            i++;
        }
        return ans ;
    }
};