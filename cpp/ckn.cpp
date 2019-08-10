#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int n,mod,k;
int dd[maxn+1],pos[maxn],cnt,val[maxn],ans,dm[maxn];
int ngto(int u)
{
    for (int i=2; i*i<=u; i++)
        if (u%i==0) return 0;
    return 1;
}
int power(int x,int n)
{
    if (n==0) return 1;
    if (n==1) return x;
    int tmp=power(x,n>>1);
    tmp=((ll)tmp*tmp)%mod;
    if (n%2) tmp=((ll)tmp*x)%mod;
    return tmp;
}
void update(int u,int st)
{
    if (st==1)
    {
        for (int i=1; i<=cnt; i++)
        {
            while(u%val[i]==0)
            {
                u/=val[i];
                dm[i]++;
            }
            if (u==1||ngto(u))
            {
                dm[pos[u]]++;
                return ;
            }
        }
    }
    else
    {
        for (int i=1; i<=cnt; i++)
        {
            while(u%val[i]==0)
            {
                u/=val[i];
                dm[i]--;
            }
            if (u==1||ngto(u))
            {
                dm[pos[u]]--;
                return ;
            }
        }
    }
}
int main()
{
    freopen("ckn.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>mod;
    for (int i=2; i*i<=maxn; i++)
        if (!dd[i])
        {
            for (int j=i*i; j<=maxn; j+=i)
            {
                dd[j]=1;
            }
        }
    for (int i=2;i<=maxn;i++)
        if (!dd[i])
    {
            val[++cnt]=i;
            pos[i]=cnt;
    }
    for (int i=2; i<=n; i++)
    {
        update(i,1);
    }
    for (int i=2; i<=k; i++)
    {
        update(i,2);
    }
    for (int i=2; i<=n-k; i++)
        update(i,2);
    ans=1;
    for (int i=1; i<=cnt; i++)
    {
            ans=((ll)ans*power(val[i],dm[i]))%mod;
    }
    cout<<ans;
    return 0;
}
