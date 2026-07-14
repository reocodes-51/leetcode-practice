class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector <int> ans ;
        int index = 0 ;
        int n = words.size() ;

        while ( index < n ) {

            for ( int i=0 ; i<words[index].size() ; i++ ) {
                if ( words[index][i] == x ) {
                    ans.push_back(index);
                    break ;
                }
            }
            index++;
        }
        return ans ;
        
    }
};