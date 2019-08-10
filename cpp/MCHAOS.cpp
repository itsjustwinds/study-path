#include<bits/stdc++.h>
#define db double
#define fs first
#define sc second
#define maxn 100005
using namespace std;
typedef pair<string,int> II;
int bit[maxn],n;
long long res;
II a[maxn];
II ac[maxn];
bool cmp1(II a,II b)
{
    return a.fs<b.fs;
}
int get(int u)
{
    long long kq=0;
    while(u<=maxn)
    {
        kq=kq+bit[u];
        u+=u&(-u);
    }
    return kq;
}
void update(int u)
{
    while(u)
    {
        bit[u]=bit[u]+1;
        u-=u&(-u);
    }
}
int main()
{
    freopen("MCHAOS.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fs;
        for (int j=a[i].fs.length()-1;j>=0;j--)
        {
            ac[i].fs=ac[i].fs+a[i].fs[j];
        }
        ac[i].sc=i;
    }
    sort(ac+1,ac+n+1,cmp1);
    for (int i=1;i<=n;i++)
        a[ac[i].sc].sc=i;
    sort(a+1,a+n+1,cmp1);
    for (int i=1;i<=n;i++)
    {
        res+=get(a[i].sc+1);
        update(a[i].sc);
    }
    cout<<res;
    return 0;
}
