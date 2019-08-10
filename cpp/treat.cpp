#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int num[maxn],low[maxn],n,cnt,res[maxn];
vector <int> e[maxn];
vector<int> re;
stack<int> s;
void visit(int u)
{
    cnt++;
    num[u]=low[u]=cnt;
    s.push(u);
    for (int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if (num[v]>0)
        {
            low[u]=min(low[u],num[v]);
        }
        else
        {
            visit(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if (num[u]==low[u])
    {
        int v,dem=0;
        re.clear();
        while(v!=u)
        {
            v=s.top();
            s.pop();
            dem++;
            num[v]=low[v]=100000005;
            re.push_back(v);
        }
        for (int i=0;i<(int)re.size();i++)
        {
            res[re[i]]=dem;
        }
    }
}
int get(int u)
{
    if (res[u]==0)
        res[u]=get(e[u][0])+1;
    return res[u];
}
int main()
{
    freopen("treat.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        e[i].push_back(x);
    }
    for (int i=1;i<=n;i++)
        if (num[i]==0)
        visit(i);
    for (int i=1;i<=n;i++)
        if (res[i]==1&&i!=e[i][0])
        res[i]=0;
    for (int i=1;i<=n;i++)
        if (res[i]==0)
        res[i]=get(i);
    for (int i=1;i<=n;i++)
        cout<<res[i]<<"\n";
    return 0;
}
