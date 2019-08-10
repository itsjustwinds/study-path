#include<bits/stdc++.h>
using namespace std;
int sum,a[5][7],res;
vector<int > e[7];
int main()
{
        freopen("SUCSAC.inp","r",stdin);
        freopen("SUCSAC.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        for (int i=1;i<=4;++i)
        {
                for (int j=1;j<=6;++j)
                {
                        cin>>a[i][j];
                        sum+=a[i][j];
                }
        }
        e[1].push_back(3);e[1].push_back(4);e[1].push_back(5);e[1].push_back(6);
        e[2].push_back(3);e[2].push_back(4);e[2].push_back(5);e[2].push_back(6);
        e[3].push_back(1);e[3].push_back(2);e[3].push_back(5);e[3].push_back(6);
        e[4].push_back(1);e[4].push_back(2);e[4].push_back(5);e[4].push_back(6);
        e[5].push_back(1);e[5].push_back(2);e[5].push_back(3);e[5].push_back(4);
        e[6].push_back(1);e[6].push_back(2);e[6].push_back(3);e[6].push_back(4);
        for (int i1=1;i1<=6;++i1)
        for (auto k1: e[i1])
        {
                for (int i2=1;i2<=6;++i2)
                for (auto k2: e[i2])
                {
                        for (int i3=1;i3<=6;++i3)
                        for (auto k3: e[i3])
                        {
                                for (int i4=1;i4<=6;++i4)
                                for (auto k4: e[i4])
                                {
if (a[1][k1]==a[2][k2]&&a[2][i2]==a[3][i3]&&a[3][k3]==a[4][k4]&&a[4][i4]==a[1][i1])
{
        sum-=a[1][i1]+a[1][k1];
        sum-=a[2][i2]+a[2][k2];
        sum-=a[3][i3]+a[3][k3];
        sum-=a[4][i4]+a[4][k4];
        res=max(res,sum);
        sum+=a[1][i1]+a[1][k1];
        sum+=a[2][i2]+a[2][k2];
        sum+=a[3][i3]+a[3][k3];
        sum+=a[4][i4]+a[4][k4];
}
                                }
                        }
                }
        }
        if(res)cout<<res;
        else cout<<-1;
        return 0;
}
