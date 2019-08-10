#include<bits/stdc++.h>
#define maxn 1<<20
#define ll long long
using namespace std;
int n;
ll t,res;
int dd[maxn],cnt,mask,d;
vector<int > E[30];
struct data
{
    int v;
    ll c;
};
vector<data > e[maxn],C;
ll change(int &MASK,int mask)
{
    ll res=0;
    for (int i=1; i<=n; ++i)
    {
        for (int j=0; j<E[i].size(); ++j)
        {
            int x=E[i][j];
            if ((mask>>(i-1))&1)
            {
                ++res;
                MASK^=1<<(x-1);
            }
            else res+=2;
        }
    }
    return res;
}
int main()
{
    freopen("FAFLOWER.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>t;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            char c;
            cin>>c;
            if (c=='1') E[i].push_back(j);
        }
    if (t==0)
    {
        cout<<0;
        return 0;
    }
    for (int i=0; i<E[1].size(); ++i)
    {
        int x=E[1][i];
        mask^=1<<(x-1);
        res++;
    }
    t--;
    dd[mask]=++cnt;
    ll SUM=0;
    while(1)
    {
        int MASK=mask;
        ll tmp=change(MASK,mask);
        SUM+=tmp;
        ++d;
        if (t==d)
        {
            cout<<res+SUM;
            return 0;
        }
        if (!dd[MASK])
        {
            dd[MASK]=++cnt;
            e[dd[mask]].push_back({dd[MASK],tmp});
        }
        else
        {
            int dem=0;
            int u=1;
            while(u!=dd[MASK])
            {
                int v=e[u][0].v;
                ll cost=e[u][0].c;
                res+=cost;
                u=v;
            }
            ll sum=0;
            if (e[u].size())
                while(dem!=2)
                {
                    if (dd[MASK]==u) ++dem;
                    int v=e[u][0].v;
                    ll cost=e[u][0].c;
                    if (dem==2) sum+=tmp;
                    else sum+=cost;
                    C.push_back({v,sum});
                }
            else
            {
                C.push_back({u,tmp});
            }
            break;
        }
        mask=MASK;
    }
    res+=1ll*C.back().c*(t/C.size());
    t%=C.size();
    int now=0;
    if (t)
    {
        while(t--) ++now;
        res+=C[now].c;
    }
    cout<<res;
    return 0;
}
