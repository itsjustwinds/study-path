#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
struct data
{
        int vex,ed;
};
data d[maxn];
int n,dd[maxn],root[maxn],sum;
long long res;
vector<int > les,ok;
int get(int u)
{
        if (root[u]==u) return u;
        root[u]=get(root[u]);
        return root[u];
}
int main()
{
        freopen("VOROOM.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        ++n;
        for (int i=1;i<=n;++i)
        {
                root[i]=i;
                d[i].vex=1;
        }
        for (int i=1;i<n;++i)
        {
                int u,v;
                cin>>u>>v;
                int ru=get(u);
                int rv=get(v);
                if (ru==rv)
                {
                        d[ru].ed++;
                        continue;
                }
                root[ru]=rv;
                d[rv].vex+=d[ru].vex;
                d[rv].ed+=d[ru].ed+1;
        }
        for (int i=1;i<=n;++i)
        {
                int r=get(i);
                if (dd[r]) continue;
                dd[r]=1;
                if (d[r].vex<d[r].ed)
                {
                        cout<<0;
                        return 0;
                }
                if (d[r].vex==d[r].ed)
                {
                        ok.push_back(r);
                }
                else les.push_back(r);
        }
        for (int i=0;i<les.size();++i)
        {
                int r=les[i];
                res+=1ll*(d[r].vex)*(d[r].vex-1)/2;//their own
                res+=1ll*(d[r].vex)*sum;//les to les
                sum+=d[r].vex;
        }
        for (int i=0;i<ok.size();++i)
        {
                int r=ok[i];
                res+=1ll*sum*d[r].vex;//ok to les
        }
        cout<<res;
        return 0;

}
