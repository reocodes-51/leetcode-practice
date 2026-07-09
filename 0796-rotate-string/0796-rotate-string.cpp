class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
        return false;
        string rotated = s ;
        for ( int i=0 ; i<goal.size() ; i++ ) {
            for ( int j=0 ; j<goal.size() ; j++ ) {
                rotated[j] = s[ (j+i)% s.size()] ;
            }
            if ( rotated == goal ) {
                return true ;
            }
            else {
                continue ;
            }
        }
        return false ;
        
    }
};