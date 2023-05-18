'''
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_cube(ll num)
{
	ll lo = 1, hi = 1e5;
	while (lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		ll cube = mid * mid * mid;
		if (cube == num)
			return true;
		else if (cube < num)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return false;
}

int main (void)
{
	ll N;
	cin >> N;
	vector<ll> v(N);
	for (ll i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	set<ll> S;

	ll ans = 0;
	for (ll i = 0; i < N; i++)
	{
		bool ok = true;
		for (ll num: S) {
			ok &= (!is_cube(num * v[i]));
			if (!ok)
				break;
		}
		if (ok) {
			S.insert(v[i]);
			ans++;
		}

	}

	cout << ans << endl;
	return (0);
}
'''

# Rewrite in Python

#import sys
#print("Python version")
#print (sys.version)
#
#print("Version info.")
#print (sys.version_info)
#
#import math

'''
def is_cube(num: int):
	if num == 1:
		return True
	lo = 1
	hi = num + 1
	while lo <= hi:
		mid = (lo + hi) // 2
		cube = mid * mid * mid
		if cube == num:
			return True
		elif cube < num:
			lo = mid + 1
		else:
			hi = mid - 1
	return False
'''

def is_cube(num: int):
	if num == 1:
		return True
	x = int(pow(num, float(1/3)))
	return (x * x * x == num)

def solve(N: int, v: list):
	S = set()
	ans = 0
	for i in range(N):
		ok = True
		for num in S:
			ok &= is_cube(num * v[i]) == False
			if not ok:
				break
		if ok:
			S.add(v[i])
			ans += 1
	return ans

if __name__ == '__main__':
	N = int(input())
	v = list(int(input()) for _ in range(N))
	v.sort()
	ans = solve(N, v)
	v.reverse()
	ans = max(ans, solve(N, v))
	print(ans)
