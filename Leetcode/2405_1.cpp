class Solution {
public:
    int partitionString(string &s) {
        s.shrink_to_fit();
        int r = 1;
        bitset<26> a;
        for (auto c = s.begin(); c != s.end(); c++)  {
            bitset<26> a;
            if (a.test(*c - 'a')) {
                a.reset();
                r++;
            }
            a.set(*c);
        }
        return (r);
    }
};