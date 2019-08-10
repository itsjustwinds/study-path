#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rand(ll l,ll r)
{
        return l+((ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)*(RAND_MAX+1)+
                  (ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)+
                  (ll)rand()*(RAND_MAX+1)
                  +rand())%(r-l+1);
}
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int tt=10000;
        for (int ii=1;ii<=tt;ii++)
        {
                ofstream out ("D:\\C++\\debug\\VOMARIO.inp");
                int n=rand(1,10);
                out<<n<<"\n";
                for (int i=1;i<=n;i++)
                {
                        out<<rand(-10,10)<<" "<<rand(0,10)<<" "<<rand(0,10)<<"\n";
                }
                out.close();
                system("D:\\C++\\debug\\VOMARIO.exe");
                system("D:\\C++\\debug\\VOMARIO_mau.exe");
                if (system("fc D:\\C++\\debug\\VOMARIO.out D:\\C++\\debug\\VOMARIO.ans")!=0)
                {
                        cout<<"test "<<ii<<" wrong\n";
                        return 0;
                }
                else cout<<"test "<<ii<<" true\n";
        }
        return 0;
}
