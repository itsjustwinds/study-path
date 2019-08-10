#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int dd[maxn],n,ht;
int main()
{
    //freopen("Snacktower.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    ht=n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        dd[x]=1;
        if (x==ht)
        {
            for (int j=x; j>=1; j--)
            {
                if (dd[j]==1) cout<<j<<" ";
                else
                {
                    cout<<"\n";
                    ht=j;
                    break;
                }
            }
        }
        else cout<<"\n";
    }
    return 0;
}
