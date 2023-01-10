#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()

int t, n, q;


struct Node {
	int val;
	Node *next;
	Node (int x) : val(x), next(nullptr) {}
	Node (int x, Node *next) : val(x), next(next) {}
};
/*
int ask(int i) {
    cout << i-1 << " " << i << " " << i+1 << endl;
    cout << flush;
    //fflush(stdout);
    int ans; cin >> ans;
    return ans - i;
}*/

int ask(int l, int r, int nw) {
    cout << l << " " << r << " " << nw << endl;
    cout << flush;
    int ans; cin >> ans;
    return ans;
    // if ans == nw -> insert
    // elif ans == r -> continue iteration
    // it wont be ans == l on this implementation 
}

void insert(Node* &head, Node* novo) {
	Node* cur = head -> next;
	Node* prev = head;
	while (cur != nullptr) {
		/*
		if (cur == nullptr) {
			prev->next = novo;
			break;
		}*/
		//ask
		int l = prev->val;
		int r = cur->val;
		int k = novo->val;
		int answ = ask(l, r, k);
		// 
		if (answ == k) {
			prev->next = novo;
			novo->next = cur;
			break;
		} else if (answ == l) {
			novo->next = prev;
			head = novo;
			return;
		} else {
			cur = cur->next;
			prev = prev->next;
		}
	}
	prev->next = novo;
	return;
}

void print(Node* &head) {
	Node* cur = head;
	while (cur != nullptr) {
		cout << cur->val << " "; 
	}
	cout << endl << flush;
}

void solve () {
	Node *ans;
	
	REP (num, 1, n + 1) {
		Node* novo;
		novo->val = num;
		if (num == 1) {
			ans = novo;
		} else if (num == 2) {
			ans->next = novo;
		} else {
			insert(ans, novo);
		}
    }
    
    vector<int> v(n, 0);
    Node* cur = ans;
    int cnt = 1;
    while (cur != nullptr ) {
		v[cur->val - 1] = cnt;
		cur = cur->next;
		cnt++;
	}
    REP (i, 0, n) cout << v[i] << " ";
    
	cout << endl << flush;
    int answer; cin >> answer;
    if (answer == -1) t = 0;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> t >> n >> q;
	while (t-->0) {
		solve();
	}
	
	return 0;
}
