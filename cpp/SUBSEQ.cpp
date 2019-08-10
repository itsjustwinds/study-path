#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define fs first
#define sc second
using namespace std;
ll a[maxn];
int n,f[maxn];
map<ll,int > m;
map<ll,int > :: iterator it;
int main()
{
            freopen("SUBSEQ.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int test;
            cin>>n>>test;
            for (int i=0;i<n;++i)
                        cin>>a[i];
            f[0]=1;
            m[a[0]]=0;
            for (int i=1;i<n;++i)
            {
                        it=m.find(a[i]);
                        f[i]=f[i-1]+1;
                        if (it==m.end())
                        {
                                    m[a[i]]=i;
                                    continue;
                        }
                        int tmp=it->sc;
                        m[a[i]]=i;
                        if (i+1-f[i]>tmp) continue;
                        f[i]=i-tmp;
            }

}
