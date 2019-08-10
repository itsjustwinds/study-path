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
        int tt=1000;
        srand(time(NULL));
        for (int ii=1; ii<=tt; ++ii)
        {
                ofstream out ("D:\\c++\\HUGEKNAP.inp");
                int test=40;
                out<<test<<"\n";
                while(test--)
                {
                        int n=100;
                        int m=rand(1,1000);
                        out<<n<<" "<<m<<"\n";
                        for (int i=1; i<=n; ++i)
                                out<<rand(1,1000)<<" ";
                        out<<"\n";
                        for (int i=1; i<=n; ++i)
                                out<<rand(1,10000)<<" ";
                        out<<"\n";
                }
                out.close();
                system("D:\\c++\\HUGEKNAP.exe");
                system("D:\\c++\\HUGEKNAP_trau.exe");
                if (system("fc D:\\c++\\HUGEKNAP.out D:\\c++\\HUGEKNAP.ans")!=0)
                {
                        cout<<"WRONG\n";
                        return 0;
                }
                else cout<<"CORRECT\n";
        }
}
