ll dfs(vvi &ri, ll col, ll a, ll b, ll &ans) {
	if (a == b) {
		ans = max(ans, 2 * (ri[a][col] + 1));
		return ri[a][col];
	}

	ll up = dfs(ri, col, a+1, b, ans);
	ll da = dfs(ri, col, a, b-1, ans);
	ll mn = min(up, da);
	ll per = 2 * (abs(b - a) + 1 + mn);
	ans = max(ans, per);

	return mn;
}


void solve (void) {
	ll ans = 0;
	ll n, m;
	cin >> n >> m;
	vstr v(n);
	rep(i, 0, n) cin >> v[i];

	// Right
	//show("Right");
	vvi ri(n, vll (m, 0));
	rep (i, 0, n) {
		rep (j, 0, m) {
			if (v[i][j] == '.') {
				ri[i][j] = 1;
				if (j > 0) ri[i][j] += ri[i][j-1];
			} else {
				ri[i][j] = 1;				
			}
		}
	}
	showmat(ri); 

	rep (col, 0, m) {
		ll mn = dfs(ri, col, 0, n-1, ans);
		ans = max(ans, 2 * (n + mn));
	}

	

	show(max(ans - 1, 0));
}