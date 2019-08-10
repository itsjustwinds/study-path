#include<bits/stdc++.h>
#define maxn 500005
#define db double
using namespace std;
int n,k;
double a[maxn];
double sum,res;
int main()
{
    //freopen("808b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=k;i++)
        sum+=db(a[i]);
    res+=sum;
    for (int i=2;i<=n-k+1;i++)
    {
        sum-=a[i-1];
        sum+=a[k+i-1];
        res+=sum;
    }
    cout<<fixed<<setprecision(10)<<double(res/(n-k+1));
    return 0;
}
