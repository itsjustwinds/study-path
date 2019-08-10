#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,b[maxn],c[maxn],xd,xc;
char s[maxn];
int bitc[maxn],bitd[maxn],res;
void updatec(int u,int val)
{
        while(u<maxn)
        {
                bitc[u]=max(bitc[u],val);
                u+=u&(-u);
        }
}
void updated(int u,int val)
{
        while(u<maxn)
        {
                bitd[u]=max(bitd[u],val);
                u+=u&(-u);
        }
}
int getc(int u)
{
        int kq=0;
        while(u)
        {
                kq=max(kq,bitc[u]);
                u-=u&(-u);
        }
        return kq;
}
int getd(int u)
{
        int kq=0;
        while(u)
        {
                kq=max(kq,bitd[u]);
                u-=u&(-u);
        }
        return kq;
}
int main()
{
        freopen("799C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>xc>>xd;
        for (int i=1; i<=n; ++i)
        {
                cin>>b[i]>>c[i]>>s[i];
        }
        for (int i=1; i<=n; ++i)
        {
                int tmp=b[i];
                int tmp1=xc;
                int tmp2=xd;
                if (s[i]=='C') tmp1-=c[i];
                else tmp2-=c[i];
                if (tmp1<0||tmp2<0) continue;
                int tmp3=max(getc(tmp1),getd(tmp2));
                if (s[i]=='C')updatec(c[i],b[i]);
                else updated(c[i],b[i]);
                if (tmp3==0) continue;
                res=max(res,tmp+tmp3);
        }
        cout<<res;
        return 0;
}
