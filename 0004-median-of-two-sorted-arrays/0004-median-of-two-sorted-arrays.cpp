class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0 ;
        vector <int> result = nums1 ;
        result.insert( result.end() , nums2.begin() , nums2.end() ) ;
        sort(result.begin() , result.end() ) ;

        int n = result.size() ;

        if ( n%2 == 1 ) {
            int temp = (n/2) ;
            median = result[temp];
        }
        else {
            int k = n/2 ;
            median = (result[k-1]+result[k])/2.0;
        }
        return median ;
    }
};