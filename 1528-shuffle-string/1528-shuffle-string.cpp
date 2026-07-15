class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        string ans = "" ;
        vector <char> hash(s.size() , 0 ) ;

        for ( int i=0 ; i<s.size() ; i++ ) {
            hash[indices[i]] = s[i] ;
        }

        for ( int i=0 ; i<s.size() ; i++) {
            char temp = hash[i] ;
            ans += temp ;
        }

        return ans ;
        
    }
};