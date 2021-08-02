#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[105],prime[100005],p[105],pn=50,pt,vis[105];
int main()
{
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
//	printf("pt=%d\n",pt);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ll ans=2e18;
	for(int i=1;i<(1<<pt);i++)
	{
		ll mul=1;
		for(int j=1;j<=n;j++)
			vis[j]=0;
		for(int j=1;j<=pt;j++)
			if((i&(1<<(j-1))))
			{
				for(int k=1;k<=n;k++)
					if(a[k]%prime[j]==0)
						vis[k]=1;
				mul*=prime[j];
			}
		int fl=1;
		for(int j=1;j<=n;j++)
			if(!vis[j]) fl=0;
		if(fl)
		{
			ans=min(ans,mul);
	//	if(i==(1<<pt)-1)	printf("mul=%lld\n",mul);
		}
	}
	printf("%lld\n",ans);
	return 0;
}