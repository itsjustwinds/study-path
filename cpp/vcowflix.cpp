#include <bits/stdc++.h>
using namespace std;
int f[5005],n,w[20],c,dd[5005];
int main()
{
    //freopen("vcowflix.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n;
    for (int i=1; i<=n; i++)
        cin>>w[i];
    f[0]=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=c-w[i]; j++) if (f[j]==1&&dd[j]!=i)
            {
                f[j+w[i]]=1;
                if (dd[j+w[i]]==0) dd[j+w[i]]=i;
            }
    }
    for (int i=c; i>=0; i--) if (f[i]==1)
        {
            cout<<i;
            return 0;
        }

}
