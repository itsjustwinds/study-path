#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int f[2*maxn],n,test,ok,a[maxn];
int main()
{
    //freopen("787b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>test;
    while(test)
    {
        test--;
        int k;
        cin>>k;
        ok=0;
        for (int j=maxn-n; j<=maxn+n; j++)
            f[j]=0;
        for (int j=1;j<=k;j++)
            cin>>a[j];
        for (int j=1; j<=k; j++)
        {
            if (a[j]>0)
            {
                f[maxn+abs(a[j])]++;
                if (f[maxn-abs(a[j])]>0)
                {
                    ok=1;
                    break;
                }
            }
            if (a[j]<0)
            {
                f[maxn-abs(a[j])]++;
                if (f[maxn+abs(a[j])]>0)
                {
                    ok=1;
                    break;
                }
            }
        }
        if (ok==0)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
