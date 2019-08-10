#include<bits/stdc++.h>
#define maxn 1000005
#define mod 1000000007
#define ll long long
using namespace std;
int n,a[maxn],f[maxn],res,dd[maxn],c,d[maxn],ftrc[maxn];
int ucln(int a,int b)
{
        return __gcd(a,b);
}
vector<int> e,ngto;
int tinh(int k)
{
        int kq=0;
        for (int i=0;i<(int)ngto.size();i++)
        {
                int x=ngto[i];
                if (k%x==0)
                {
                        kq++;
                        while(k%x==0) k/=x;
                }
                if (dd[k]==0&&k!=1) return kq+1;
                if (k==1) return kq;
        }
        return kq;
}
int power(int a,int n)
{
        if (n==0) return 1;
        if (n==1) return a;
        int tmp=power(a,n>>1);
        tmp=((ll)tmp*tmp)%mod;
        if (n&1) tmp=((ll)tmp*a)%mod;
        return tmp;
}
int main()
{
        freopen("D:\\c++\\debug\\VO17xxx.inp","r",stdin);
        freopen("D:\\c++\\debug\\VO17xxx.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>c;
        for (int i=1;i<=n;i++)
        {
                cin>>a[i];
        }
        for (int i=2;i*i<=maxn-1;i++)
        if (dd[i]==0)
        {
                for (int j=i*i;j<=maxn-1;j+=i)
                {
                        dd[j]=1;
                }
        }
        for (int i=2;i<=maxn-1;i++)
                if (dd[i]==0)
        {
                ngto.push_back(i);
        }
        for (int i=1;i<=n;i++)
        {
                int xk=e.size();
                for (int j=0;j<xk;j++)
                {
                        int k=e[j];
                        ftrc[k]=f[k];
                }
                for (int j=0;j<xk;j++)
                {
                        int k=e[j];
                        int tmp=ucln(k,a[i]);
                        if (d[tmp]==0)
                        {
                                d[tmp]=1;
                                e.push_back(tmp);
                        }
                        f[tmp]=(f[tmp]+ftrc[k])%mod;
                }
                if (d[a[i]]==0)
                {
                        d[a[i]]=1;
                        e.push_back(a[i]);
                }
                f[a[i]]=(f[a[i]]+1)%mod;
        }
        for (int i=0;i<(int)e.size();i++)
        {
                int k=e[i];
                if (f[k]==0) continue;
                int tmp=power(c,tinh(k));
                res=(res+((ll)tmp*f[k])%mod)%mod;
        }
        cout<<res;
        return 0;
}
