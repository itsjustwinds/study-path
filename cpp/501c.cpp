#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
typedef pair<II,int> III;
II a[maxn];
int n;
queue<int> q;
int main()
{
    freopen("501c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].fs>>a[i].sc;
        if (a[i].fs==1) q.push(i);
    }
    int sum=0;
    for (int i=0;i<n;i++)
        sum+=a[i].fs;
    cout<<sum/2<<"\n";
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if (!a[u].fs) continue;
        a[u].fs--;
        int v=a[u].sc;
        cout<<u<<" "<<v<<"\n";
        a[v].sc=a[v].sc^u;
        a[v].fs--;
        if (a[v].fs==1) q.push(v);
    }
    return 0;
}
