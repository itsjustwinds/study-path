#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
            int dem,dd[30];
            ll val;
};
data f[1000][30];
int d[30],n;
int main()
{
            freopen("tratien.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n;
            for (int i=1; i<=20; ++i)
                        d[i]=i*i;
            f[0][1].val=1;
            for (int i=1; i<=n; ++i)
                        for (int j=1; i-d[j]>=0; ++j)
                        {
                                    int tmp=i-d[j];
                                    for (int s=1; s<=20; ++s)
                                                for (int t=1; t<=s; ++t)
                                                {
                                                            f[i][s].val+=f[tmp][t].val;
                                                }
                        }
            ll sum=0;
            for (int i=1;i<=20;++i)
                        sum+=f[n][i].val;
            cout<<sum;
}
