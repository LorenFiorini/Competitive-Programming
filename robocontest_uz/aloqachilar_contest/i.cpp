#include <bits/stdc++.h>
using namespace std;

int v[] = {0, 0, 0, 1, 5, 13, 35, 49, 126, 161, 330, 301, 715, 757, 1365, 1377, 2380, 1837, 3876, 3841, 5985, 5941, 8855, 7297, 12650, 12481, 17550, 17249, 23751, 16801, 31465, 30913, 40920, 40257, 52360, 46981, 66045, 64981, 82251, 80881, 101270, 84841, 123410, 121441, 148995, 146741, 178365, 164161, 211876, 208801, 249900, 246273, 292825, 272485, 341055, 336337, 395010, 389761, 455126, 405181, 521855, 515221, 595665, 588161, 677040, 639013, 766480, 757249, 864501, 854421, 971635, 934561, 1088430, 1076257, 1215450, 1202017, 1353275, 1296517, 1502501, 1486561, 1663740, 1646561, 1837620, 1754173, 2024785, 2004661, 2225895, 2204049, 2441626, 2354761, 2672670, 2647393, 2919735, 2892757, 3183545, 3096961, 3464840, 3433921, 3764376, 3731201, 4082925};

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cout << v[n-1] << endl;

	return 0;
}

// Lorenzo Fiorini