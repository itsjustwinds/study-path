#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rand(int l,int h)
{
    return l+((ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)*(RAND_MAX+1)+
              (ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)+
              (ll)rand()*(RAND_MAX+1)+
              rand())%(h-l+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp=10;
    srand(time(NULL));
    for (int itest=1; itest<=tmp; itest++)
    {
        ofstream out ("D:\\C++\\TST\\TOURS13.inp");
        int test=rand(1,1);
        out<<test<<"\n";
        while(test--)
        {
            int n=rand(1,20);
            int m=rand(1,20);
            out<<n<<" "<<m<<"\n";
            for (int i=1; i<=m; i++)
            {
                int u=rand(1,n);
                int v=u;
                while(v==u) v=rand(1,n);
                int c=rand(1,1000000);
                out<<u<<" "<<v<<" "<<c<<"\n";
            }
        }
        out.close();
        system("D:\\C++\\TST\\tours13.exe");
        system("D:\\C++\\TST\\tours13_trau.exe");
        if (system("fc D:\\C++\\TST\\tours13.ans D:\\C++\\TST\\tours13.out")!=0)
        {
            cout<<"test "<<itest<<" WRONG\n";
            return 0;
        }
        else cout<<"test "<<itest<<" CORECT\n";
    }
    return 0;
}
