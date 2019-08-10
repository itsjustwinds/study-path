#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
long long res;
int f[maxn],a,b,ngto[maxn];
set <int> q;
void sang()
{
    for (int i=2;i*i<=maxn;i++)
    if (ngto[i]==0)
    {
        ngto[i]=i;
        for (int j=i*i;j<=maxn;j+=i)
            ngto[j]=i;
    }
}
void tinh(int x)
{
    for ( ; x > 1; x /= ngto[x])
    {
        if (f[ngto[x]] == 0)
        {
            q.insert(ngto[x]);
        }
        ++f[ngto[x]];
    }
}
int main()
{
    freopen("lcm.inp","r",stdin);
    //freopen("lcm.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    sang();
    while (t)
    {
        t--;
        cin>>a>>b;
        for (int i=a;i<=b;i++)
        {
            tinh(i);
        }
        res=1;
        while (!q.empty())
        {
            int k=*q.begin();
            q.erase(k);
            res=(res*(2*f[k]+1))%111539786;
            f[k]=0;
        }
        cout<<res<<"\n";
    }
}
