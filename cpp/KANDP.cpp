#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
struct data
{
            int x1,y1,x2,y2,dem;
};
data s;
int res;
int dx[10],dy[10];
int dd[3*maxn][3*maxn];
void bfs()
{
            queue<data> q;
            while(!q.empty()) q.pop();
            q.push(s);
            while(!q.empty())
            {
                        data u=q.front();q.pop();
                        for (int i=1; i<=8; ++i)
                        {
                                    data v;
                                    v.x1=u.x1+dx[i];v.y1=u.y1+dy[i];v.x2=u.x2+1;v.y2=u.y2;v.dem=u.dem+1;
                                    if (v. x1==u.x2&&v.y1==u.y2){
                                                res=u.dem+1;
                                                return;
                                    }
                                    if (maxn+v.x1-v.x2<0||maxn+v.x1-v.x2>=2*maxn||maxn+v.y1-v.y2<0||maxn+v.y1-v.y2>=2*maxn||dd[maxn+v.x1-v.x2][maxn+v.y1-v.y2]) continue;
                                    dd[maxn+v.x1-v.x2][maxn-v.y1-v.y2]=1;
                                    q.push(v);
                        }
            }
}
int main()
{
            freopen("KANDP.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            dx[1]=-2;dy[1]=1;
            dx[2]=-1;dy[2]=2;
            dx[3]=1;dy[3]=2;
            dx[4]=2;dy[4]=1;
            dx[5]=2;dy[5]=-1;
            dx[6]=1;dy[6]=-2;
            dx[7]=-1;dy[7]=-2;
            dx[8]=-2;dy[8]=-1;
            cin>>s.x1>>s.y1;
            cin>>s.x2>>s.y2;
            int tt;
            cin>>tt;
            s.x2+=tt;
            dd[maxn+s.x1-s.x2][maxn+s.y1-s.y2]=1;
            if (s.x1==s.x2&&s.y1==s.y2)
            {
                        if (!tt)
                        {
                                    cout<<"YES\n";
                                    cout<<0;
                                    return 0;
                        }
                        else
                        {
                                    cout<<"NO";
                                    return 0;
                        }
            }
            bfs();
            if(res)
            {
                        cout<<"YES\n";
                        cout<<res;
                        return 0;
            }
            cout<<"NO";
            return 0;
}

