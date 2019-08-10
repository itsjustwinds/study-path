#include<bits/stdc++.h>
#define maxn 10005
#define ll long long
using namespace std;
struct data
{
            int u,v;
            ll w;
};
data c[3000005],a[maxn];
int n,root[maxn],dem;
ll res;
bool cmp(data a,data b)
{
            return a.w>b.w;
}
int get(int u)
{
            if (root[u]==u) return u;
            root[u]=get(root[u]);
            return root[u];
}
int main()
{
            freopen("TRAVELAL.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int test;
            cin>>test;
            while(test--)
            {
                        cin>>n;
                        for (int i=1; i<=n; ++i)
                                    cin>>a[i].u>>a[i].v;
                        for (int i=1; i<=n; ++i)
                                    for (int j=1; j<=n; ++j)
                                    {
                                                if (i==j) continue;
                                                ++dem;
                                                c[dem].u=i;
                                                c[dem].v=j;
                                                c[dem].w=abs(a[i].u-a[j].u)+abs(a[i].v-a[j].v);
                                    }
                        sort(c+1,c+dem+1,cmp);
                        for (int i=1; i<=n; ++i)
                                    root[i]=i;
                        int d=0;
                        for (int i=1; i<=dem; ++i)
                        {
                                    int u=c[i].u;
                                    int v=c[i].v;
                                    int ru=get(u);
                                    int rv=get(v);
                                    if (ru==rv) continue;
                                    root[ru]=rv;
                                    ++d;
                                    res=c[i].w;
                                    if (d==n-1) break;
                        }
                        cout<<res<<"\n";
            }
            return 0;
}
