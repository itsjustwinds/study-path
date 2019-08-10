#include<bits/stdc++.h>
#define maxn 55
#define ll long long
#define mod 1000000006
using namespace std;
struct data
{
        int h[maxn];
};
struct matrix_Data
{
        int n,m;
        data h[maxn][maxn];
};
struct matrix_Int
{
        int n,m;
        int h[maxn][maxn];
};
matrix_Data M;
data ZERO;
matrix_Int base;
int n,k,a[maxn];
int po(int a,int n)
{
        if (n==0) return 1;
        stack<int >e;
        while(!e.empty()) e.pop();
        while(n!=1)
        {
                e.push(n%2);
                n/=2;
        }
        int res=a;
        while(!e.empty())
        {
                res=(1ll*res*res)%(mod+1);
                if (e.top()==1) res=(1ll*res*a)%(mod+1);
                e.pop();
        }
        return res;
}
int tinh(const data &b)
{
        int res=1;
        for (int i=1; i<=k; ++i)
        {
                res=(1ll*res*po(a[i],b.h[i]))%(mod+1);
        }
        return res;
}
matrix_Int operator *(matrix_Int a,matrix_Int b)
{
        matrix_Int c;
        c.n=a.n;
        c.m=b.m;
        for (int i=1; i<=c.n; ++i)
                for (int j=1; j<=c.m; ++j)
                {
                        c.h[i][j]=0;
                        for (int h=1; h<=a.m; ++h)
                                c.h[i][j]=(c.h[i][j]+(1ll*a.h[i][h]*b.h[h][j])%mod)%mod;
                }
        return c;
}
matrix_Int power(int n)
{
        stack<int >e;
        while(!e.empty()) e.pop();
        while(n!=1)
        {
                e.push(n%2);
                n/=2;
        }
        matrix_Int ans=base;
        while(!e.empty())
        {
                ans=ans*ans;
                int x=e.top();
                e.pop();
                if (x) ans=ans*base;
        }
        return ans;
}
data operator *(int n,data a)
{
        data c;
        for (int i=1; i<=k; ++i)
        {
                c.h[i]=(1ll*a.h[i]*n)%mod;
        }
        return c;
}
data operator +(data a,data b)
{
        data c;
        for (int i=1; i<=k; ++i)
                c.h[i]=(a.h[i]+b.h[i])%mod;
        return c;
}
matrix_Data operator*(matrix_Int a,matrix_Data b)
{
        matrix_Data c;
        c.n=a.n;
        c.m=b.m;
        for (int i=1; i<=c.n; ++i)
                for (int j=1; j<=c.m; ++j)
                {
                        c.h[i][j]=ZERO;
                        for (int h=1; h<=a.m; ++h)
                                c.h[i][j]=c.h[i][j]+a.h[i][h]*b.h[h][j];
                }
        return c;
}
int main()
{
        freopen("VMYT.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1; i<=k; ++i)
                cin>>a[i];
        base.n=k+1;
        base.m=k+1;
        for (int i=1; i<=k; ++i)
                base.h[i][i+1]=1;
        for (int i=2; i<=k+1; ++i)
                base.h[k+1][i]=1;
        M.n=k+1;
        M.m=1;
        for (int i=1; i<=k; ++i)
                M.h[i][1].h[i]=1;
        for (int i=1; i<=k; ++i)
                M.h[k+1][1].h[i]=1;
        if (n<=k+1)
        {
                cout<<tinh(M.h[n][1]);
                return 0;
        }
        matrix_Int S=power(n-k-1);
        matrix_Data res=S*M;
        cout<<tinh(res.h[k+1][1]);
        return 0;
}
