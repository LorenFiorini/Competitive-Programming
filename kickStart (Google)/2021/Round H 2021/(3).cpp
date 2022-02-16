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

struct Node {
	int val;
	Node* pre;
	Node* next = nullptr;
};

void shownodes(Node* head) {
	while (head != nullptr) {
		cout << head->val;
		//Node* tmp = head;
		head = head->next;
		//delete tmp;
	}
	cout << "\n";
}

Node* input() {
	int n;
	vector<Node*> v(n, new Node);
	cin >> n;
	string s;
	cin >> s;
	rep (i, 0, n) {
		if (i+1<n) {
			v[i]->next = v[i+1];
		}
		v[i]->val = s[i] - '0';
	}
	return v[0];
}

bool replace(Node* head) {
	Node* cur = head;
	bool change = 0;
	while (cur->next != nullptr) {
		if (cur->val + 1 == cur->next->val) {
			change = 1;
			cur->val = (cur->val + 2) % 10;
			//Node *tmp = cur->next;
			cur->next = cur->next->next;
			//delete tmp;
		} else{
			cur = cur->next;
		}
	}
	shownodes(head);
	return change;
}



void solve () {
	Node* head = input();
	bool changed = 1;
	shownodes(head);
	/*
	do {
		changed = replace(head);
	} while(changed);
	*/
	shownodes(head);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
