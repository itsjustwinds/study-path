#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rand(int l,int r)
{
        return  l+((ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)*(RAND_MAX+1)+
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
        int tt=100;
        for (int itest=1; itest<=tt; itest++)
        {
                ofstream out ("D:\\C++\\debug\\OTOCI.inp");
                int n=rand(30000,30000);
                out<<n<<"\n";
                for (int i=1;i<=n;i++)
                        out<<rand(1,1000)<<" ";
                out<<"\n";
                int q=rand(300000,300000);
                out<<q<<"\n";
                for (int i=1; i<=q; i++)
                {
                        int tmp=rand(1,3);
                        if(tmp==1)
                        {
                                int u,v;
                                u=rand(1,n);
                                v=rand(1,n);
                                out<<"bridge "<<u<<" "<<v<<"\n";
                                continue;
                        }
                        if (tmp==2)
                        {
                                int u,v;
                                u=rand(1,n);
                                v=rand(1,n);
                                out<<"excursion "<<u<<" "<<v<<"\n";
                                continue;
                        }
                        out<<"penguins "<<rand(1,n)<<" "<<rand(1,1000)<<"\n";
                }
                out.close();
                system("D:\\C++\\debug\\OTOCI.exe");
                system("D:\\C++\\debug\\OTOCI_trau.exe");
                if (system("fc D:\\C++\\debug\\OTOCI.out D:\\C++\\debug\\OTOCI.ans")!=0)
                {
                        cout<<"WRONG "<<itest;
                        return 0;
                }
                else cout<<"CORECT "<<itest<<"\n";
        }
        return 0;
}
