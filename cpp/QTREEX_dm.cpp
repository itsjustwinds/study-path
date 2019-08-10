#include<bits/stdc++.h>
#define ll long long
#define fs first
#define sc second
#define maxn 10005
using namespace std;
ll rand(int l,int r)
{
        return l+((ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)*(RAND_MAX+1)+
                  (ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)+
                  (ll)rand()*(RAND_MAX+1)+
                  rand())%(r-l+1);

}
typedef pair<int,int> II;
II edge[maxn];
int dem;
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ttest=100;
        srand(time(NULL));
        for (int itest=1; itest<=ttest; itest++)
        {
                ofstream out ("D:\\C++\\debug\\QTREEX.inp");
                int tmp=20;
                out<<tmp<<"\n";
                for (int j=1; j<=tmp; j++)
                {
                        dem=0;
                        int n=rand(10000,10000);
                        out<<n<<"\n";
                        for (int i=2; i<=n; i++)
                        {
                                int v=rand(1,i-1);
                                edge[++dem]=II(i,v);
                                out<<i<<" "<<v<<" "<<rand(-10000000,10000000)<<"\n";
                        }
                        int q=rand(1,10000);
                        for (int i=1; i<=q; i++)
                        {
                                int x=rand(1,3);
                                if (x==1)
                                {
                                        int tmp1=rand(1,dem);
                                        out<<"CHANGE "<<tmp1<<" "<<rand(-10000000,10000000)<<"\n";
                                        continue;
                                }
                                if (x==2) out<<"NEGATE ";
                                else out<<"QUERY ";
                                int tmp1=rand(1,n);
                                int tmp2=rand(1,n);
                                out<<tmp1<<" "<<tmp2<<"\n";
                        }
                        out<<"DONE\n";
                }
                out.close();
                system("D:\\C++\\debug\\QTREEX.exe");
                system("D:\\C++\\debug\\QTREEX_trau.exe");
                if (system("fc D:\\C++\\debug\\QTREEX.out D:\\C++\\debug\\QTREEX.ans")!=0)
                {
                        cout<<"WRONG TEST "<<itest<<"\n";
                        break;
                }
                else cout<<"CORECT TEST "<<itest<<"\n";
        }
        return 0;
}
