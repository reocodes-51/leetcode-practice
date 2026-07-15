class Solution {
public:

    int product ( int x ) {
        int ans = 1 ;
        while ( x>0 ) {
            ans *= x%10 ;
            x = x/10 ;
        }
        return ans ;
    }

    int sum ( int x ) {
        int ans = 0 ;
        while ( x>0 ) {
            ans += x%10 ;
            x = x/10 ;
        }
        return ans ;
    }
    int subtractProductAndSum(int n) {
        return product(n) - sum(n) ;

    }
};