#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
II s,t,trc[10][10],res[1000];
int dd[10][10],dem;
vector<II> e[10][10];
void bfs(II s)
{
    queue<II> q;
    int ok=0;
    if (s==t)
    {
        cout<<0<<" "<<char(s.fs+'A'-1)<<" "<<s.sc<<"\n";
        return;
    }
    while(!q.empty()) q.pop();
    dd[s.fs][s.sc]=1;
    q.push(s);
    while(!q.empty())
    {
        II u=q.front();
        q.pop();
        for (int i=0; i<(int)e[u.fs][u.sc].size(); i++)
        {
            II v=e[u.fs][u.sc][i];
            if (dd[v.fs][v.sc]) continue;
            dd[v.fs][v.sc]=1;
            trc[v.fs][v.sc]=II(u.fs,u.sc);
            if (v==t)
            {
                ok=1;
                break;
            }
            q.push(v);
        }
        if (ok) break;
    }
    if (!ok) cout<<"Impossible\n";
    else
    {
        dem=0;
        while(t!=s)
        {
            res[++dem]=t;
            t=trc[t.fs][t.sc];
        }
        res[++dem]=s;
        if (dem-1>4)
        {
            cout<<"Impossible\n";
            return;
        }
        cout<<dem-1<<" ";
        for (int i=dem; i>=1; i--)
        {
            cout<<char(res[i].fs+'A'-1)<<" "<<res[i].sc<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    //freopen("chess.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for (int i=1; i<=8; i++)
        for (int j=1; j<=8; j++)
        {
            int a=i,b=j;
            while(a>0&&a<9&&b>0&&b<9)
            {
                a-=1;
                b+=1;
                e[i][j].push_back(II(a,b));
            }
            a=i,b=j;
            while(a>0&&a<9&&b>0&&b<9)
            {
                a+=1;
                b+=1;
                e[i][j].push_back(II(a,b));
            }
            a=i,b=j;
            while(a>0&&a<9&&b>0&&b<9)
            {
                a+=1;
                b-=1;
                e[i][j].push_back(II(a,b));
            }
            a=i,b=j;
            while(a>0&&a<9&&b>0&&b<9)
            {
                a-=1;
                b-=1;
                e[i][j].push_back(II(a,b));
            }
        }
    while(test--)
    {
        char S;
        cin>>S>>s.sc;
        s.fs=(S-'A'+1);
        cin>>S>>t.sc;
        t.fs=(S-'A'+1);
        memset(dd,0,sizeof(dd));
        for (int i=1;i<=8;i++)
            for (int j=1;j<=8;j++)
            trc[i][j]=II(0,0);
        bfs(s);
    }
}
