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
typedef set<int> seti;
typedef map<int,seti> mpii;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

vint pr;
void sieve() {
	int N = 32000;
	int lp[N+1];
	rep (i, 2, N+1) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < len(pr) && pr[j] <= lp[i] && i*pr[j] <= N; j++ ) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

void factors(vint &v, int num) {
	rep (i, 0, len(pr)) {
		ll d = (ll) (pr[i]);
		if (d * d > (ll) num) break;
		
		while (num % (int) d == 0) {
			v.pb((int) d);
			num /= (int) d;
		}
	}
	if (num > 1) {
		v.pb(num);
	}
}




void add(mpii &mp, int steps, int div) {
	steps--;
	mpii :: iterator it;
	it = mp.find(steps);
	if (it == mp.end()) {
		seti st;
		st.insert(div);
		mp.insert(mk(steps, st));
	}
	else {
		it->ss.insert(div);
	}
}

void divStep(mpii &mp, vint &v) {
	int n = len(v);
	vvi pre(n , vint(n, 1) );
	
	rep (i, 0, n) {
		rep (j, i, n) {
			if (i == 0) {
				pre[i][j] = v[j];
				if (j) pre[i][j] *= pre[i][j-1];
				add(mp, i + n - j, pre[i][j]);
			} else if (i < j){
				int d = v[i-1];
				pre[i][j] = pre[i-1][j] / d;
				add(mp, i + n - j, pre[i][j]);
			}
		}
	}
	
}

bool ok(mpii& mpa, mpii& mpb, int step) {
	mpii :: iterator ita = mpa.find(step); 
	mpii :: iterator itb = mpb.find(step); 
	if (ita == mpa.end() || itb == mpb.end()) {
		return false;
	}
	
	each ( div , ita->ss) {
		int divisor = *div;
		seti :: iterator setdiv;
		setdiv = itb->ss.find(divisor);
		if (setdiv != itb->ss.end())  {
			return true;
		} else show(divisor);
	}
	return false;
	
}

void solve () {
	int a,b,k;
	cin >> a >> b >> k;
	
	vint fA;
	vint fB;
	factors(fA, a);	
	factors(fB, b);
	//showv(fA, len(fA));
	//showv(fB, len(fB));
	
	mpii mpa;
	mpii mpb;
	divStep(mpa, fA);
	divStep(mpb, fB);
	/*
	each(it, mpa) {
		show("step - divisor");
		cout << it->ff << "\n";
		showset(itttt, it->ss);
	}*/
	if (ok(mpa, mpb, k)) {
		show("YES");
	} else {
		show("NO");
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	sieve();
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
