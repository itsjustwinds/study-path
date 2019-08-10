#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int root[maxn+1];
int getr(int u)
{
            if (root[u]==u) return u;
            root[u]=getr(root[u]);
            return root[u];
}
int main()
{
            freopen("IOIBIN.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int test;
            for (int i=1;i<=maxn;++i)
            {
                        root[i]=i;
            }
            cin>>test;
            while(test--)
            {
                        int u,v,x;
                        cin>>u>>v>>x;
                        int ru=getr(u);
                        int rv=getr(v);
                        if (x==1)
                        {
                                    if (ru==rv) continue;
                                    root[ru]=rv;
                                    continue;
                        }
                        if (ru==rv) cout<<1<<"\n";
                        else cout<<"0\n";
            }
            return 0;
}
