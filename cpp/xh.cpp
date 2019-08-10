#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
int n,now,res;
typedef pair<int,int> II;
II f[maxn];
int cmp(II a,II b)
{
    if (a.fs==b.fs)
        return a.sc<b.sc;
    return a.fs<b.fs;
}
int main()
{
    freopen("xh.inp","r",stdin);
    //freopen("xh.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>f[i].fs;
        f[i].sc=i;
    }
    sort(f+1,f+n+1,cmp);
    now=1;
    for (int i=2;i<=n;i++)
        if (f[i].sc>f[i-1].sc)
    {
        now++;
    }
    else{
        res=max(res,now);
        now=1;
    }
    res=max(res,now);
    cout<<n-res;
    return 0;
}
