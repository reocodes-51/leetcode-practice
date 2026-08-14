class Solution {
public:
    int maximumLengthSubstring(string s) {

        map<char,int> freq ;
        int mx = 0 ;
        int left = 0 ;
        for ( int right = 0 ; right < s.size() ; right++ ) {

            freq[s[right]]++;
            while( freq[s[right]]>2) {
                freq[s[left]]--;
                left++;
            }
            mx = max(mx,right-left+1);
        }
        return mx ;
    }
};