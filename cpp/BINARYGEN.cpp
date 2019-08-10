#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int n;
char s[maxn],res[maxn];
int main()
{
    //freopen("BINARYGEN.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>(s+1);
    int ok=0;
    for (int i=n;i>=1;i--)
    {
        if (s[i]=='1')
        {
            res[i]='0';
        }
        else
        {
            res[i]='1';
            ok=1;
            for (int j=1;j<i;j++)
                res[j]=s[j];
            break;
        }
    }
    if (ok)
    {
        for (int i=1;i<=n;i++)
            cout<<res[i];
        return 0;
    }
    else
    {
        cout<<'1';
        for (int i=1;i<=n;i++)
            cout<<res[i];
    }
    return 0;

}
