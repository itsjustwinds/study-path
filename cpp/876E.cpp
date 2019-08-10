#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int n;
long long res;
priority_queue<int,vector<int >, greater<int > > q;
int main()
{
        //freopen("876E.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; ++i)
        {
                int x;
                cin>>x;
                if (q.size()!=0&&q.top()<x)
                {
                        int tmp=q.top();
                        res+=x-tmp;
                        q.pop();
                        q.push(x);
                }
                q.push(x);
        }
        cout<<res;
}
