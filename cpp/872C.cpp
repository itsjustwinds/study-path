#include<bits/stdc++.h>
#define maxn 1000007
using namespace std;
int q,n,dd[maxn];
vector<int > cp;
bool check(int n)
{
        for (int i=2;i*i<=n;++i)
        if (n%i==0) return 0;
        return 1;
}
int cal(int n)
{
        if (n<4) return -1;
        if (check(n)) return -1;
        res=0;
        for (int i=0;i<cp.size();++i)
        {
                res+=n/cp[i];
                n%=cp[i];
        }

}
int main()
{
        freopen("872C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>q;
        for (int i=2;i*i<=1e9;++i)
                cp.push_back(i*i);
        while(q--)
        {
                cin>>n;
                cout<<cal(n)<<"\n";
        }
}
