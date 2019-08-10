#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
struct data
{
        int x,e,id;
};
data a[maxn],f[maxn];
int n,t[maxn],res[maxn];
stack<data > s;
bool cmp(data a,data b)
{
        return a.x<b.x;
}
int main()
{
        freopen("COLLIDER.inp","r",stdin);
        //freopen("COLLIDER.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                t[i]=1e9+7;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].x>>a[i].e;
                if (a[i].e==1)
                {
                        s.push({a[i].x,1,i});
                }
                else
                {
                        if (!s.empty())
                        {
                                data x=s.top();
                                s.pop();
                                int id=x.id;
                                int val=x.x;
                                t[id]=(a[i].x-val+1)/2;
                                t[i]=(a[i].x-val+1)/2;
                        }
                }
        }
        sort(t+1,t+n+1);
        int test;
        cin>>test;
        for (int i=1;i<=test;++i)
        {
                cin>>f[i].x;
                f[i].id=i;
        }
        sort(f+1,f+test+1,cmp);
        int now=0;
        for (int i=1;i<=test;++i)
        {
                while(now+1<=n&&t[now+1]<=f[i].x)++now;
                res[f[i].id]=n-now;
        }
        for (int i=1;i<=test;++i)
                cout<<res[i]<<"\n";
}
