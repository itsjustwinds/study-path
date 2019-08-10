#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int l[maxn],r[maxn],a[maxn],n,ddl[maxn],ddr[maxn];
double res,dem;
int main()
{
    freopen("817b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=3; i<=n; i++)
        ddr[a[i]]++;
    l[1]=a[1];
    for (int i=2; i<=n; i++)
        l[i]=min(l[i-1],a[i]);
    r[n]=a[n];
    for (int i=n-1; i>=1; i--)
        r[i]=min(r[i+1],a[i]);
    ddl[a[1]]++;
    for (int i=2; i<=2; i++)
    {
        double tmp=l[i-1]*a[i]*r[i+1];
        res=tmp;
        dem=(double)ddl[l[i-1]]*ddr[r[i+1]];
        ddl[a[i]]++;
        ddr[a[i+1]]--;
    }

    for (int i=3; i<n; i++)
    {
        double tmp=l[i-1]*a[i]*r[i+1];
        if (tmp<res)
        {
            res=tmp;
            dem=(double)ddl[l[i-1]]*ddr[r[i+1]];
        }
        else if (tmp==res) dem+=(double)ddl[l[i-1]]*ddr[r[i+1]];
        ddl[a[i]]++;
        ddr[a[i+1]]--;
    }
    cout<<dem;
    return 0;
}
