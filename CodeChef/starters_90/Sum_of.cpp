#include <bits/stdc++.h>
using namespace std;

#define mod1 998244353
#define mod2 1000000007
#define ll int long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

unsigned long long fac[200000 + 1];
//fac[0] = 1;
    

unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < (unsigned ll) r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
   
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int main(){
    fastio()
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fac[i] = (fac[i - 1] * i) % mod2;
    }
    
	int t; cin>>t; 
	while(t--){
        int n; cin>>n; int a[n];
        for (int i = 0; i < n ; i++) {
            cin>>a[i];
        }
        sort(a, a+n);
        ll sum = 0;
        for (int i = 0; i < n ; i++) {
            if( a[i] - 1 <= i ){
                ll test = nCrModPFermat(i , a[i]-1, mod2);
                test*= power(2,n-1-i,mod2);
                test = test%mod2;
                sum += test; sum = sum%mod2;
            }
            
            cout << i << ": " << sum << endl;
        }
        cout<<sum<<endl;
        // for (int i = 0; i < n ; i++) {
        //     cout<<a[i].first<<" ";
        // }cout<<endl;
        // for (int i = 0; i < n ; i++) {
        //     cout<<a[i].second<<" ";
        // }cout<<endl;
	  
	}
	return 0;
}
