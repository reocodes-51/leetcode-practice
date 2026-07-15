class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

        int count = 0 ;
        int compare = 0 ;

        if ( ruleKey == "type" ) compare = 0 ;
        else if ( ruleKey == "color" ) compare = 1 ;
        else compare = 2 ;

        for ( int i=0 ; i<items.size() ; i++ ) {

            if ( ruleValue == items[i][compare] ) {
                count++;
            }
        }

        return count ;
        
    }
};