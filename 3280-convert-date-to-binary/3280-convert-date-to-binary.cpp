class Solution {
public:
    string binary ( int n ) {

         if (n == 0)
            return "0";

        string ans = "" ;
        while ( n>0 ) {
            ans += n%2 + '0' ;
            n=n/2 ;
        }
        reverse(ans.begin() , ans.end() ) ;
        return ans ;
    }

    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        string ans = "";
        ans += binary(year) ;
        ans +="-";
        ans += binary(month) ;
        ans +="-";
        ans += binary(day) ;

        return ans ;
    }
};