#include<bits/stdc++.h>
#define maxn 2005
#define fs first
#define sc second
#define ll long long
using namespace std;
ll res;
int a[maxn][maxn],n,m,dx[5],dy[5],C[maxn][maxn],ok,TMP[maxn][maxn];
typedef pair<int,int > II;
vector<II > T;
void dm()
{
        if (n==1)
        {
                for (int j=1; j<=m; ++j)
                        if (a[n][j]==0) a[n][j]=a[n][j-1]+1;
                        else if (a[n][j]<=a[n][j-1])
                        {
                                cout<<-1;
                                return;
                        }
                ll ans=0;
                for (int j=1; j<=m; ++j)
                        ans+=a[n][j];
                cout<<ans;
                return ;
        }
        for (int i=1; i<=n; ++i)
                if (a[i][m]==0) a[i][m]=a[i-1][m]+1;
                else if (a[i][m]<=a[i-1][m])
                {
                        cout<<-1;
                        return;
                }
        ll ans=0;
        for(int i=1; i<=n; ++i)
                ans+=a[i][m];
        cout<<ans;
}
void zero()
{
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        if (a[i][j]==0)
                        {
                                int tmp=max(a[i-1][j],a[i][j-1])+1;
                                int T[5];
                                int d=0;
                                for (int k=1; k<=4; ++k)
                                {
                                        int X=i+dx[k];
                                        int Y=j+dy[k];
                                        if (a[X][Y]==0) continue;
                                        T[++d]=a[X][Y]%2;
                                }
                                sort(T+1,T+d+1);
                                if (d>0&&T[1]!=T[d])
                                {
                                        cout<<-1;
                                        return;
                                }
                                if (tmp%2==T[1]) ++tmp;
                                a[i][j]=tmp;
                        }
                        else
                        {
                                if (a[i][j]<=a[i-1][j]||a[i][j]<=a[i][j-1])
                                {
                                        cout<<-1;
                                        return;
                                }
                        }
        ll ans=0;
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        ans+=a[i][j];
        cout<<ans;
}
void reset()
{
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        a[i][j]=TMP[i][j];
}
void solve()
{
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                {
                        int tmp=max(a[i-1][j],a[i][j-1])+1;
                        if (tmp%2!=C[i][j]) ++tmp;
                        if (a[i][j]!=0&&a[i][j]<tmp)
                        {
                                return;
                        }
                        if (!a[i][j])a[i][j]=tmp;
                }
        ll ans=0;
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        ans+=a[i][j];
        res=min(res,ans);
        /*if (ans==104)
        {
        for (int i=1;i<=n;++i)
        {
                for (int j=1;j<=m;++j)
                        cout<<a[i][j]<<" ";
                        cout<<"\n";
        }
        }*/
}
void dfs(int i,int j,int x)
{
        if (!ok) return;
        if (i<1||i>n||j<1||j>m) return;
        if(C[i][j]!=-1) return;
        if (a[i][j]!=0&&a[i][j]%2!=x)
        {
                ok=0;
                return;
        }
        C[i][j]=x;
        for (int k=1; k<=4; ++k)
        {
                dfs(i+dx[k],j+dy[k],1-x);
        }
}
int main()
{
        freopen("BGMAGIC.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        memset(C,-1,sizeof C);
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                {
                        cin>>a[i][j];
                        TMP[i][j]=a[i][j];
                        //C[i][j]=-1;
                        if (a[i][j]!=0)
                        {
                                T.push_back(II(i,j));
                        }
                }
        dx[1]=-1,dy[1]=-1;
        dx[2]=-1,dy[2]=1;
        dx[3]=1,dy[3]=1;
        res=1e18;
        dx[4]=1,dy[4]=-1;
        ok=1;
        if (T.size()==0)
        {
                zero();
                return 0;
        }
        for (int i=0; i<T.size(); ++i)
                dfs(T[i].fs,T[i].sc,a[T[i].fs][T[i].sc]%2);
        if (!ok)
        {
                cout<<-1;
                return 0;
        }
        if (n==1||m==1)
        {
                dm();
                return 0;
        }
        if ((C[1][1]==-1||C[1][2]==-1))
        {
                if (C[1][1]==-1)
                {
                        dfs(1,1,0);
                        solve();
                        memset(C,-1,sizeof C);
                        reset();
                        dfs(T[0].fs,T[0].sc,a[T[0].fs][T[0].sc]%2);
                        dfs(1,1,1);
                        solve();
                        if (res!=1e18)cout<<res;
                        else cout<<-1;
                        return 0;
                }
                else
                {
                        dfs(2,1,0);
                        solve();
                        memset(C,-1,sizeof C);
                        reset();
                        dfs(T[0].fs,T[0].sc,a[T[0].fs][T[0].sc]%2);
                        dfs(2,1,1);
                        solve();
                        if (res!=1e18)cout<<res;
                        else cout<<-1;
                        return 0;
                }
        }
        solve();
        if (res!=1e18)cout<<res;
        else cout<<-1;
}
