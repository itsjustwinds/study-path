#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
typedef pair<int,int> II;
vector<II> res;
queue<int> s;
int q,que[maxn],maxx;
int main()
{
    freopen("volley.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    int i_love_u;
    cin>>i_love_u;
    for (int i=1;i<=i_love_u;i++)
    {
        cin>>que[i];
        maxx=max(que[i],maxx);
    }
    int champ=s.front();
    s.pop();
    for (int i=1;i<=maxx;i++)
    {
        int x=s.front();
        s.pop();
        res.push_back(II(champ,x));
        s.push(min(champ,x));
        champ=max(x,champ);
    }
    for (int i=1;i<=i_love_u;i++)
    {
        cout<<res[que[i]-1].first<<" "<<res[que[i]-1].second<<"\n";
    }
    return 0;
}
