#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
char s[maxn][maxn];
int n,m;
int main()
{
            //freopen("837B.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>m;
            for (int i=1; i<=n; ++i)
                        for (int j=1; j<=m; ++j)
                                    cin>>s[i][j];
            if (m%3==0)
            {
                        int ok=1;
                        for (int k=1; k<=3; ++k)
                                    for (int i=1; i<=n; ++i)
                                    {
                                                if (!ok) break;
                                                for (int j=(m/3)*(k-1)+1; j<=(m/3)*k; ++j)
                                                            if (s[i][j]!=s[1][(m/3)*k])
                                                            {
                                                                        ok=0;
                                                                        break;
                                                            }
                                    }
                        if (ok)
                        {
                                    cout<<"YES";
                                    return 0;
                        }
            }
            if (n%3==0)
            {
                        int ok=1;
                        for (int k=1; k<=3; ++k)
                                    for (int i=1; i<=m; ++i)
                                    {
                                                if (!ok) break;
                                                for (int j=(n/3)*(k-1)+1; j<=(n/3)*k; ++j)
                                                            if (s[j][i]!=s[(n/3)*k][1])
                                                            {
                                                                        ok=0;
                                                                        break;
                                                            }
                                    }
                        if (ok)
                        {
                                    cout<<"YES";
                                    return 0;
                        }
            }
            cout<<"NO";
            return 0;
}
