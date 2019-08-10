#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int a[maxn],n,dd[maxn],trace[maxn];
vector<int> dem;
int main()
{
    freopen("FE.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int now=1;
    for (int i=2;i<=n+1;i++)
        if (a[i]==a[i-1])
        {
            now++;
        }
        else
        {
            if (dd[now]==0)
            {
                dem.push_back(now);
                trace[now]=a[i-1];
            }
            dd[now]++;
            now=1;
        }
    for (int i=0;i<(int)dem.size();i++)
    {
        int v=dem[i];
        if (dd[v]==1)
        {
            cout<<trace[v];
            return 0;
        }
    }
    return 0;
}
