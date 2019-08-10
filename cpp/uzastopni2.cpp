#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    freopen("uzastopni.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    //int m=int(sqrt(n));
    //if (int(sqrt(n))!=sqrt(n)) m++;
    for (int i=2;i<=n/2;i++)
    {
        long long k=n/i;
        long long t=0;
        for (int j=1;j<=(i-1)/2;j++)
            t+=k+j;
        for (int j=1;j<=(i-1)/2;j++)
            if (k-j<=0 ) return 0;
            else t+=k-j;
        t+=k;
        if (i%2==0)
        {
            if (t+k+(i-1)/2+1==n) cout<<k-(i-1)/2<<" "<<k+(i-1)/2+1<<"\n";
            if (t+k-(i-1)/2-1==n) cout<<k-(i-1)/2-1<<" "<<k+(i-1)/2<<"\n";
        }
        else
        {
            if (t==n) cout<<k-i/2<<" "<<k+i/2<<"\n";
        }
    }
    return 0;
}
