class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx = 0 ;
        int index=0;
        int n = sentences.size() ;
       while ( index < n ) {
        int count = 0 ;
        for (int i=0 ; i<sentences[index].size() ; i++ ) {
            if ( sentences[index][i] == ' ' ) {
                count++;
            }
        }
        mx = max(mx , count+1);
        index++;
       }
       return mx ;
        
    }
};