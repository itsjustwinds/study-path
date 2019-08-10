#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
int f[maxn],dd[maxn],n,dem;
typedef pair<int,int> II;
II a[maxn];
int main()
{
    freopen("dominoes.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fs>>a[i].sc;
        ac[++dem]=a[i].fs;
        ac[++dem]=a[i].sc;
    }

}
