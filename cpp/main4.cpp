#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int f[maxn],a[maxn],b[maxn],n,m,trc[maxn];
vector<int > ans;
int main()
{
        freopen("main4.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<=m;++i)
                cin>>b[i];
        for (int i=1;i<=n;++i)
        {
                int tmp=0;
                for (int j=1;j<=m;++j)
                {
                        if (a[i]==b[j])
                        {
                                if (f[tmp]+1>f[j])
                                {
                                        f[j]=f[tmp]+1;
                                        trc[j]=tmp;
                                }
                        }
                        if (a[i]<b[j])
                        {
                                if (f[j]>f[tmp])
                                {
                                        tmp=j;
                                }
                        }
                }
        }
        int res=0;
        int now=0;
        for (int i=1;i<=m;++i)
        if (res<f[i])
        {
                res=f[i];
                now=i;
        }
        cout<<res<<"\n";
        for (int i=1;i<=res;++i)
        //while(now)
        {
                ans.push_back(b[now]);
                now=trc[now];
        }
        for (int i=ans.size()-1;i>=0;--i)
                cout<<ans[i]<<" ";
        return 0;
}
