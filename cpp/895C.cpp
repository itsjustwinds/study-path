#include<bits/stdc++.h>
#define maxn 100005
#define mod 1000000007
using namespace std;
int n,f[1000005],cnt[105],dem,res;
vector<int > P,X;
int d,mul[maxn];
void light_on(int &mask,int i)
{
        mask|=1<<(i);
}
int pt(int x)
{
        int mask=0;
        for (int i=0;i<P.size();++i)
        {
                if (x%P[i]==0)
                {
                        int D=0;
                        while(x%P[i]==0)
                        {
                                D++;
                                x/=P[i];
                        }
                        if (D%2) light_on(mask,i);
                }
        }
        return mask;
}
bool ngto(int x)
{
        for (int i=2;i*i<=x;++i)
        if (x%i==0) return 0;
        return 1;
}
int main()
{
        freopen("895C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=2;i<=70;++i)
                if (ngto(i)) P.push_back(i);
        int G=(1<<(P.size()))-1;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                if (!cnt[x])
                {
                        X.push_back(x);
                }
                ++cnt[x];
        }
        mul[0]=1;
        for (int i=1;i<=n;++i)
                mul[i]=(1ll*mul[i-1]*2)%mod;
        f[0]=1;
        for (int i=0;i<X.size();++i)
        {
                int x=X[i];
                int s=cnt[x];
                int mask=pt(x);
                int nw[1000005];
                for (int j=0;j<=G;++j) nw[j]=0;
                for (int j=0;j<=G;++j){
                        nw[j]=(nw[j]+(1ll*mul[s-1]*f[j])%mod)%mod;
                        nw[j]=(nw[j]+(1ll*mul[s-1]*f[j^mask])%mod)%mod;
                }
                swap(f,nw);
        }
        cout<<f[0]-1;
        //cout<<res;
}
