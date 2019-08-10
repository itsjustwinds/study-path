#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int a[maxn],basea[maxn],b[maxn],n,M,res,x[maxn];
void check(int S1,int S2)
{
        for (int i=1;i<=2*n;++i)
                a[i]=basea[i];
        int d=0;
        for (int i=1;i<=n-M+1;++i)
        {
                if (a[S1+i-1]!=b[S2+i-1])
                {
                        ++d;
                        for (int j=1;j<=M;++j)
                                a[S1+i-1+j-1]=1-a[S1+i-1+j-1];
                }
        }
        for (int i=n-M+2;i<=n;++i)
                if (a[S1+i-1]!=b[S2+i-1]) return;
        res=min(res,d);
}
int main()
{
        freopen("LATCO.inp","r",stdin);
        freopen("LATCO.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>M;
        res=1e9;
        for (int i=1;i<=n;++i)
        {
                char x;
                cin>>x;
                basea[i]=x-'0';
                basea[i+n]=basea[i];
        }
        for (int i=1;i<=n;++i)
        {
                char x;
                cin>>x;
                b[i]=x-'0';
                b[i+n]=b[i];
        }
        res=1e9;
        for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                check(i,j);
        cout<<res;
}
