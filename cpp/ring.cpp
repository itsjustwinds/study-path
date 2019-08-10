#include<bits/stdc++.h>
#define maxn 1005
#define fs first
#define sc second
#include<fstream>
#define pb push_back
using namespace std;
ifstream fi("ring.inp");
ofstream fo("ring.out");
typedef pair<int,int> II;
II edge[maxn];
int n,cur[maxn],s[1000000],dem,dd[100],res[maxn],dd1[100],dd2[100],dem2;
vector<int> e[maxn];
void euler()
{
    for (int i=1;i<=50;i++) cur[i]=0;
    for (int i=1;i<=n;i++) dd[i]=0;
    int sn=0;
    s[++sn]=edge[1].fs;
    while(sn)
    {
        int u=s[sn];
        while(cur[u]<(int)e[u].size()&&dd[e[u][cur[u]]]) cur[u]++;
        if (cur[u]==(int)e[u].size())
        {
            sn--;
            res[++dem]=u;
        }
        else
        {
            int id=e[u][cur[u]];
            dd[id]=1;
        int v;
        if (u==edge[id].fs) v=edge[id].sc;
        else v=edge[id].fs;
        s[++sn]=v;
        }
    }
}
void dfs(int u)
{
    if (dd2[u]!=0) return;
    dd2[u]=dem2;
    for (int i=0;i<(int)e[u].size();i++)
    {
        II tmp=edge[e[u][i]];
        int v;
        if (u==tmp.fs) v=tmp.sc;
        else v=tmp.fs;
        dfs(v);
    }
}
int main()
{
    //freopen("ring.inp","r",stdin);
    //freopen("ring.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    fi>>test;
    while(test)
    {
        test--;
        fi>>n;
        for (int i=1;i<=50;i++)
            e[i].clear();
        for (int i=1;i<=50;i++)
            dd1[i]=0;
        for (int i=1;i<=n;i++)
        {
            int u,v;
            fi>>u>>v;
            edge[i]=II(u,v);
            dd1[u]=1;dd1[v]=1;
            e[u].pb(i);
            e[v].pb(i);
        }
        for (int i=1;i<=50;i++)
            dd2[i]=0;
        dem2=0;
        for (int i=1;i<=50;i++)
            if (dd1[i]==1&&dd2[i]==0)
        {
            dem2++;
            dfs(i);
        }
        if (dem2!=1)
        {
            fo<<"NO"<<"\n";
            continue;
        }
        int ok=0;
        for (int i=1;i<=n;i++)
            if (dd1[i]==1)
                if ((int)e[i].size()%2==1)
        {
            fo<<"NO"<<"\n";
            ok=1;
            break;
        }
        if (ok==1) continue;
        dem=0;
        euler();
        if (res[1]==res[dem])
        {
            fo<<"YES"<<"\n";
            for (int i=2;i<=dem;i++)
            fo<<res[i-1]<<" "<<res[i]<<"\n";
        }
            else fo<<"NO"<<"\n";
    }
    fi.close();
    return 0;
}
