#include<bits/stdc++.h>
#define maxn 7005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
queue<II > q;                            // 0 means loop, 1 means lose, 2 means win
int n,s[3][maxn],f[3][maxn],k[3],dd[3][maxn];
int main()
{
    freopen("787c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=2; i++)
    {
        cin >> k[i];
        for(int j=1; j<=k[i]; j++) cin >> s[i][j];
    }
    memset(f,0,sizeof f);
    q.push(II(1,0));
    q.push(II(2,0));
    f[1][0]=1;
    f[2][0]=1;
    while (!q.empty())
    {
        int t = q.front().fs;
        int u = q.front().sc;
        q.pop();
        if (f[t][u] == 1)
        {
            for(int i=1; i<=k[3-t]; i++)
            {
                int v=(u+n-s[3-t][i])%n;
                if (f[3-t][v] > 0) continue;
                f[3-t][v] = 2;
                q.push(II(3-t,v));
            }
        }
        else
        {
            for(int i=1; i<=k[3-t]; i++)
            {
                int v=(u+n-s[3-t][i])%n;
                if (f[3-t][v] > 0) continue;
                ++dd[3-t][v];
                if (dd[3-t][v] == k[3-t])
                {
                    f[3-t][v] = 1;
                    q.push(II(3-t,v));
                }
            }
        }
    }
    for (int i=1; i<=2; i++)
    {
        for (int j=1; j<=n-1; j++)
        {
            if (f[i][j]<1) cout<<"Loop ";
            if (f[i][j]==1) cout<<"Lose ";
            if (f[i][j]>1) cout<<"Win ";
        }
        cout<<"\n";
    }
    return 0;
}
