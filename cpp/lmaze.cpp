#include<bits/stdc++.h>
#define maxn 10000007
using namespace std;
int s[maxn],n,dd[maxn],dem1,dem2,now;
int res;
int main()
{
    freopen("lmaze.inp","r",stdin);
    freopen("lmaze.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s[x]=i;
    }
    now=1;
    dem1=1;
    while (now!=n)
        if (dd[s[now]]==0)
    {
        res++;
        dem1++;
        dd[s[now]]=1;
        now=s[now];
    }
    else {
        cout<<-1;
        return 0;
    }
    dem1-=2;
    dem2=1;
    while(now!=1)
    {
        res++;
        dem2++;
        now=s[now];
    }
    res-=2;
    dem2--;
    res=res+dem1+dem2;
    cout<<res;
    return 0;
}
