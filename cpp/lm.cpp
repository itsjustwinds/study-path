#include<bits/stdc++.h>
#define maxn 1000005
#define fs first
#define ll long long
#define sc second
using namespace std;
char s[15];
int n,dd[maxn],th[15],dem;
typedef pair<int,string> II;
void bfs()
{
    queue<II> q;
    for (int i=1;i<=dem;i++)
    {
        if (th[i]==0) continue;
        if (th[i]%n ==0)
        {
            cout<<th[i];
            return;
        }
        string k="";
        II tmp=II(th[i]%n,k+char(th[i]+'0'));
        q.push(tmp);
        dd[th[i]%n]=1;
    }
    while(!q.empty())
    {
        II tmp=q.front();
        q.pop();
        for (int i=1;i<=dem;i++)
        {
            int sum=((ll)tmp.fs*10+th[i])%n;
            if (dd[sum]) continue;
            dd[sum]=1;
            if (sum==0)
            {
                cout<<tmp.sc+char(th[i]+'0');
                return;
            }
            q.push(II(sum,tmp.sc+char(th[i]+'0')));
        }
    }
    cout<<0;
    return;

}
int main()
{
    freopen("lm.inp","r",stdin);
    //freopen("lm.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>(s+1);
    for (int i=1;i<=(int)strlen(s+1);i++)
        th[++dem]=s[i]-'0';
    sort(th+1,th+dem+1);
    bfs();
    return 0;
}
