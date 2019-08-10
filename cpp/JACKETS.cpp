#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct data
{
        int x,type,id;
};
vector<data > events;
set<int > s;
set<int > ::iterator it;
vector<int >f[maxn],g[maxn];
int res[maxn];
bool cmp(data a,data b)
{
        if (a.x!=b.x) return a.x<b.x;
        return a.type<b.type;
}
int n,m;
int main()
{
        freopen("JACKETS.inp","r",stdin);
        //freopen("JACKETS.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                events.push_back({x,0,i});
        }
        for(int i=1;i<=m;++i)
        {
                int x,y;
                cin>>x>>y;
                events.push_back({x,-1,i});
                events.push_back({y,1,i});
        }
        sort(events.begin(),events.end(),cmp);
        for (int i=0;i<events.size();++i)
        {
                data now=events[i];
                if (now.type==-1)
                {
                        s.insert(now.id);
                        continue;
                }
                if (now.type==1)
                {
                        s.erase(now.id);
                        continue;
                }
                int cnt=0;
                for (int it: s )
                {
                        g[now.id].push_back(it);
                        f[now.id].push_back(-1);
                        ++cnt;
                        if (cnt==3) break;
                }
        }
        for (int i=0;i<f[1].size();++i)
                f[1][i]=i;
        for (int i=2;i<=n;++i)
        {
                for (int j=0;j<f[i].size();++j)
                {
                        int x=g[i][j];
                        for (int k=0;k<f[i-1].size();++k)
                        {
                                int y=g[i-1][k];
                                if (f[i-1][k]==-1) continue;
                                if (x==y) continue;
                                f[i][j]=k;
                        }
                }
        }
        for (int i=0;i<f[n].size();++i)
        {
                if (f[n][i]!=-1)
                {
                        int now=i;
                        for (int j=n;j>=1;--j)
                        {
                                res[j]=g[j][now];
                                now=f[j][now];
                        }
                        cout<<"Yes\n";
                        for (int i=1;i<=n;++i)
                                cout<<res[i]<<" ";
                        return 0;
                }
        }
        cout<<"No";
}
