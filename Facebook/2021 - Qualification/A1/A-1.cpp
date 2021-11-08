#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
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
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second
//
ifstream input("a1(FULL-input).txt");
ofstream output("a1(FULL-output).txt");

bool vow(char c) {
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void solve (){
	int ans = 0;
	string s;
	input >> s;
	
	map<char, int> mp;
	for (char c : s) mp[c]++;
	
	int countVowels = 0;
	int countConsonants = 0;
	int maxVowel = 0;
	int maxConsonant = 0;
	
	each(it, mp) {
		if (vow(it->ff)) {
			// Vowel
			maxVowel = max(maxVowel, it->ss);
			countVowels += it->ss;
		} else {
			// Consonant
			maxConsonant = max(maxConsonant, it->ss);
			countConsonants += it->ss;			
		}
	}
	
	// MINIMUM of
	// turning all consonants to the maxVowel + 2 * (all vowels - maxVowel)
	
	ans = min(countConsonants + 2 * (countVowels - maxVowel) , countVowels + 2 * (countConsonants - maxConsonant));
	
	output << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T, CASE = 0;
	input >> T;
	while (CASE++ < T) {
		output << "Case #" << CASE << ": ";
		solve();
	}
	output.close();
	return 0;
}


// Lorenzo Fiorini