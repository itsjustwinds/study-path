#include <bits/stdc++.h>

using namespace std;
    int n,a[1005],cl[1005][260],f[1005][260];
    int sl[10][1005];
bool kt(int val)
{
    memset(cl,0,sizeof(cl));

    cl[0][0]=1;
    for(int i=1; i<=n; ++i)
    for(int x=0; x<256; ++x)
    {
        if(cl[i-1][x])
            cl[i][x]=1;
        if(x&(1<<(a[i]-1)))
        {
            int y=x^(1<<(a[i]-1));
            int p=sl[a[i]][i]-val+1;
            if(p<0) continue;
            int j=upper_bound(sl[a[i]]+1,sl[a[i]]+n+1,p)-sl[a[i]]-1;
            if(j<i && sl[a[i]][j]==p && cl[j][y])
                cl[i][x]=1;

            p=sl[a[i]][i]-val;
            if(p<0) continue;
            j=upper_bound(sl[a[i]]+1,sl[a[i]]+n+1,p)-sl[a[i]]-1;
            if(j<i && sl[a[i]][j]==p && cl[j][y])
                cl[i][x]=1;
        }
    }

    if(cl[n][255]) return 1;
    return 0;
}
void tinh(int val)
{
    memset(cl,0,sizeof(cl));

    cl[0][0]=1;
    f[0][0]=0;
    for(int i=1; i<=n; ++i)
    for(int x=0; x<256; ++x)
    {
        f[i][x]=0;
        if(cl[i-1][x]) {
            cl[i][x]=1;
            f[i][x]=f[i-1][x];
        }
        if(x&(1<<(a[i]-1)))
        {
            int y=x^(1<<(a[i]-1));
            int p=sl[a[i]][i]-val+1;
            if(p<0) continue;
            int j=upper_bound(sl[a[i]]+1,sl[a[i]]+n+1,p)-sl[a[i]]-1;
            if(j<i && sl[a[i]][j]==p && cl[j][y])
            {
                cl[i][x]=1;
                f[i][x]=max(f[i][x],f[j][y]+val-1);
            }

            p=sl[a[i]][i]-val;
            if(p<0) continue;
            j=upper_bound(sl[a[i]]+1,sl[a[i]]+n+1,p)-sl[a[i]]-1;
            if(j<i && sl[a[i]][j]==p && cl[j][y])
            {
                cl[i][x]=1;
                f[i][x]=max(f[i][x],f[j][y]+val);
            }
        }
    }

    if(val>1) cout<<f[n][255];
    else
    {
        int ds=0;
        for(int x=0; x<256; ++x)
            ds=max(ds,f[n][x]);
        cout<<ds;
    }
}
int main()
{
    freopen("743e.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>a[i];

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=8; ++j)
            sl[j][i]=sl[j][i-1];
        sl[a[i]][i]++;
    }

    int lo=1,hi=n+1;
    while(hi-lo>1)
    {
        int mid=(lo+hi)/2;
        if(kt(mid)) lo=mid;
        else hi=mid;
    }
    tinh(lo);
}
