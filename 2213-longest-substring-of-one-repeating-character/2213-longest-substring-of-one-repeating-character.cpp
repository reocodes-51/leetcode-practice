class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int prefix;
        int suffix;
        int maxi;
        int len;

        Node() {
            leftChar = '#';
            rightChar = '#';
            prefix = 0;
            suffix = 0;
            maxi = 0;
            len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0)
            return b;

        if (b.len == 0)
            return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;

        res.maxi = max(a.maxi, b.maxi);

        // Entire left + beginning of right
        if (a.rightChar == b.leftChar) {

            if (a.prefix == a.len) {
                res.prefix = a.len + b.prefix;
            }

            if (b.suffix == b.len) {
                res.suffix = b.len + a.suffix;
            }

            res.maxi = max(res.maxi, a.suffix + b.prefix);
        }

        return res;
    }

    void build(int node, int start, int end, string &s) {

        if (start == end) {

            tree[node].leftChar = s[start];
            tree[node].rightChar = s[start];

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].maxi = 1;
            tree[node].len = 1;

            return;
        }

        int mid = (start + end) / 2;

        build(node * 2, start, mid, s);
        build(node * 2 + 1, mid + 1, end, s);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int index, char ch) {

        if (start == end) {

            tree[node].leftChar = ch;
            tree[node].rightChar = ch;

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].maxi = 1;

            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid) {
            update(node * 2, start, mid, index, ch);
        }
        else {
            update(node * 2 + 1, mid + 1, end, index, ch);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, index, ch);

            ans.push_back(tree[1].maxi);
        }

        return ans;
    }
};