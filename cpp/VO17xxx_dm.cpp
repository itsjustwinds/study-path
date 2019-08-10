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
        srand(time(NULL));
        cin.tie(0);
        cout.tie(0);
        int tt=1000;
        for (int ii=1;ii<=tt;ii++)
        {
                ofstream out ("D:\\C++\\debug\\VO17XXX.inp");
                int n=rand(1,100000);
                out<<n<<" "<<rand(1,1000)<<"\n";
                for (int i=1;i<=n;i++)
                        out<<rand(1,1000000)<<" ";
                out.close();
                system("D:\\C++\\debug\\VO17XXX.exe");
                system("D:\\C++\\debug\\VO17XXX_mau.exe");
                if (system("fc D:\\C++\\debug\\VO17XXX.out D:\\C++\\debug\\VO17XXX.ans")!=0)
                {
                        cout<<"test "<<ii<<" wrong \n";
                        return 0;
                }
                else cout<<"test "<<ii<<" corect\n";
        }
        return 0;
}
