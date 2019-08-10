#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct II
{
        int fs,sc,pos;
};
II a[3*maxn];
int n,bit[maxn],ans[3*maxn];
bool cmp(II a,II b )
{
        if (a.fs!=b.fs) return a.fs<b.fs;
        return a.sc<b.sc;
}
bool operator ==(II a,II b)
{
        return a.fs==b.fs&&a.sc==b.sc;
}
void update(int u)
{
        while(u<=maxn)
        {
                bit[u]++;
                u+=u&(-u);
        }
}
int get(int u)
{
        int res=0;
        while(u)
        {
                res+=bit[u];
                u-=u&(-u);
        }
        return res;
}
int main()
{
        freopen("CRATE.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].fs>>a[i].sc;
                a[i].pos=i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                int res=0;
                res=get(a[i].sc);
                update(a[i].sc);
                for (int j=i-1;j>=1;--j)
                if (a[i]==a[j]) --res;
                else break;
                ans[a[i].pos]=res;
        }
        for (int i=1;i<=n;++i)
                cout<<ans[i]<<"\n";
}
