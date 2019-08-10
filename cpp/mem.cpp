#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
int dd[maxn],n,ok;
priority_queue <int,vector<int>,greater<int> > q;
int main()
{
    freopen("mem.inp","r",stdin);
    //freopen("mem.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<=maxn;i++)
        q.push(i);
    for (int i=1;i<=n;i++)
    {
        char s[1000];
        cin>>s+1;
        if (s[1]=='?')
        {
            ok=0;
            int t;
            while (!ok)
            {
                t=q.top();
                q.pop();
                if (dd[t]==0) ok=1;
            }
            cout<<t<<"\n";
        }else
        {
            int t=0;
            for (int i=1;i<=strlen(s+1);i++)
                t=t*10+(s[i]-'0');
            if (t<=maxn)
            {
                dd[t]=1;
            }
        }
    }
    return 0;
}

