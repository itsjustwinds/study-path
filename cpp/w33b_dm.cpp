#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dem;
char a[100];
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
    int tmp=1000;
    a[++dem]='0';
    a[++dem]='1';
    //for (char k='a'; k<='z'; k++)
    //    a[++dem]=k;
    srand(time(NULL));
    for (int it=1; it<=tmp; it++)
    {
        ofstream out ("D:\\C++\\TST\\w33b.inp");
        int test=rand(1,20);
        out<<test<<"\n";
        while(test--)
        {
            int n=rand(1,2000);
            for (int i=1; i<=n; i++)
                out<<rand(0,1);
            out<<"\n";
        }
        out.close();
        system("D:\\C++\\TST\\w33b.exe");
        system("D:\\C++\\TST\\w33_trau.exe");
        if (system("fc D:\\C++\\TST\\w33b.out D:\\C++\\TST\\w33b.ans")!=0)
        {
            cout<<"test "<<it<<" WRONG\n";
            return 0;
        }
        else cout<< "test "<<it<<" CORRECT\n";
    }
    return 0;
}
