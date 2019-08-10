#include<bits/stdc++.h>
#define maxn 10005
#define fs first
#define sc second
using namespace std;
int res[maxn],n,w;
typedef pair<int,int> II;
II a[maxn];
int main()
{
    //freopen("808c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>w;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fs;
        a[i].sc=i;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        w-=int(a[i].fs+1)/2;
        res[a[i].sc]+=int(a[i].fs+1)/2;
    }
    if (w<0)
    {
        cout<<-1;
        return 0;
    }
    if (w>0)
    {
        int i=n;
        while(w)
        {
            int tmp=min(w,int(a[i].fs/2));
            w-=tmp;
            res[a[i].sc]+=tmp;
            i--;
        }
    }
    for (int i=1;i<=n;i++)
        cout<<res[i]<<" ";
    return 0;
}
