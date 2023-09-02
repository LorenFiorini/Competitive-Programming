class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // int n = 4;
        // for (int i = 0; i < n; i++) {
        //     bool ok = 1;
        //     for (int j = 0; j < n; j++) {
        //         ok &= s1[(i + j) % n] == s2[j];
        //     }
        //     if (ok) return 1;
        // }
        // return 0;
        int n = s1.size();
        vector<vector<int>> cnt(2, vector<int> (26, 0));
        for (int i = 0; i < n; i++) cnt[i % 2][s1[i] - 'a']++;
        for (int i = 0; i < n; i++) cnt[i % 2][s2[i] - 'a']--;
        
        // for (auto ro: cnt) {for (auto a: ro) cout << (char)(a + 'a') << " "; cout << endl;}
        // for (int i = 0; i < n; i++) {
        //     if (cnt[0][i] != 0 || cnt[1][i] != 0)
        //         return false;
        // }
        for (auto ro: cnt) {for (auto a: ro) if (a != 0) return false; }
        return 1;
    }
};
/*
"abcd"
"cdab"
"abcd"
"dacb"
"bnxw"
"bwxn"
"gudo"
"ogdu"
*/