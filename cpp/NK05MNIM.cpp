#include<bits/stdc++.h>
using namespace std;
int n,tmp;
int main()
{
        freopen("NK05MNIM.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n;
                tmp=0;
                int ok=1;
                for (int i=1;i<=n;i++)
                {
                        int x;
                        cin>>x;
                        tmp^=x;
                        if (x!=1) ok=0;
                }
                if (ok)
                {
                        if(n%2) cout<<"-1\n";
                        else cout<<"1\n";
                        continue;
                }
                if (tmp==0)
                {
                        cout<<"-1\n";
                }
                else cout<<"1\n";
        }
        return 0;
}
