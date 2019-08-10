#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,l[maxn],r[maxn],a[maxn],res,k,p[maxn][35];
int get(int l,int r)
{
        int log=log2(r-l+1);
        int tmp=max(p[l][log],p[r-(1<<log)+1][log]);
        return tmp;
}
int main()
{
        freopen("minimize.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        res=1111111111;
        for (int i=1; i<=n; i++)
                cin>>a[i];
        for (int i=1; i<=n; i++)
                for (int j=1; j<=34; j++)
                        p[i][j]=1111111111;
        a[0]=a[1];
        a[n+1]=a[n];
        for (int i=1; i<=n; i++)
                a[i]=a[i+1]-a[i];
        for (int i=1; i<=n; i++)
                p[i][0]=a[i];
        for (int j=1; (1<<j)<=n; j++)
        {
                for (int i=1; i+(1<<j)-1<=n; i++)
                {
                        p[i][j]=max(p[i][j-1],p[i+(1<<(j-1))][j-1]);
                }
        }
        for (int i=0; i<=k; i++)
        {
                res=min(res,get(i+1,n-k+i-1));
        }
        cout<<res;
        return 0;
}
