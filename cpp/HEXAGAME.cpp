#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
string s,e;
int res,cnt1,cnt2,ok;
typedef pair<string,int > II;
struct trie
{
        int child[20];
        int fi;
};
trie m1[1000005],m2[1000005];
queue<II> q1,q2;
void insert1(string a,int sk)
{
        int now=1;
        for (int i=0; i<(int)a.length(); ++i)
        {
                int k=a[i]-'0';
                if (!m1[now].child[k]) m1[now].child[k]=++cnt1;
                now=m1[now].child[k];
        }
        m1[now].fi=sk;
}
void insert2(string a,int sk)
{
        int now=1;
        for (int i=0; i<(int)a.length(); ++i)
        {
                int k=a[i]-'0';
                if (!m2[now].child[k]) m2[now].child[k]=++cnt2;
                now=m2[now].child[k];
        }
        m2[now].fi=sk;
}
int check1(string a)
{
        int now=1;
        for (int i=0; i<(int)a.length(); ++i)
        {
                int k=a[i]-'0';
                if (m1[now].child[k]==0) return 0;
                now=m1[now].child[k];
        }
        return m1[now].fi;
}
int check2(string a)
{
        int now=1;
        for (int i=0; i<(int)a.length(); ++i)
        {
                int k=a[i]-'0';
                if (m2[now].child[k]==0) return 0;
                now=m2[now].child[k];
        }
        return m2[now].fi;
}
string changes(int x,string a)
{
        string res;
        res="";
        if (x==1)
        {
                res=res+a[3];
                res=res+a[0];
                res=res+a[2];
                res=res+a[7];
                res=res+a[4];
                res=res+a[1];
                res=res+a[6];
                res=res+a[8];
                res=res+a[5];
                res=res+a[9];
        }
        else if (x==2)
        {
                res=res+a[0];
                res=res+a[4];
                res=res+a[1];
                res=res+a[3];
                res=res+a[8];
                res=res+a[5];
                res=res+a[2];
                res=res+a[7];
                res=res+a[9];
                res=res+a[6];
        }
        else if (x==3)
        {
                res=res+a[1];
                res=res+a[5];
                res=res+a[2];
                res=res+a[0];
                res=res+a[4];
                res=res+a[8];
                res=res+a[6];
                res=res+a[3];
                res=res+a[7];
                res=res+a[9];
        }
        else
        {
                res=res+a[0];
                res=res+a[2];
                res=res+a[6];
                res=res+a[3];
                res=res+a[1];
                res=res+a[5];
                res=res+a[9];
                res=res+a[7];
                res=res+a[4];
                res=res+a[8];
        }
        return res;
}
void bfs2(int best)
{
        while(!q2.empty())
        {
                II u=q2.front();
                if (u.sc>best) return;
                q2.pop();
                for (int i=3; i<=4; ++i)
                {
                        II v=II(changes(i,u.fs),u.sc+1);
                        if (check2(v.fs)) continue;
                        if (v.sc==14) cout<<v.fs<<"\n";
                        int kq=check1(v.fs);
                        if (kq)
                        {
                                ok=1;
                                res=kq+v.sc;
                                return;
                        }
                        q2.push(v);
                        insert2(v.fs,v.sc);
                }
        }
}
void bfs()
{
        int now=0;
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        q1.push(II(s,0));
        q2.push(II(e,0));
        bfs2(0);
        while(!q1.empty())
        {
                if (ok) return;
                II u=q1.front();
                q1.pop();
                if (u.sc!=now)
                {
                        now=u.sc;
                        bfs2(now);
                }
                if (ok) return;
                for (int i=1; i<=2; ++i)
                {
                        II v=II(changes(i,u.fs),u.sc+1);
                        if (check1(v.fs)) continue;
                        int kq=check2(v.fs);
                        if (kq)
                        {
                                ok=1;
                                res=v.sc+kq;
                                //cout<<v.sc<<" "<<kq<<"\n";
                                return;
                        }
                        if (ok) return;
                        q1.push(v);
                        insert1(v.fs,v.sc);
                }
        }
}
int main()
{
        freopen("HEXAGAME.inp","r",stdin);
        //freopen("HEXAGAME.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        for (int i=1; i<=10; ++i)
        {
                int x;
                cin>>x;
                s=s+char(x+'0');
        }
        cnt1=1;
        cnt2=1;
        e="1238004765";
        if (s==e)
        {
                cout<<0;
                return 0;
        }
        insert1(s,0);
        insert2(e,0);
        bfs();
        cout<<res;
        return 0;
}
/*
 0 5 2
7 1 6 3
 8 4 0
*/
//18
