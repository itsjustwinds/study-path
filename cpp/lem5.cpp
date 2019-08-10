#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
int n,res;
typedef pair<int,int> II;
II a[maxn];
int f[maxn][105];
map<int,int > bg,ed;
map<int,int> :: iterator it;
bool cmp (const II &a,const II &b)
{
        if (a.fs!=b.fs) return a.sc<b.sc;
        else return a.fs<b.fs;
}
int main()
{
        freopen("lem5.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; i++)
        {
                cin>>a[i].fs;
                a[i].sc=i;
        }
        sort(a+1,a+n+1);
        for (int i=1; i<=n; i++)
        {
                it=bg.find(a[i].fs);
                if (it==bg.end()) bg[a[i].fs]=i;
                ed[a[i].fs]=i;
        }
        for (int i=1; i<=n; i++)
        {
                for (int j=1; j<=100; j++)
                {
                        int maxx=0;
                        it=bg.find(a[i].fs-j);
                        if (it!=bg.end())
                        {
                                int trc=it->sc;
                                it=ed.find(a[i].fs-j);
                                int sau=it->sc;
                                for (int k=trc; k<=sau; k++)
                                {
                                        if (a[k].sc>a[i].sc) break;
                                        maxx=max(maxx,f[k][j]);
                                }
                        }
                        f[i][j]=maxx+1;
                        res=max(res,maxx+1);
                }
        }
        cout<<res;
        return 0;
}
