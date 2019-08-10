#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
int a[maxn],b[maxn],n,m,dem,f[maxn];
typedef pair<int,int> II;
int ac[10000005];
int main()
{
    freopen("D:\\C++\\huy\\LCS2X.inp","r",stdin);
    //freopen("D:\\C++\\huy\\LCS2X.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        for (int i=1; i<=m; i++)
            cin>>b[i];
        dem=0;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
                if (a[i]==b[j])
            {
                for (int k=m;k>=j+1;k--)
                    if (a[i]*2<=b[j])
                {
                    ac[++dem]=j;
                }
            }
        }

    }
    return 0;
}
