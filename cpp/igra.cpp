#include <bits/stdc++.h>
using namespace std;
int f[3],n,ok;
char s[5005],res[5005];
void tryy(int i)
{
    if (ok==1) return ;
    for (int j=0;j<=2;j++)
    if (j+'a'!=s[i]&&f[j]>0)
    {
        res[i]=j+'a';
        f[j]--;
        if (i==n)
        {
            for (int k=1;k<=n;k++)
                cout<<res[k];
            ok=1;
        }
        else tryy(i+1);
        if(ok==1) return ;
        f[j]++;
    }
}
int main()
{
    freopen("igra.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        char k;
        cin>>k;
        f[k-'a']++;
    }
    cin>>(s+1);
    tryy(1);
    return 0;
}
