class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int total_sum = 0 ;
        int maxi = 0 ;
        int left = 0 ;
        int n = cardPoints.size() ;

        for ( int i=0 ; i<n ; i++ ) {
            total_sum += cardPoints[i] ;
        }

        int win_sum = 0 ;
        int len = n-k ;

        for ( int right = 0 ; right < len ; right++ ) {
            win_sum += cardPoints[right] ;
        }
        int mini = win_sum ;
        for ( int i = len ; i < n ; i++ ) {
            win_sum += cardPoints[i] ;
            win_sum -= cardPoints[i-len];
            mini = min( mini , win_sum ) ;
        }
        maxi = total_sum - mini ;
        return maxi ;
        
    }
};