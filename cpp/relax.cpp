#include<bits/stdc++.h>
#define ll long long
#include<fstream>
#define maxn 100005
using namespace std;
ifstream fi("relax.inp");
ofstream fo("relax.out");
int n;
ll a[maxn],sum[maxn];
int findd(int l,int r,ll x)
{
    while(l<=r)
    {
        int m=(l+r)/2;
        if (sum[m]<x) l=m+1;
        if (sum[m]>x) r=m-1;
        if (sum[m]==x) return m;
    }
    return 0;
}
ll tinh(int l,int r)
{
    if ((sum[r]-sum[l-1])%2) return 0;
    if (l>=r) return 0;
    int tmp=findd(l,r,sum[l-1]+(sum[r]-sum[l-1])/2);
    if (tmp!=0) return 1+max(tinh(l,tmp),tinh(tmp+1,r));
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    fi>>test;
    while(test)
    {
        test--;
        fi>>n;
        for (int i=1; i<=n; i++)
        {
            fi>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        ll res=tinh(1,n);
        fo<<res<<"\n";
    }
    return 0;
    fi.close();
}
