#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; ++i)
using namespace std;

typedef __int128_t ll;
const ll mod = 360 * 12 * ll(1e5) * ll(1e5);

ll inv(ll a, ll m) {
    return a-1 ? m - m*inv(m%a, a)/a : 1;
}

ll inv_seg = inv(11, mod);
ll inv_min = inv(719, mod);

ll anda(ll h, ll m, ll s) {
	m = (m-h+mod)%mod;
	s = (s-h+mod)%mod;
	if((m*inv_min - s*inv_seg) % mod != 0) return -1;
	return (m*inv_min) % mod;
}

int main() {
	assert(inv_seg > 0);
	assert(inv_min > 0);
	
	assert(inv_seg * 11 % mod == 1);
	
	int t;
	cin >> t;
	forn(test, t) {
		long long hh, mm, ss;
		cin >> hh >> mm >> ss;
		ll h = hh;
		ll m = mm;
		ll s = ss;
		
		for(ll i : {
			anda(h, m, s),
			anda(h, s, m),
			anda(m, h, s),
			anda(m, s, h),
			anda(s, h, m),
			anda(s, m, h),
		}) {
			if(i != -1) {
				long long nano = (long long)(i%ll(1e9));
				i /= ll(1e9);
				
				long long seg = (long long)(i%60); i/=60;
				long long min = (long long)(i%60); i/=60;
				long long hor = (long long)(i%12); i/=12;
				cout << "Case #" << test+1 << ": " << hor << " " << min << " " << seg << " " << nano << "\n";
				break;
			}
		}
	}
}
