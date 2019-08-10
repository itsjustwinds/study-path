#include<bits/stdc++.h>
#define mod 100007
#define base 2
#define ll long long
#define maxn 105
using namespace std;
int hashs[maxn],n,k,res,dd[mod],power[maxn];
char s[maxn],ac[maxn];
vector<int> e[maxn];
int get(int i,int j)
{
    return (hashs[j]-((ll)hashs[i-1]*power[j-i+1])%mod+mod)%mod;
}
void dfs(int i,int dem)
{
    if (dem>k) return;
    if (i==n+1)
    {
        res++;
        return;
    }
    if (s[i]!='?')
    {
        hashs[i]=(hashs[i-1]*base+(s[i]=='4'?1:2))%mod;
        int cnt=0;
        for (int j=1; j<=i; j++)
        {
            int tmp=get(j,i);
            if (dd[tmp]) continue;
            e[i].push_back(tmp);
            dd[tmp]=1;
            cnt++;
        }
        dfs(i+1,dem+cnt);
        for (int j=0; j<(int)e[i].size(); j++)
            dd[e[i][j]]=0;
    }
    if (s[i]=='?')
    {
        hashs[i]=(hashs[i-1]*base+1)%mod;
        int cnt=0;
        e[i].clear();
        for (int j=1; j<=i; j++)
        {
            int tmp=get(j,i);
            if (dd[tmp]) continue;
            e[i].push_back(tmp);
            dd[tmp]=1;
            cnt++;
        }
        dfs(i+1,dem+cnt);
        for (int j=0; j<(int)e[i].size(); j++)
            dd[e[i][j]]=0;
        e[i].clear();
        hashs[i]=(hashs[i-1]*base+2)%mod;
        cnt=0;
        for (int j=1; j<=i; j++)
        {
            int tmp=get(j,i);
            if (dd[tmp]) continue;
            e[i].push_back(tmp);
            dd[tmp]=1;
            cnt++;
        }
        dfs(i+1,dem+cnt);
        for (int j=0; j<(int)e[i].size(); j++)
            dd[e[i][j]]=0;
    }
}
int main()
{
    freopen("LUCKFILL.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    power[0]=1;
    for (int i=1;i<=100;i++)
        power[i]=(power[i-1]*2)%mod;
    cin>>test;
    while(test--)
    {
        res=0;
        cin>>n>>k;
        cin>>(s+1);
        dfs(1,0);
        cout<<res<<"\n";
    }
    return 0;
}
