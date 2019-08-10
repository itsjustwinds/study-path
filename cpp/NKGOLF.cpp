#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int a[maxn][maxn],n,m,h[maxn],le[maxn],ri[maxn],b[maxn][maxn];
deque<int > s;
int res;
int main()
{
        freopen("NKGOLF.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        cin>>a[i][j];
        for (int i=1; i<=n; ++i)
        {
                a[i][0]=-1e9-7;
                int d=0;
                for (int j=1; j<=m; ++j)
                {
                        if (a[i][j]>=a[i][j-1])
                        {
                                ++d;
                                res=max(res,d);
                        }
                        else d=1;
                }
        }
        for (int j=1; j<=m; ++j)
        {
                a[0][j]=-1e9-7;
                int d=0;
                for (int i=1; i<=n; ++i)
                {
                        if (a[i][j]>=a[i-1][j])
                        {
                                ++d;
                                res=max(res,d);
                        }
                        else d=1;
                }
        }
        for (int i=1; i<n; ++i)
                for (int j=1; j<m; ++j)
                        b[i][j]=(a[i][j]<=a[i+1][j]&&a[i][j]<=a[i][j+1]&&a[i+1][j]<=a[i+1][j+1]&&a[i][j+1]<=a[i+1][j+1]);
        h[0]=-1;
        h[m]=-1;
        for (int i=1; i<n; ++i)
        {
                for (int j=1; j<m; ++j)
                        h[j]=(h[j]+1)*b[i][j];
                s.clear();
                s.push_back(0);
                for (int j=1; j<m; ++j)
                {
                        while(s.size()>1&&h[s.back()]>=h[j]) s.pop_back();
                        le[j]=s.back()+1;
                        s.push_back(j);
                }
                s.clear();
                s.push_back(m);
                for (int j=m-1; j>=1; --j)
                {
                        while(s.size()>1&&h[s.back()]>=h[j]) s.pop_back();
                        ri[j]=s.back()-1;
                        s.push_back(j);
                }
                for (int j=1; j<m; ++j)
                {
                        if (h[j]==0) continue;
                        res=max(res,(h[j]+1)*(ri[j]-le[j]+2));
                }
        }
        cout<<res;
        return 0;
}
