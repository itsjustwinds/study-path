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
        int itest=1000;
        srand(time(NULL));
        for (int ii=1;ii<=itest;++ii)
        {
                ofstream out ("D:\\c++\\LCIS.inp");
                int n=rand(5000,5000);
                out<<n<<"\n";
                for (int i=1;i<=n;++i)
                        out<<rand(-10000,10000)<<" ";
                out<<"\n";
                int m=rand(5000,5000);
                out<<m<<"\n";
                for (int i=1;i<=m;++i)
                        out<<rand(-10000,10000)<<" ";
                out.close();
                system("D:\\c++\\LCIS.exe");
                system("D:\\c++\\LCIS_trau.exe");
                if (system("fc D:\\c++\\LCIS.out D:\\c++\\LCIS.ans")!=0)
                {
                        cout<<ii<<" wrong ";
                        return 0;
                }
                cout<<ii<<" true\n";
        }
        return 0;
}
