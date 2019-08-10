#include<bits/stdc++.h>
using namespace std;
char s[1000];
int n,res;
int main()
{
    //freopen("801a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    n=strlen(s+1);
    for (int i=0; i<=n; i++)
    {
        int dem=0;
        if (s[i]=='V') s[i]='K';
        else s[i]='V';
        for (int i=1; i<=n-1; i++)
        {
            string tmp="";
            tmp=tmp+s[i];
            tmp=tmp+s[i+1];
            if (tmp=="VK") dem++;
        }
        res=max(res,dem);
        if (s[i]=='V') s[i]='K';
        else s[i]='V';
    }
    cout<<res;
    return 0;
}
