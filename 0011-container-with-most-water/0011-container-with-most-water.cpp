class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ; 

        int left = 0 ;
        int right = n-1 ;
        long long maxi = 0 ;

        while ( left < right ) {

            long long temp  = (right-left)*(min(height[left],height[right])) ;
            maxi = max(maxi , temp) ;

            if ( height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxi ;
        
    }
};