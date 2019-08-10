#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int a[maxn],n;
int main()
{
            freopen("EraseValue.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n;
            int res=1000000005;
            for (int i=1;i<=n;++i)
                        cin>>a[i];
            for (int i=1;i<=n;++i)
            {
                        int sum=0;
                        int x=a[i];
                        for (int j=1;j<=n;++j)
                        {
                                    if (a[j]==x) continue;
                                    sum+=a[j];
                        }
                        res=min(res,sum);
            }
            cout<<res;
            return 0;
}
