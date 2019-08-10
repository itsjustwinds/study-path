#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int a[maxn],n;
ll res;
bool cmp(int a,int b)
{
        return a>b;
}
int main()
{
        freopen("nhom3.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i+=3)
        {
                res+=a[i];
                res+=a[i+1];
        }
        cout<<res;
        return 0;
}
