#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll rand(ll l,ll r)
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
        int tt=10000;
        for (int ii=1;ii<=tt;ii++)
        {
                ofstream out ("D:\\C++\\debug\\VMPIZZA.inp");
                int n=rand(1,100000);
                int b=rand(1,100000);
                out<<n<<" "<<b<<"\n";
                for (int i=1;i<=n;i++)
                {
                        out<<rand(1,100000)<<" "<<rand(1,100000)<<" "<<rand(1,100000)<<"\n";
                }
                out.close();
                system("D:\\C++\\debug\\VMPIZZA.exe");
                system("D:\\C++\\debug\\VMPIZZA_mau.exe");
                if (system("fc D:\\C++\\debug\\VMPIZZA.out D:\\C++\\debug\\VMPIZZA.ans")!=0)
                {
                        cout<<"test "<<ii<<" wrong";
                        return 0;
                }
                else cout<<"test "<<ii<<" true\n";
        }
        return 0;
}
