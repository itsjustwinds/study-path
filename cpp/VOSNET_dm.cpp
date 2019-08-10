#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rand(int l,int r)
{
            return l+((ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)*(RAND_MAX+1)+
                      (ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)+
                      (ll)rand()*(RAND_MAX+1)+
                      rand())%(r-l+1);
}
int dd[3005][3005];
int main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int tt=1000;
            srand(time(NULL));
            for (int ii=1;ii<=tt;++ii)
            {
                        memset(dd,0,sizeof(dd));
                        ofstream out("D:\\c++\\debug\\VOSNET.inp");
                        int n=rand(3000,3000);
                        int m=rand(100,100);
                        for (int i=1;i<=n;++i) dd[i][i]=1;
                        out<<n<<" "<<m<<"\n";
                        int tmp=0;
                        while(tmp<m)
                        {
                                    int u=rand(1,n);
                                    int v=rand(1,n);
                                    if (dd[u][v]) continue;
                                    tmp++;
                                    dd[u][v]=1;
                                    dd[v][u]=1;
                                    out<<u<<" "<<v<<"\n";
                        }
                        out.close();
                        system("D:\\c++\\debug\\VOSNET.exe");
                        system("D:\\c++\\debug\\VOSNET_trau.exe");
                if (system("fc D:\\C++\\debug\\VOSNET.out D:\\C++\\debug\\VOSNET.ans")!=0)
                {
                        cout<<"WRONG TEST "<<ii<<"\n";
                        return 0;
                }
                else cout<<"CORECT TEST "<<ii<<"\n";
            }
            return 0;
}
