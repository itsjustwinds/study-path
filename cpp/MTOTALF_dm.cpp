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
    int ttest=10000;
    for (int itest=1; itest<=ttest; itest++)
    {
        ofstream out ("D:\\C++\\TST\\MTOTALF.inp");
        int n=rand(1,30);
        out<<n<<"\n";
        for (int i=1; i<=n; i++)
        {
            int tmp=rand(1,4);
            if (tmp==1)
            {
                char a,b;
                int k;
                a=char(rand(0,25)+'A');
                b=char(rand(0,25)+'A');
                k=rand(1,1000);
                out<<a<<" "<<b<<" "<<k<<"\n";
            }
            if (tmp==2)
            {
                char a,b;
                int k;
                a=char(rand(0,25)+'a');
                b=char(rand(0,25)+'a');
                k=rand(1,1000);
                out<<a<<" "<<b<<" "<<k<<"\n";
            }
            if (tmp==3)
            {
                char a,b;
                int k;
                a=char(rand(0,25)+'A');
                b=char(rand(0,25)+'a');
                k=rand(1,1000);
                out<<a<<" "<<b<<" "<<k<<"\n";
            }
            if (tmp==4)
            {
                char a,b;
                int k;
                a=char(rand(0,25)+'a');
                b=char(rand(0,25)+'A');
                k=rand(1,1000);
                out<<a<<" "<<b<<" "<<k<<"\n";
            }
        }
        out.close();
        system("D:\\C++\\TST\\MTOTALF.exe");
        system("D:\\C++\\TST\\MTOTALF_trau.exe");
        if (system("fc D:\\C++\\TST\\MTOTALF.out D:\\C++\\TST\\MTOTALF.ans")!=0)
        {
            cout<<"test "<<itest<<" WRONG\n";
            return 0;
        }
        else cout<<"test "<<itest<<" CORECT\n";
    }
    return 0;
}
