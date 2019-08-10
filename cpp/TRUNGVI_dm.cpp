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
        srand(time(NULL));
        for (int ii=1;ii<=tt;++ii)
        {
                ofstream out ("D:\\c++\\TRUNGVI.inp");
                int n=rand(10,10);
                int m=rand(1,n);
                out<<n<<" "<<m<<"\n";
                int a[5005];
                for (int i=1;i<=n;++i)
                        a[i]=i;
                random_shuffle(a+1, a+n+1);
                for (int i=1;i<=n;++i)
                        out<<a[i]<<" ";
                out.close();
                system("D:\\c++\\TRUNGVI.exe");
                system("D:\\c++\\TRUNGVI_trau.exe");
                if (system("fc D:\\c++\\TRUNGVI.out D:\\c++\\TRUNGVI.ans")!=0)
                {
                        cout<<"wrong test "<<ii;
                        return 0;
                }
                else cout<<"correct "<<ii<<"\n";
        }
}

