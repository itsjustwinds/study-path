#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int a[maxn],b[maxn],n;
long long res;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    //freopen("msp.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int k=1;k<t;k++)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=1;i<=n;i++)
            cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1,cmp);
        res=0;
        for (int i=1;i<=n;i++)
            res+=a[i]*b[i];
        cout<<"Case "<<k<<": "<<res<<"\n";
    }
    cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=1;i<=n;i++)
            cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1,cmp);
        res=0;
        for (int i=1;i<=n;i++)
            res+=a[i]*b[i];
        cout<<"Case "<<t<<": "<<res;
    return 0;
}
