#include<bits/stdc++.h>
#define maxn 10005
#define fs first
#define sc second
#include <fstream>
using namespace std;
ifstream fi("multiple.inp");
ofstream fo("multiple.out");
int n,dd[maxn];
typedef pair<int,string> II;
string f[maxn];
void bfs()
{
    queue <II> q;
    q.push(II(1%n,"1"));
    while(!q.empty())
    {
        II t=q.front();
        q.pop();
        for (int i=0; i<=1; i++)
        {
            II tmp=II((t.fs*10+i)%n,t.sc+char(i+48));
            if (tmp.fs==0)
            {
                fo<<tmp.sc<<"\n";
                return ;
            }
            if (dd[tmp.fs]==0)
            {
                q.push(tmp);
                dd[tmp.fs]=1;
            }
        }
    }
}
int main()
{
    //freopen("multiple.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(fi>>n)
    {
        if (n==0)
        {
            fi.close();
            return 0;
        }
        bfs();
    }
    fi.close();
    return 0;
}
