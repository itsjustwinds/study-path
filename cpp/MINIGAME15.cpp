#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn],n,res;
int main()
{
    freopen("MINIGAME15.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
        if (a[i]%2==0)
        {
            if (a[i]==0)
            {
                int k=lower_bound(a+1,a+n+1,a[i]/2)-a;
                int h=upper_bound(a+1,a+n+1,a[i]/2)-a;
                if (h-k!=1) res++;
                continue;
            }
            int k=lower_bound(a+1,a+n+1,a[i]/2)-a;
            if (a[k]==a[i]/2) res++;
        }
    cout<<res;
    return 0;
}
