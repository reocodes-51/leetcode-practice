class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<long long, int> PresumMap;

        PresumMap[0] = 1;

        long long sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            long long rem = sum - goal;

            if (PresumMap.find(rem) != PresumMap.end()) {
                count += PresumMap[rem];
            }

            PresumMap[sum]++;
        }

        return count;
        
    }
};