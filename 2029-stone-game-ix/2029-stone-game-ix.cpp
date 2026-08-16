class Solution {
public:

    bool stoneGameIX(vector<int>& stones) {

        int zero = 0;
        int one = 0;
        int two = 0;

        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] % 3 == 0) {
                zero++;
            }
            else if (stones[i] % 3 == 1) {
                one++;
            }
            else {
                two++;
            }
        }

        if (zero % 2 == 0) {
            if (one > 0 && two > 0) {
                return true;
            }
            return false;
        }

        else {
            if (abs(one - two) > 2) {
                return true;
            }
            return false;
        }
    }
};