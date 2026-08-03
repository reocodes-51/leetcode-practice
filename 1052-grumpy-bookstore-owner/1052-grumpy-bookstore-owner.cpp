class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size() ;
        int sum = 0 ;
        int maxi = 0 ;
        for ( int i = 0 ; i<n ; i++ ) {
            if ( grumpy[i] == 0 ) {
                sum += customers[i] ;
            }
        }
        int gain = 0 ;
        for ( int i = 0 ; i < minutes ; i++ ) {
            if ( grumpy[i] == 1 ) {
                gain += customers[i] ;
                maxi = max(maxi , gain) ;
            }
        }
        for ( int i = minutes ; i < n ; i++ ) {
            if ( grumpy[i] == 1 ) {
                gain += customers[i] ;
            }
            if ( grumpy[i-minutes] == 1) {
                     gain -= customers[i-minutes] ;
                }
            maxi = max(maxi , gain) ;
        }
        return sum + maxi ;
    }
};