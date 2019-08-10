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
        int tt=10000;
        for (int ii=1;ii<=tt;ii++)
        {
                ofstream out ("D:\\c++\\debug\\PERREC.inp");
                out<<rand(1,2000)<<" "<<rand(1,4000000)<<" ";
                out<<rand(1,2000)<<" "<<rand(1,2000)<<" "<<rand(1,2000)<<" "<<rand(1,2000)<<" "<<rand(1,2000)<<" "<<rand(1,2000);
                out.close();
                system("D:\\c++\\debug\\PERREC.exe");
                system("D:\\c++\\debug\\PERREC_mau.exe");
                if (system("fc D:\\c++\\debug\\PERREC.out D:\\c++\\debug\\PERREC.ans")!=0)
                {
                        cout<<"test "<<ii<<"wrong\n";
                        return 0;
                }
                else cout<<"test "<<ii<<"true\n";
        }
        return 0;
}
