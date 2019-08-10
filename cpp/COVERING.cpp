#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct data
{
        int x,id,c;
};
data a[2*maxn];
int n,dd[maxn],res;
vector<int > e;
bool cmp(data a,data b)
{
        if (a.x!=b.x) return a.x<b.x;
        return a.c<b.c;
}
int main()
{
        freopen("COVERING.inp","r",stdin);
        //freopen("COVERING.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                int x,y;
                cin>>x>>y;
                a[i]={x,i,0};
                a[i+n]={y,i,1};
        }
        sort(a+1,a+2*n+1,cmp);
        for (int i=1;i<=2*n;++i)
        {
                if (a[i].c==0) e.push_back(a[i].id);
                if (a[i].c==1&&dd[a[i].id]==0)
                {
                        for (int i=0;i<e.size();++i)
                        {
                                int u=e[i];
                                dd[u]=1;
                        }
                        ++res;
                        e.clear();
                }
        }
        cout<<res;
        return 0;
}
