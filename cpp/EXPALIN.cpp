#include<bits/stdc++.h>
#define maxn 5000005
#define ll long long
using namespace std;
ll n,res;
char s[maxn],tmp[maxn];
int dem;
int main()
{
    freopen("expalin.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>(s+1);
        n=strlen(s+1);
        res=n;
        for (int i=1; i<=n; i++)
        {
            for (int j=2; (ll)j*i<=n; j++)
            {
                dem=1;
                tmp[1]=s[i];
                for(ll k=i*j; k<=n; k*=j)
                {
                    tmp[++dem]=s[k];
                    int ok=0;
                    for (int ac=1;ac<=dem/2;ac++)
                        if (tmp[ac]!=tmp[dem-ac+1])
                    {
                        ok=1;
                        break;
                    }
                    if (!ok) res++;
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
