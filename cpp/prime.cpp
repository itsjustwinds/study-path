#include<bits/stdc++.h>
using namespace std;
int L,R,p[50],n;
vector<int >res;
void dfs(int i,int N)
{
        if (N>=L&&N<=R) res.push_back(N);
        if (1ll*N*p[i]>R) return;
        for (int j=i;j<=n;++j)
        {
                if (1ll*N*p[j]<=R) dfs(j,1ll*N*p[j]);
                else break;
        }
}
int main()
{
        freopen("PRIME.inp","r",stdin);
        freopen("PRIME.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>p[i];
        sort(p+1,p+n+1);
        cin>>L>>R;
        dfs(1,1);
        if (res.size()==0)
        {
                cout<<"none";
                return 0;
        }
        sort(res.begin(),res.end());
        for (int i=0;i<res.size()-1;++i)
                cout<<res[i]<<",";
        cout<<res[res.size()-1];
}
