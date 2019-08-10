#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],b[maxn],dd[maxn],n,ans[maxn];
void update(int x,int y)
{
    ans[x]=y;
    while (ans[dd[x]-1]<=y&&dd[x]-1>0)
        dd[x]=dd[dd[x]-1];
}
int get(int x)
{
    return ans[dd[x]];
}
int main()
{
    freopen("INSERTAR.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>n>>test;
    ans[0]=1000000000;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    while(test--)
    {
        int c,x,y;
        cin>>c;
        if (c==1)
        {
            cin>>x>>y;
            dd[x]=x;
            update(x,y);
        }
        else
        {
            cin>>x;
            int k=get(x);
            if (k==0)
            {
                cout<<a[x]<<"\n";
            }
            else cout<<b[x]<<"\n";
        }
    }
    return 0;
}
