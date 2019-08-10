#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int a[3*maxn],n,bit[205][maxn];
int pos[3*maxn],head[205],m;
void update(int m,int u,int val)
{
        while(u)
        {
                bit[m][u]+=val;
                u-=u&(-u);
        }
}
int get(int m,int u)
{
        int kq=0;
        while(u<=maxn)
        {
                kq+=bit[m][u];
                u+=u&(-u);
        }
        return kq;
}
int main()
{
        freopen("KQUERY2.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; ++i)
                cin>>a[i];
        m=sqrt(n);
        int cnt=0;
        int now=1;
        for (int i=1; i<=n; ++i)
        {
                ++cnt;
                if (cnt>m)
                {
                        cnt%=m;
                        ++now;
                }
                if (!head[now]) head[now]=i;
                pos[i]=now;
                update(now,a[i],1);
        }
        head[now+1]=n+1;
        int test;
        cin>>test;
        while(test--)
        {
                int x,u,v,i,c;
                cin>>x;
                if (x==0)
                {
                        cin>>i>>c;
                        update(pos[i],a[i],-1);
                        update(pos[i],c,1);
                        a[i]=c;
                        continue;
                }
                cin>>u>>v>>c;
                int res=0;
                if (pos[u]==pos[v])
                {
                        for (int i=u;i<=v;++i)
                        if (a[i]>c) ++res;
                        cout<<res<<"\n";
                        continue;
                }
                for (int i=pos[u]+1; i<=pos[v]-1; ++i)
                        res+=get(i,c+1);
                for (int i=u; i<head[pos[u]+1]; ++i)
                        if (a[i]>c) ++res;
                for (int i=head[pos[v]]; i<=v; ++i)
                        if (a[i]>c) ++res;
                cout<<res<<"\n";
        }
}
