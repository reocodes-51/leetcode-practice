class Solution {
public:

    int sumOfSquare ( int n ) {

        int sum = 0 ;
        while ( n > 0 ) {
            int temp = n%10 ;
            sum += temp*temp ;
            n=n/10 ;
        }
        return sum ;

    }

    bool isHappy(int n) {
        unordered_set <int> seen ;
        while ( n!=1 ) {
            if ( seen.count(n) ) {
                return false ;
            }
            seen.insert(n) ;
            n=sumOfSquare(n) ;
        }
        return true ;
    }
};