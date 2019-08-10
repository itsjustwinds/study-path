#include<bits/stdc++.h>
#define fs first
#define sc second
#define maxn 10005
using namespace std;
int a[maxn],b[maxn],n;
long long sum,s;
typedef pair<int,int> II;
typedef pair <int,II> III;
//set <III> q;
priority_queue<III/*,vector<III> */> q;
int main()
{
    freopen("mpilot.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    for (int i=1; i<=n; i++)
    {
        sum+=a[i];
        q.push(III(a[i]-b[i],II(a[i],b[i])));
        if (i%2==1)
        {
            III t=q.top();
            q.pop();
            s+=t.sc.fs-t.sc.sc;
        }
    }
    cout<<sum-s;
    return 0;
}
