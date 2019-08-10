#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll random(int l,int r)
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
    ofstream inp ("D:\\C++\\huy\\LCS2X.inp");
    srand(time(NULL));
    int tmp=1000;
    for (int itest=1; itest<=tmp; itest++)
    {
        int test=random(1,10);
        inp<<test<<"\n";
        while(test--)
        {
        int n=1500;
        int m=1500;
        inp<<n<<" "<<m<<"\n";
        for (int i=1; i<=n; i++)
        {
            //int x=random(1,100);
            inp<<1<<" ";
        }
        inp<<"\n";
        for (int i=1; i<=m; i++)
        {
            //int x=random(1,100);
            inp<<1<<" ";
        }
        inp<<"\n";
        }
        inp.close();
        system("D:\\C++\\huy\\LCS2X.exe");
        system("D:\\C++\\huy\\LCS2X_trau.exe");
        if (system("fc D:\\C++\\huy\\LCS2X.out D:\\C++\\huy\\LCS2X.ans")!=0)
        {
            cout<<"test "<<itest<<" WRONG\n";
            return 0;
        }
        else cout<<"test "<<itest<<" CORECT\n";
    }
    return 0;
}
