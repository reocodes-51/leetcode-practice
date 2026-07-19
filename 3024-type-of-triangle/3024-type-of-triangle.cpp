class Solution {
public:
    string triangleType(vector<int>& nums) {

        string ans = "none" ;
        int a = nums[0] ;
        int b = nums[1] ;
        int c = nums[2] ;

        if (a + b <= c || a + c <= b || b + c <= a) {
            return ans ;
        }
        else if ( a == b && b == c && a == c ) { 
            ans = "equilateral" ;
        }
        else if ( a==b || a==c || b==c) {
            ans = "isosceles";
        }
        else {
            ans = "scalene";
        }
        return ans ;
    }
};