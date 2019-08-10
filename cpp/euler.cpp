#include <bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
typedef pair<int, int> II;
    int n,m,deg[2005],dd[10005],x[10005],slx=0;
    II edge[10005];
    vector<int> g[2005];
    int cur[2005], s[2005];
void euler()
{
    for(int i=1; i<=n; i++) cur[i]=0;
    int sn=0;
    s[++sn]=edge[1].fs;
    while(sn)
    {
        int u=s[sn];
        while(cur[u]<deg[u]&&dd[g[u][cur[u]]]) cur[u]++;
        if(cur[u]==deg[u]){x[++slx]=u; sn--;}
        else{
            int id=g[u][cur[u]];
            dd[id]=1;
            int v;
            if(u==edge[id].fs) v=edge[id].sc;
                else v=edge[id].fs;
            s[++sn]=v;
        }
    }
}
int main()
{
    freopen("euler.inp","r",stdin);
    //freopen("postman.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int u,v;
        cin>>u>>v;
        edge[i]=II(u,v);
        g[u].push_back(i);deg[u]++;
        g[v].push_back(i);deg[v]++;
        dd[m]=0;
    }
    euler();
    //cout<<slx-1<<"\n";
    for(int i=2; i<=slx; i++)
        cout<<x[i-1]<<" "<<x[i]<<"\n";
    return 0;
}

