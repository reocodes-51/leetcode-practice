class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n=stones.size();
        int count = 0 ;

        for ( int i=0 ; i<n ; i++ ) {
            auto it = find(jewels.begin() , jewels.end() , stones[i] ) ;
            if ( it != jewels.end() ) {
                count++;
            }
        }
        return count ;

        
    }
};