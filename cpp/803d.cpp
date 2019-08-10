#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,res,a[maxn],k,m,dd[maxn];
int check(int m)
{
    memset(dd,0,sizeof(dd));
    int cnt=1;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>m) return 0;
        if (a[i]+dd[cnt]<=m)
        {
            dd[cnt]+=a[i];
        }
        else
        {
            dd[++cnt]+=a[i];
        }
    }
    if (cnt<=k) return 1;
    return 0;

}
int main()
{
    freopen("803d.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>k;
    getline(cin,s);
    getline(cin,s);
    n=1;
    m=s.length();
    for (int i=0;i<m;i++)
    if (s[i]!='-'&&s[i]!=' ')
    {
        a[n]++;
    }
    else
    {
        a[n]++;
        n++;
    }
    int l=1,r=1e6;
    while(l<=r)
    {
        int m=(l+r)>>1;
        if (check(m))
        {
            res=m;
            r=m-1;
        }
        else l=m+1;
    }
    cout<<res;
    return 0;
}
