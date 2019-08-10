#include<bits/stdc++.h>
#define maxn 2005
#define ll long long
using namespace std;
int s[maxn][maxn],n,m,x,y,a,b,c,d,h[maxn],le[maxn],ri[maxn];
int dm[maxn];
int dem[maxn],st[maxn][maxn],res;
int main()
{
        freopen("D:\\C++\\debug\\PERREC.inp","r",stdin);
        freopen("D:\\C++\\debug\\PERREC.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>x>>a>>b>>y>>c>>d;
        x%=n;
        y%=n;
        s[x][y]=1;
        for (int i=2; i<=m; i++)
        {
                x=((ll)x*a+b)%n;
                y=((ll)y*c+d)%n;
                s[x][y]=1;
        }
        h[n]=-1000000;
        for (int i=0; i<=n-1; i++)
                for (int j=0; j<=n-1; j++)
                        if (s[i][j]==1)
                        {
                                st[i][++dem[i]]=j;
                        }
        for (int i=0; i<=n-1; i++)
        {
                for (int j=1; j<=n; j++)
                        dm[j]=-1;
                for (int j=0; j<=n-1; j++)
                        if (s[i][j]==1)
                        {
                                h[j]=0;
                        }
                        else h[j]++;
                for (int j=0; j<=n-1; j++)
                {
                        le[j]=j;
                        if (j==0) continue;
                        while(h[j]<=h[le[j]-1])
                        {
                                le[j]=le[le[j]-1];
                                if (le[j]==0) break;
                        }
                }
                for (int j=n-1; j>=0; j--)
                {
                        ri[j]=j;
                        while(h[j]<=h[ri[j]+1]) ri[j]=ri[ri[j]+1];
                }
                for (int j=0; j<=n-1; j++)
                {
                        if (h[j]==0) continue;
                        int d1=le[j];
                        int d2=ri[j];
                        if (d1<=dm[h[j]]) continue;
                        int ok=1;
                        if (i<n-1&&dem[i+1]!=0)
                        {
                                int tmp=lower_bound(st[i+1]+1,st[i+1]+dem[i+1]+1,d1)-st[i+1];
                                if (tmp==dem[i+1]+1) continue;
                                if (st[i+1][tmp]<=d2) ok=0;
                        }
                        if (i==n-1) ok=0;
                        if (ok) continue;
                        res++;
                        dm[h[j]]=d2;
                }
        }
        cout<<res;
        return 0;
}
