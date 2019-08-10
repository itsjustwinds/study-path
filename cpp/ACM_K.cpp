#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;
int a[3*maxn],n;
ll res;
int main()
{
        freopen("ACM_K.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n;
                n*=3;
                for (int i=1;i<=n;++i)
                        cin>>a[i];
                sort(a+1,a+n+1);
                int l=1,r=n;
                int res=0;
                while(l<=r)
                {
                        l++;
                        r--;
                        res+=a[r];
                        r--;
                }
                cout<<res<<"\n";
        }
}
