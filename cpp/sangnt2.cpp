#include<bits/stdc++.h>
#define maxn 10000007
using namespace std;
int a[2*maxn];
long long res;
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	for (int i=2;i<=int(sqrt(2*maxn));i++)
	if (a[i]==0)
	{
		int j=i*i;
		while (j<=2*maxn)
		{
			a[j]=1;
			j+=i;
		}
	}
	for (int i=maxn+1;i<2*maxn;i++)
	{
		if (a[i]==0) res++;
	}
	cout<<res;
	return 0;
}
