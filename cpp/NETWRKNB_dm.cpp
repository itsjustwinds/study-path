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
            for (int ii=1; ii<=tt; ++ii)
            {
                        ofstream out ("D:\\C++\\debug\\NETWRKNB.inp");
                        int n=rand(100000,100000);
                        int q=rand(100000,100000);
                        out<<n<<" "<<q<<"\n";
                        for (int i=2; i<=n; ++i)
                        {
                                    int tmp=rand(1,2);
                                    if (tmp==1) out<<i<<" "<<rand(1,i-1)<<" "<<rand(1,1000000000)<<"\n";
                                    else out<<rand(1,i-1)<<" "<<i<<" "<<rand(1,1000000000)<<"\n";
                        }
                        for (int i=1; i<=q; ++i)
                        {
                                    int tmp=rand(1,2);
                                    if (tmp==1)
                                    {
                                                out<<"P ";
                                                out<<rand(1,n)<<" "<<rand(1,n)<<" "<<rand(1,1000000000)<<"\n";
                                    }
                                    else
                                    {
                                                out<<"T ";
                                                out<<rand(1,n-1)<<" "<<rand(1,1000000000)<<"\n";
                                    }
                        }
                        out.close();
                        system("D:\\C++\\debug\\NETWRKNB.exe");
                        system("D:\\C++\\debug\\NETWRKNB_mau.exe");
                        if (system("fc D:\\C++\\debug\\NETWRKNB.out D:\\C++\\debug\\NETWRKNB.ans")!=0)
                        {
                                    cout<<"WRONG TEST "<<ii<<"\n";
                                    return 0;
                        }
                        else cout<<"CORECT TEST "<<ii<<"\n";
            }
            return 0;
}
