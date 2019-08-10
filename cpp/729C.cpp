#include<bits/stdc++.h>
#define maxn 200005
#define db double
#define fs first
#define sc second
using namespace std;
int n,k,s,ans,d[maxn];
typedef pair<int,int> II;
II a[maxn];
int t;
bool  cmp(II a,II b)
{
        if (a.fs!=b.fs)return a.fs<b.fs;
        return a.sc>b.sc;
}
bool check(int m)
{
        int res=0;
        for (int i=1;i<=k;++i)
        {
                int dis=d[i]-d[i-1];
                if (2*dis<=m)
                {
                        res+=dis;
                        continue;
                }
                int y=m-dis;
                if (y<0) return 0;
                int x=dis-y;
                res+=x*2+y;
        }
        if (res<=t) return 1;
        else return 0;
}
int main()
{
        //freopen("729C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k>>s>>t;
        for (int i=1;i<=n;++i)
                cin>>a[i].fs>>a[i].sc;
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=k;++i)
                cin>>d[i];
        d[++k]=s;
        sort(d+1,d+k+1);
        int l=1,r=1e9;
        ans=1e9+7;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (check(m))
                {
                        ans=m;
                        r=m-1;
                }
                else l=m+1;
        }
        for (int i=1;i<=n;++i)
        if (a[i].sc>=ans)
        {
                cout<<a[i].fs;
                return 0;
        }
        cout<<-1;
        return 0;
}
