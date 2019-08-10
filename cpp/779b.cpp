#include <bits/stdc++.h>
using namespace std;
int k,res;
char n[15];
int main()
{
    //freopen("779b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(n+1);
    cin>>k;
    int kd=k;
    int m=strlen(n+1);
    while (k)
    {
        if (n[m]=='0') k--;
        if (n[m]!='0')
        {
            res++;
        }
        m--;
        if (m==0&&k>0)
        {
            if (k<kd) cout<<strlen(n+1)-1;
            return 0;
        }
    }
    cout<<res;
    return 0;
}
