#include<bits/stdc++.h>
#define maxn 100005
#define mod 1000000007
#define ll long long
using namespace std;
int sum,n,a[maxn],power[maxn],fre[maxn];
int main()
{
    freopen("PLUSMUL.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    power[0]=1;
    for (int i=1; i<=maxn; i++)
        power[i]=(power[i-1]*2)%mod;
    while(test--)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        int sum=a[1];
        fre[1]=a[1];
        for (int i=2; i<=n; i++)
        {
            fre[i]=((ll)(fre[i-1]+1)*a[i]+((ll)a[i])%mod)%mod;
        }
        cout<<fre[n]<<"\n";
    }
    return 0;
}
