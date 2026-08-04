class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<int> ans;

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i-1] + 1;
            while(x < nums[i]) {
                ans.push_back(x);
                x++;
            }
        }

        return ans;
    }
};