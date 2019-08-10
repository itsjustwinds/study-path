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
        srand(time(NULL));
        int itest=1000;
        for (int ii=1;ii<=itest;++ii)
        {
                ofstream out("D:\\C++\\LUBENICA.inp");
                int n=rand(1e5,1e5);
                out<<n<<"\n";
                for (int i=2;i<=n;++i)
                {
                        out<<i<<" "<<rand(1,i-1)<<" "<<rand(1,1e6)<<"\n";
                }
                int test=rand(1e5,1e5);
                out<<test<<"\n";
                for (int i=1;i<=test;++i)
                {
                        out<<rand(1,n)<<" "<<rand(1,n)<<"\n";
                }
                out.close();
                system("D:\\c++\\LUBENICA.exe");
                system("D:\\C++\\LUBENICA_mau.exe");
                if (system("fc D:\\c++\\LUBENICA.out D:\\c++\\LUBENICA.ans")!=0)
                {
                        cout<<"test "<<ii<<" wrong";
                        return 0;
                }
                else cout<<"test "<<ii<<" true\n";
        }
}
