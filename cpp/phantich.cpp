#include<bits/stdc++.h>
#define maxn 20005
using namespace std;
int dd[maxn],n,m,f[maxn],sz,res;
vector<int > ngto;
void dfs(int i,int last,int sum)
{
        if (i==m+1)
        {
                ++res;
                return;
        }
        int lef=m-i+1;
        if (i+lef-1>m) return;
        if (sum+f[last+lef]-f[last]>n) return;
        for (int j=last+1;j<=sz;++j)
        if (sum+ngto[j-1]<=n) dfs(i+1,j,sum+ngto[j-1]);
        else break;
}
int main()
{
        freopen("PHANTICH.inp","r",stdin);
        freopen("PHANTICH.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=2;i*i<=n;++i)
        if (!dd[i])
        {
                for (int j=i*i;j<=n;j+=i)
                        dd[j]=1;
        }
        for (int i=2;i<=n;++i)
        if (!dd[i]) ngto.push_back(i);
        int sum=0;
        for (int i=0;i<ngto.size();++i)
        {
                int j=i+1;
                f[j]=f[j-1]+ngto[i];
        }
        sz=ngto.size();
        for (int i=0;i<ngto.size()&&sum+ngto[i]<=n;++i)
        {
                sum+=ngto[i];
                ++m;
        }
        dfs(1,0,0);
        cout<<res;
        return 0;
}
