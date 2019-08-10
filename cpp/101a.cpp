#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
char s[maxn],t[maxn];
int n;
int main()
{
    freopen("101a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>(s+1);
    cin>>(t+1);
    int res=0;
    for (int i=1;i<=n;i++)
        if (s[i]!='.')
    {
        if (s[i]!=t[i]) res++;
    }
    cout<<res;
}
