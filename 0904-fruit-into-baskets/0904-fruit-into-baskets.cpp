class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int left = 0 ;
       int n = fruits.size() ;
       int maxi = 0 ;

       unordered_map <int,int> hash ;

       for ( int right = 0 ; right < n ; right++ ) {
            hash[fruits[right]]++;
            while ( hash.size() > 2 ) {
                hash[fruits[left]]--;
                if ( hash[fruits[left]] == 0 ) {
                    hash.erase(fruits[left]);
                }
                left++;
            }
            maxi = max(maxi, right - left + 1);
       }
       return maxi ;
    }
};