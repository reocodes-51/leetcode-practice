class Solution {
public:
    int scoreOfString(string s) {

        long long int score = 0 ;
        for ( int i=1 ; i<s.size() ; i++ ) {
            int forward = s[i] - 'a' ;
            int backward = s[i-1] - 'a' ;
            int temp = forward-backward ;
            score += abs(temp) ;
        }
        return score ;
        
    }
};