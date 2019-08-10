#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
typedef pair<int,int> II;
typedef pair<int,II> III;
III a[maxn];
int main()
{
    freopen("805c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if (n%2==0)
    {cout<<(1LL*(n/2)-1)%(n+1);
    return 0;
    }
    cout<<(1LL*(n/2))%(n+1);
    return 0;
}
