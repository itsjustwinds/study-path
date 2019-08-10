#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m;
struct data
{
        int u,v;
};
vector<data > e;
int main()
{
        //freopen("TOURMAP.inp","r",stdin);
        //freopen("TOURMAP.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        if(m==n)
        {
                cout<<"Possible\n";
                cout<<1<<" "<<n;
                for (int i=2;i<=n;++i)
                        cout<<i-1<<" "<<i<<"\n";
                return 0;
        }
        cout<<"Impossible";
}

