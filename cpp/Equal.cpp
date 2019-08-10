#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,mi,res;
int main()
{
    freopen("Equal.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        mi=1000000000;
        res=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            mi=min(mi,a[i]);
        }
        for (int i=1;i<=n;i++)
        {
            int tmp=a[i]-mi;
            res+=tmp/5;
            tmp%=5;
            res+=tmp/2;
            tmp%=2;
            res+=tmp;
        }
        cout<<res<<"\n";
    }
    return 0;
}
