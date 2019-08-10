#include<bits/stdc++.h>
#define maxn 10000
#define ll long long
using namespace std;
int n;
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
        srand(time(NULL));
        int tmp=100;
        int test=tmp;
        while(test--)
        {
                ofstream inp ("D:\\C++\\huy\\PVOI14_5.inp");
                int n=random(1,100000);
                inp<<n<<"\n";
                for (int i=1; i<=n; i++)
                {
                        int x=random(1,10000);
                        inp<<x<<" ";
                }
                inp.close();
                system("D:\\C++\\huy\\PVOI14_5.exe");
                system("D:\\C++\\huy\\PVOI14_5_trau.exe");
                if (system("fc D:\\C++\\huy\\PVOI14_5.out D:\\C++\\huy\\PVOI14_5.ans")!=0)
                {
                        cout<<"test "<<tmp-test<<" WRONG\n";
                        return 0;
                }
                else cout<<"test "<<tmp-test<<" CORECT\n";
        }
        return 0;
}
