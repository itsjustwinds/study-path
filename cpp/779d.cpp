#include <bit/stdc++.h>
#define maxn 200005
using namespace std;
char s[maxn],k[maxn];
int n,a[maxn],dd[maxn];
int main()
{
    freopen("779d.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s+1;
    cin>>k+1;
    n=strlen(s+1);
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=n;i>=1;i--)
        dd[s[i]-65]=
}
