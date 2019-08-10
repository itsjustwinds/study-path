#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
#define mod 1000000007
using namespace std;
struct data
{
        int b[3];
};
data base,hS[maxn],hT[maxn],power[maxn];
int n,m,s[maxn],t[maxn];
data getS(int l,int r)
{
        data c;
        for (int i=1; i<=2; i++)
        {
                c.b[i]=(hS[r].b[i]-((ll)hS[l-1].b[i]*power[r-l+1].b[i])%mod+mod)%mod;
        }
        return c;
}
data getT(int l,int r)
{
        data c;
        for (int i=1; i<=2; i++)
        {
                c.b[i]=(hT[r].b[i]-((ll)hT[l-1].b[i]*power[r-l+1].b[i])%mod+mod)%mod;
        }
        return c;
}
bool operator ==(data a,data b)
{
        for (int i=1; i<=2; i++)
        {
                if (a.b[i]!=b.b[i]) return 0;
        }
        return 1;
}
int check(int i,int j,int len)
{
        return getS(i,i+len-1)==getT(j,j+len-1);
}
int findd(int i,int j,int l,int r)
{
        int kq=0;
        while(l<=r)
        {
                int mid=(l+r)>>1;
                if (!check(i,j,mid))
                {
                        r=mid-1;
                        kq=mid;
                }
                else l=mid+1;
        }
        return kq;
}
int main()
{
        freopen("V11STR.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>m>>n;
        for (int i=1; i<=m; i++)
                cin>>t[i];
        for (int i=1; i<=n; i++)
                cin>>s[i];
        if (m>n)
        {
                cout<<-1;
                return 0;
        }
        base.b[1]=107;
        base.b[2]=83;
        power[0].b[1]=1;
        power[0].b[2]=1;
        for (int i=1; i<=n; i++)
        {
                for (int j=1; j<=2; j++)
                {
                        power[i].b[j]=((ll)power[i-1].b[j]*base.b[j])%mod;
                }
        }
        for (int i=1; i<=m; i++)
        {
                for (int j=1; j<=2; j++)
                {
                        hT[i].b[j]=(((ll)hT[i-1].b[j]*base.b[j])%mod+t[i])%mod;
                }
        }
        for (int i=1; i<=n; i++)
        {
                for (int j=1; j<=2; j++)
                {
                        hS[i].b[j]=(((ll)hS[i-1].b[j]*base.b[j])%mod+s[i])%mod;
                }
        }
        for (int i=1; i<=n-m+1; i++)
        {
                int tmp1=findd(i,1,1,m);
                if (tmp1==0)
                {
                        cout<<i;
                        return 0;
                }
                int tmp2=findd(i+tmp1,tmp1+1,1,m-tmp1);
                if (tmp2==0)
                {
                        cout<<i;
                        return 0;
                }
        }
        cout<<-1;
        return 0;
}
