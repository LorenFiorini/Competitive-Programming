#include "bits/stdc++.h"
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
#define por(I_, A_, B_, in__) for (int I_ = A_; I_ < (B_); I_ += in__)
#define rep(I_, A_, B_) por(I_, A_, B_, 1)
#define each(it, MP) for (auto it = MP.begin(); it != MP.end(); it++)
#define all(C_) C_.begin(), C_.end()
#define allg(C_) all(C_), greater<> ()
#define len(V_) (int) V_.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(X_) cout << X_ << "\n";
#define showbin(X_) for (int I = (1 << 30); I > 0; I >>= 1) {cout << ((X_&I)? 1: 0);} cout << "\n";
#define showp(X_, Y_) cout << X_ << " " << Y_ << "\n";
#define showv(V_) for (auto A_: V_) {cout << A_ << " ";} cout << "\n";
#define showvp(V_) for (auto P_: V_) {showp(P_.first, P_.second);}
#define showmat(MAT) for (auto R_: MAT) {showv(R_);}
#define showset(ST) for (auto X_: ST) {cout << X_ << " ";} cout << "\n";
#define showmap(MP) for (auto P_: MP) {cout << P_.first << " " << P_.second << "\n";} cout << "\n";


void solve (void) {
	int ans = 0;
	int n, q;
	string s;
	cin >> s;
	cin >> q;

	n = s.size();
	vector<vector<int>> cnt(26, vector<int>(n+1, 0));
	for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            cnt[j][i] = cnt[j][i+1];
        }
        cnt[s[i]-'a'][i]++;
    }

    map<char, int> index;
    for (int i = 0; i < n; i++) {
        if (index.find(s[i]) == index.end()) {
            index[s[i]] = i;
            if (len(index) == 26) break;
        }
    }
    showmat(cnt);


	while (q--) {
		char a, b;
		cin >> a >> b;
        if (index.find(a) == index.end() || index.find(b) == index.end()) {
            ans = 0;
        } else if (a == b) {
            ans = cnt[b - 'a'][index[a] - 1];
        } else {
            ans = cnt[b - 'a'][index[a] - 1] - cnt[b - 'a'][index[b]];
        }
		
		
		cout << ans << endl;
	}
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
