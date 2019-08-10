#include<bits/stdc++.h>
#define maxn 1005
#define oo 2111111111
using namespace std;
int a[maxn],d,n,f[maxn],res,nw[maxn];
int main()
{
        freopen("VOLIS.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>d;
        for (int i=1; i<=n; i++) cin>>a[i];
        f[0]=-oo;
        nw[0]=-oo;
        for (int i=1; i<=n; i++)
        {
                for (int j=0; j<=res; j++)
                {
                        if (f[j]<=a[i]+d)
                        {
                                int tmp=a[i]-d;
                                if (j!=0)tmp=max(tmp,f[j]);
                                if (j+1<=res)nw[j+1]=min(tmp,f[j+1]);
                                else nw[j+1]=tmp;
                                if (j==res)
                                {
                                        res++;
                                        break;
                                }
                        }
                }
                for (int j=0; j<=res; j++) f[j]=nw[j];
        }
        cout<<res;
        return 0;
}
