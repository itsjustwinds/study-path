#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll a[maxn],dd[2],d,n;
int main()
{
        freopen("VOGAME.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n>>d;
                dd[0]=0;
                dd[1]=0;
                for (int i=1;i<=d;i++)
                {
                        cin>>a[i];
                        dd[a[i]]++;
                }
                if (n==d)
                {
                        cout<<dd[1]%2<<"\n";
                        continue;
                }
                d++;
                ll k=n/d;
                a[d]=dd[1]%2;
                dd[a[d]]++;
                ll du=n-d*k;
                dd[1]*=k;
                for (int i=1;i<=du;i++)
                        dd[a[i]]++;
                cout<<dd[1]%2<<"\n";
        }
        return 0;
}
