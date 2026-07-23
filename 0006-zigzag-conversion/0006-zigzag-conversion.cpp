class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);

        int currRow = 0;
        bool goingDown = true;

        for (char ch : s) {

            rows[currRow] += ch;

            if (currRow == numRows - 1)
                goingDown = false;

            else if (currRow == 0)
                goingDown = true;

            if (goingDown)
                currRow++;
            else
                currRow--;
        }

        string ans = "";

        for (string row : rows) // isme row wise answer  store ho jayga
            ans += row;

        return ans;
    }
};