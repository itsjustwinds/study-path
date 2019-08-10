#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rand(int l,int r)
{
        return l+(1ll*rand()*(RAND_MAX+1)*(RAND_MAX+1)*(RAND_MAX+1)+
                  1ll*rand()*(RAND_MAX+1)*(RAND_MAX+1)+
                  1ll*rand()*(RAND_MAX+1)+
                  rand())%(r-l+1);
}
int dd[105][105];
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int tt=1000;
        srand(time(NULL));
        for (int ii=1;ii<=tt;++ii)
        {
                ofstream out("D:\\c++\\MINCOST.inp");
                int n=rand(100,100);
                int need=rand(1,300000);
                int m=rand(1,1000);
                int s=rand(1,n);
                int t=rand(1,n);
                out<<n<<" "<<m<<" "<<need<<" "<<s<<" "<<t<<"\n";
                while(m)
                {
                        int u,v,c,cost;
                        u=rand(1,n);
                        v=rand(1,n);
                        if (dd[u][v]||dd[v][u]) continue;
                        m--;
                        dd[u][v]=1;
                        c=rand(1,30000);
                        cost=rand(1,1000000000);
                        out<<u<<" "<<v<<" "<<cost<<" "<<c<<"\n";
                }
                for (int i=1;i<=n;++i)
                        for (int j=1;j<=n;++j)
                        dd[i][j]=0;
                out.close();
                system("D:\\c++\\MINCOST.exe");
                system("D:\\c++\\MINCOST_sample.exe");
                if (system("fc D:\\c++\\MINCOST.out D:\\c++\\MINCOST.ans")!=0)
                {
                        cout<<"wrong "<<ii;
                        return 0;
                }
                else cout<<"correct "<<ii<<"\n";
        }
        return 0;
}
