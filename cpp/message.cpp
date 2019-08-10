#include<bits/stdc++.h>
#define maxn 1000
#define ll long long
using namespace std;
ll n,m,len,res,dm[maxn],tmp,power[maxn];
vector<char> e;
string s;
void dfs(int i,string pre,ll sum)
{
    if (pre==s)
    {
        res=(res+sum*power[n-i+1])%m;
        return;
    }
    if (i>n) return;
    dfs(i+1,"",(sum*tmp)%m);
    for (int j=0;j<(int)e.size();j++)
    {
        if (pre.length()<len) dfs(i+1,pre+e[j],sum);
        else
        {
            string k=pre;
            k.erase(0,1);
            k=k+e[j];
            dfs(i+1,k,sum);
        }
    }
}
int main()
{
    freopen("message.inp","r",stdin);
    //freopen("message.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    power[0]=1;
    while(test--)
    {
        res=0;
        tmp=26;
        cin>>n>>m;
        for (int i=1;i<=n;i++)
        power[i]=(power[i-1]*26)%m;
        cin>>s;
        len=s.length();
        e.clear();
        for (int i=0;i<=26;i++)
            dm[i]=0;
        for (int i=0;i<len;i++)
            if (!dm[s[i]-'a'])
        {
            dm[s[i]-'a']=1;
            e.push_back(s[i]);
            tmp--;
        }
        dfs(1,"",1);
        cout<<res<<"\n";
    }
}
