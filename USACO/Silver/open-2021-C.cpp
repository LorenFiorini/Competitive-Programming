#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
typedef int ll;
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
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
//cout << setprecision(d) << fixed;


void input () {
	int answer = 0;
	int n, k, l;
	cin >> n >> k >> l;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	// cambios
	int p = 0;
	vector<int> pos(1 , 0);
	
	//recorrer surveys
	sort(v.begin(), v.end(), greater<> ());
	for (int i = 0; i < n; i++) 
	{
		// pointer to last
		if (i > 0 && v[i-1] > v[i]) {
			pos.pb(i);
			p++;// = len(pos) - 1; 
		}
		
		// largo
		int blo = i + 1 - pos[p]; 
		
		//index
		int index = min(v[i], i + 1);
		
		//altura
		//int alt = min(k, i + 1 - v[i]);
		
	// change index if possible ______________________________
		if (v[i] < i + 1)
		{
			int pp = p;
			int kk = k;
			while (blo <= l && pp >= 0 && kk >= 0){
				int alt = min(v[pp] + kk, (pp-1 >= 0)? v[pos[pp-1]] : v[0]);
				
				index = min(alt, i + 1);
				
				blo += pos[pp] - pos[(pp-1 >= 0)? v[pos[pp-1]] : v[0]];
				kk -= (alt - v[pp]);
				pp--;
			} 
		}
	// change index if possible ______________________________		
		
		show(index);
		answer = max(answer, index);
	}
	show("");
	showv(pos, p+1);
	cout << answer << "\n";
}

int main () 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();	
	return 0;
}

/*
 if (blo * alt == l) 
			{
				index += alt;
			} 
			else if (blo * alt > l) 
			{
				int rest = alt - (l / blo);
				index += (alt - rest);
			} 
			else if (blo * alt < l)
			{
				index += alt;
				
			}
			
			
			index = v[i] + alt;
*/
