#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
char a[maxn],b[maxn],res[maxn];
int n;
int main()
{
    //freopen("801b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(a+1);
    cin>>(b+1);
    n=strlen(a+1);
    for (int i=1; i<=n; i++)
    {
        if (b[i]-a[i]<0)
        {
            res[i]=b[i];
            continue;

        }
        if (b[i]>a[i])
        {
            cout<<-1;
            return 0;
        }
        res[i]=a[i];
    }
    for (int i=1;i<=n;i++)
        cout<<res[i];
    return 0;
}
