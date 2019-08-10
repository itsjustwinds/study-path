#include<bits/stdc++.h>
using namespace std;
int f[100005],n;
int main()
{
    freopen("hr47a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        f[x]++;
            if (f[x]==2)
            {
                cout<<"NO";
                return 0;
            }
    }
    cout<<"YES";
    return 0;
}
