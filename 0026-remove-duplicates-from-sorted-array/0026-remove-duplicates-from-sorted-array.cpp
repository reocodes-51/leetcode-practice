class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // set <int> st  ;
        // for ( auto x : nums ) {
        //     st.insert(x) ;
        // }
        // int index=0;
        // for ( auto x : st ) {
        //     nums[index]=x;
        //     index++;
        // }
        // return index ;
        int ans = 0 ;
        int slow = 0 ;
        for ( int fast = 1 ; fast < nums.size() ; fast++ ) {
            if ( nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast] ;
            }
        }
        return slow + 1 ;
    }
};