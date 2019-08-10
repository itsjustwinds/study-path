#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
vector<int> w,l;
int a[maxn],n;
int dd[maxn];
int getbit(int n,int k)
{
    return (n>>(k-1))&1;
}
int main()
{
    freopen("ANDO.inp","r",stdin);
    freopen("ANDO.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
    }
    memset(dd,1,sizeof(dd));
    for (int i=32; i>=1; --i)
    {
        l.clear();w.clear();
        for (int j=1;j<=n;j++)
        if (dd[j]&&getbit(a[j],i))
        {
            w.push_back(j);
        }
        else l.push_back(j);
        if ((int)w.size()==2)
        {
            int res=a[w[0]]&a[w[1]];
            cout<<res;
            return 0;
        }
        if ((int)w.size()>2)
        {
            for (int j=0;j<(int)l.size();++j)
            {
                int v=l[j];
                dd[v]=0;
            }
        }
    }
    int res=a[w[0]]&a[w[1]];
    cout<<res;
    return 0;
}
