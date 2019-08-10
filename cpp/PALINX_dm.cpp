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
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int tt=1000;
        for (int ii=1;ii<=tt;++ii)
        {
                ofstream out ("D:\\c++\\PALINX.inp");
                int n=1000;
                out<<n<<"\n";
                for (int i=1;i<=n;++i)
                {
                        int x=rand(1,1000);
                        out<<x<<" ";
                        for (int j=1;j<=x;++j)
                                out<<char(rand(0,1)+'a');
                        out<<"\n";
                }
                out.close();
                system("D:\\c++\\PALINX.exe");
                system("D:\\c++\\PALINX_trau.exe");
                if (system("fc D:\\c++\\PALINX.out D:\\c++\\PALINX.ans")!=0)
                {
                        cout<<"wrong test "<<ii;
                        return 0;
                }
                else cout<<"correct test "<<ii<<"\n";
        }
}
