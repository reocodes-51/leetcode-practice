class Solution {
public:
    int maxProduct(int n) {

        int copy = n ;
        int maxi = 0 ;
        int sec_maxi = 0 ;
        int mx_cnt = 0 ;
        long long max_product = 0 ;

        while ( n > 0 ) {
            int temp = n%10 ;
            maxi = max( maxi , temp ) ;
            n=n/10;
        }
         while ( copy > 0 ) {
            int temp = copy%10 ;
            if ( temp == maxi ) {
                mx_cnt++;
            }
            else {
                sec_maxi = max(sec_maxi , temp);
            }
            copy = copy/10;
         }

        if ( mx_cnt >= 2 ) {
            max_product = maxi*maxi ;
        }
        else {
            max_product = sec_maxi*maxi ;
        }

        

        return max_product ;
        
    }
};