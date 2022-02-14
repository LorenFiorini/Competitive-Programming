#include <bits/stdc++.h>
using namespace std;



/*
 * Complete the 'maxPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY skillLevel
 *  2. INTEGER minDiff
 */

int maxPairs(vector<int> skillLevel, int minDiff) {
    map<int, int> mp;
    //int n = skillLevel.size();
    //cout << n << endl;
    //cout << minDiff << endl;
    
    for (int level : skillLevel) {
       //cout << level << " ";
        mp[level]++;
    }
    
    int ans = 0;
    //auto ita = mp.begin();
    //auto ite = mp.lower_bound(ita->first + minDiff);
    for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it -> first << " -> " << it->second << endl;
	}
    
    while (1) {
        set<int> del;
        map<int, vector<int>> mapa;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            auto to = mp.lower_bound(it->first + minDiff);
            if (to == mp.end()) break;
            int dif = (to->first) - (it->first);
            mapa[dif].push_back(it->first);
        }
        if (mapa.size() == 0) break;
        for (auto it = mp.begin(); it != mp.end(); it++) {
			cout << it -> first << " -> " << it->second << endl;
		}
        
        for (auto start = mapa.begin(); start != mapa.end(); start++) {
            for (int num : start->second) {
                int num2 = num + start->first;
                int dif = min(mp[num], mp[num2]);
                ans += dif;
                mp[num] -= dif;
                mp[num2] -= dif;
                if (mp[num] == 0) del.insert(num);
                if (mp[num2] == 0) del.insert(num2);
            }
        }
        
        for (int num : del) {
            mp.erase(num);
        }
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << maxPairs(v, k) << endl;
}
