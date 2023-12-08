/*
B. Two Out of Three
time limit per test3 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
. You need to find an array 𝑏1,𝑏2,…,𝑏𝑛
 consisting of numbers 1
, 2
, 3
 such that exactly two out of the following three conditions are satisfied:

There exist indices 1≤𝑖,𝑗≤𝑛
 such that 𝑎𝑖=𝑎𝑗
, 𝑏𝑖=1
, 𝑏𝑗=2
.
There exist indices 1≤𝑖,𝑗≤𝑛
 such that 𝑎𝑖=𝑎𝑗
, 𝑏𝑖=1
, 𝑏𝑗=3
.
There exist indices 1≤𝑖,𝑗≤𝑛
 such that 𝑎𝑖=𝑎𝑗
, 𝑏𝑖=2
, 𝑏𝑗=3
.
If such an array does not exist, you should report it.

Input
Each test contains multiple test cases. The first line contains a single integer 𝑡
 (1≤𝑡≤500)
 — the number of test cases. Each test case is described as follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤100)
 — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤100)
 — the elements of the array 𝑎
.

Output
For each test case, print -1 if there is no solution. Otherwise, print 𝑏1,𝑏2,…,𝑏𝑛
 — an array consisting of numbers 1
, 2
, 3
 that satisfies exactly two out of three conditions. If there are multiple possible answers, you can print any of them.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;
typedef int64_t ll;

// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_.first << " " << a_.second << "\n";} cout << "\n";


void solve () {
	int ans = 0;
	int n;
	cin >> n;
    vector<int> a(n);
    vector<int> vec(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
	map<int, int> cnt;
    map<int, vector<int> > pos;

    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        pos[a[i]].push_back(i);
    }
	
    // for (auto &pa: cnt) {
    //     cout << pa.first << " - " << pa.second << "\n";
    // }
	// for (auto pa: pos) {
    //     cout << pa.first << ": ";
    //     showv(pa.second);
    // }
    vector<int> ansvec;
    for (auto &pa: cnt) {
        if (pa.second == 3) {
            ans += 2;
            auto it = pos.find(pa.first);
            vec[it->second[0]] = 2;
            vec[it->second[1]] = 3;
            vec[it->second[2]] = 3;
            showv(vec);
            return;
        } else if (pa.second == 2) {
            ansvec.push_back(pa.first);
            if (ansvec.size() == 2) {
                    for (int i = 0; i < 2; i++) {
                        auto it = pos.find(ansvec[i]);
                        vec[it->second[0]] = 2;
                        vec[it->second[1]] = 3;
                    }
                showv(vec);
                return;
            }
        }
    }
    if (ansvec.size() > 1) {
        
    }
    show(-1);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	{
    	solve();
        // cout << endl;
    }
	
	return 0;
}

/* Lorenzo Fiorini */
