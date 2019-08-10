#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define mod 1000000003
using namespace std;
int n,m,base[3];
int power[maxn][3];
struct data{
    int val[3];
};
data hashT[maxn],hashS[maxn];
char s[maxn],t[maxn];
data getT(int l,int r)
{
    data ans;
    for (int i=0;i<=2;i++)
    {
        int tmp=((ll)hashT[r].val[i]-((ll)hashT[l-1].val[i]*power[r-l+1][i])%mod+mod)%mod;
        ans.val[i]=tmp;
    }
    return ans;
}
data getS(int l,int r)
{
    data ans;
    for (int i=0;i<=2;i++)
    {
        int tmp=((ll)hashS[r].val[i]-((ll)hashS[l-1].val[i]*power[r-l+1][i])%mod+mod)%mod;
        ans.val[i]=tmp;
    }
    return ans;
}
bool ss(data tmp1,data tmp2)
{
    for (int i=0;i<=2;i++)
        if (tmp1.val[i]!=tmp2.val[i]) return 0;
    return 1;
}
bool check(int l,int r,int u,int v)
{
    data tmp1=getS(l,r);
    data tmp2=getT(u,v);
    for (int i=0;i<=2;i++)
    if (ss(tmp1,tmp2)) return 1;
    return 0;
}
int main()
{
    freopen("VOSTR.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    base[0]=37;base[1]=91;base[2]=107;
    power[0][0]=1;power[0][1]=1;power[0][2]=1;
    for (int i=1;i<=max(n,m);i++)
    {
        for (int j=0;j<=2;j++)
            power[i][j]=((ll)power[i-1][j]*base[j])%mod;
    }
    cin>>n>>m;
    cin>>(s+1);
    cin>>(t+1);
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=2;j++)
            hashS[i].val[j]=((ll)hashS[i-1].val[j]*base[j]+s[i]-'a')%mod;
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=0;j<=2;j++)
            hashT[i].val[j]=((ll)hashT[i-1].val[j]*base[j]+t[i]-'a')%mod;
    }
    int i_love_u;
    cin>>i_love_u;
    while(i_love_u--)
    {
        int l,r,u,v;
        cin>>l>>r>>u>>v;
        data tmp1=getS(l,r);
        data tmp2=getT(u,v);
        if (r-l+1==v-u+1&&ss(tmp1,tmp2))
        {
            cout<<"=";
            continue;
        }
        int pos=maxn;
        int le=1,ri=min(r-l+1,v-u+1);
        while(le<=ri)
        {
            int m=(le+ri)/2;
            if (!check(l,l+m-1,u,u+m-1))
            {
                pos=m;
                ri=m-1;
            }
            else le=m+1;
        }
        if (pos!=maxn)
        {
            if (s[l+pos-1]>t[u+pos-1]) cout<<">";
            else cout<<"<";
            continue;
        }
        if (r-l+1>v-u+1) cout<<">";
        else cout<<"<";
    }
    return 0;
}
