#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
struct node
{
    int a,x,y;
};
int n,m,a[maxn],b[maxn],k;
struct cmp
{
    bool operator() (node a,node b)
    {
        return a.a>b.a;
    }
};
int main()
{
    priority_queue <node,vector<node>,cmp > q;
    freopen("kmin.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int j=1; j<=m; j++)
        cin>>b[j];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for (int i=1; i<=n; i++)
    {
        node s;
        s.a=a[1]+b[i];
        s.x=1;
        s.y=i;
        q.push(s);
    }
    for (int i=1; i<=k; i++)
    {
        node s=q.top();
        cout<<s.a<<"\n";
        q.pop();
        node l;
        if (a[s.x+1]-a[s.x]<b[s.y+1]-b[s.y])
        {
            l.a=a[s.x+1]+b[s.y];
            l.x=s.x+1;
            l.y=s.y;
        }
        else
        {
            l.a=a[s.x]+b[s.y+1];
            l.x=s.x;
            l.y=s.y+1;
        }
        q.push(l);
    }
    return 0;

}
