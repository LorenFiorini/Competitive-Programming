/*
A. Channel
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya is an administrator of a channel in one of the messengers. A total of n
 people are subscribed to his channel, and Petya is not considered a subscriber.

Petya has published a new post on the channel. At the moment of the publication, there were a
 subscribers online. We assume that every subscriber always reads all posts in the channel if they are online.

After this, Petya starts monitoring the number of subscribers online. He consecutively receives q
 notifications of the form "a subscriber went offline" or "a subscriber went online". Petya does not know which exact subscriber goes online or offline. It is guaranteed that such a sequence of notifications could have indeed been received.

Petya wonders if all of his subscribers have read the new post. Help him by determining one of the following:

it is impossible that all n
 subscribers have read the post;
it is possible that all n
 subscribers have read the post;
it is guaranteed that all n
 subscribers have read the post.
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first line of each test case contains three integers n
, a
, and q
 (1≤n≤100
, 0≤a≤n
, 1≤q≤100
) — the number of subscribers of the channel, the initial number of subscribers online, and the number of notifications.

The second line of each test case contains a string of length q
, consisting of characters '+' and '-'. The i
-th of these characters is '+', if the i
-th notification tells that a subscriber goes online, and it is '-' otherwise.

Output
For each test case, output a single line: "YES" if all n
 subscribers are guaranteed to have read the post, "NO" if it is impossible for all n
 subscribers to have read the post, and "MAYBE" otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";

void solve(void) {
	string ans = "NO\n";
	int n, a, q;
	cin >> n >> a >> q;
	string s;
	cin >> s;

	// All subscribers are online
	int cnt[2] = {0, 0};

	for (int i = 0; i <= q; i++) {
				
		if (a + cnt[1] - cnt[0] >= n) {
			cout << "YES\n";
			return;
		} else if (a + cnt[1] >= n) {
			ans = "MAYBE\n";
		}

		if (i < q) {
			if (s[i] == '+') {
				cnt[1]++;
			} else {
				cnt[0]++;
			}
		}
	}

	cout << ans;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t; while (t--)
	solve();
	
	return 0;
}

// Lorenzo Fiorini
