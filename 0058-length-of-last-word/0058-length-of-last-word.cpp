class Solution {
public:

    string trim(string s) {
    int start = s.find_first_not_of(' ');
    int end = s.find_last_not_of(' ');

    if (start == string::npos)
        return "";

    return s.substr(start, end - start + 1);
    }

    int lengthOfLastWord(string s) {
        string temp = trim(s) ;
        int length = 0 ;
        for ( int i=temp.size()-1 ; i>=0 ; i--) {
            if ( temp[i] == ' ') {
                break ;
            }
            else {
                length++;
            }
        }
        return length ;

    }
};