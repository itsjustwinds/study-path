#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
ll rand(int l,int h)
{
    return l+((ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)*(RAND_MAX+1)+
              (ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)+
              (ll)rand()*(RAND_MAX+1)+
              rand())%(h-l+1);
}
int dd[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ofstream out ("D:\\C++\\huy\\VOTREE.inp");
    int n=rand(1,10);
    int q=rand(1,10);
    out<<n<<" "<<q<<"\n";
    for (int i=1;i<=n;i++)
}
