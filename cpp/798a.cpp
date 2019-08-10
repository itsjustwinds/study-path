#include<bits/stdc++.h>
using namespace std;
char s[1000];
int n,res;
int main()
{
    //freopen("798a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    n=strlen(s+1);
    for (int i=1;i<=n/2;i++)
        if (s[i]!=s[n-i+1])
        res++;
    if (res==1) cout<<"YES";
    else cout<<"NO";
    return 0;
}
