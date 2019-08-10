#include<bits/stdc++.h>
#define maxn 10000007
#include<fstream>
#define ll long long
using namespace std;
ifstream fi("IMPERFECT.inp");
ofstream fo("IMPERFECT.out");
ll a,b,f[maxn],res;
int main()
{
    //("imperfect.inp","r",stdin);
    //freopen("imperfect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>a>>b;
    for (int i=2;i<=b;i++)
        f[i]=i-1;
        f[1]=1;
    for (int i=2;i*i<=b;i++)
    {
        f[i*i]-=i;
        for (int j=i+1;j<=b/i;j++)
            f[i*j]-=i+j;
    }
    res=0;
    for (int i=a;i<=b;i++)
        res+=abs(f[i]);
    fo<<res;
    return 0;
}
