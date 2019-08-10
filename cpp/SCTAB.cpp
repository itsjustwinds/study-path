#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
typedef vector<vector<int> > tab;
map<tab,int > M;
tab a,b;
int n,m,s,k;
bool cmp1(vector<int> a,vector<int> b)
{
        return a[1]<b[1];
}
bool cmp2(vector<int> a,vector<int> b)
{
        return a[2]<b[2];
}
bool cmp3(vector<int> a,vector<int> b)
{
        return a[3]<b[3];
}
bool cmp4(vector<int> a,vector<int> b)
{
        return a[4]<b[4];
}
bool cmp5(vector<int> a,vector<int> b)
{
        return a[5]<b[5];
}
bool cmp6(vector<int> a,vector<int> b)
{
        return a[6]<b[6];
}
bool cmp7(vector<int> a,vector<int> b)
{
        return a[7]<b[7];
}
bool cmp8(vector<int> a,vector<int> b)
{
        return a[8]<b[8];
}
bool cmp9(vector<int> a,vector<int> b)
{
        return a[9]<b[9];
}
bool cmp10(vector<int> a,vector<int> b)
{
        return a[10]<b[10];
}
bool cmp11(vector<int> a,vector<int> b)
{
        return a[11]<b[11];
}
bool cmp12(vector<int> a,vector<int> b)
{
        return a[12]<b[12];
}
bool cmp13(vector<int> a,vector<int> b)
{
        return a[13]<b[13];
}
bool cmp14(vector<int> a,vector<int> b)
{
        return a[14]<b[14];
}
bool cmp15(vector<int> a,vector<int> b)
{
        return a[15]<b[15];
}
bool cmp16(vector<int> a,vector<int> b)
{
        return a[16]<b[16];
}
bool cmp17(vector<int> a,vector<int> b)
{
        return a[17]<b[17];
}
bool cmp18(vector<int> a,vector<int> b)
{
        return a[18]<b[18];
}
bool cmp19(vector<int> a,vector<int> b)
{
        return a[19]<b[19];
}
bool cmp20(vector<int> a,vector<int> b)
{
        return a[20]<b[20];
}
typedef pair<tab,vector<int > >II;
vector<int> zero;
void bfs()
{
        M[a]=1;
        queue<II> q;
        while(!q.empty()) q.pop();
        q.push(II(a,zero));
        while(!q.empty())
        {
                tab u=q.front().fs;
                vector<int >tmp=q.front().sc;
                q.pop();
                for (int x=1; x<=n; ++x)
                {
                        tab c=a;
                        vector<int >t=tmp;
                if (x==1) sort(c.begin()+1,c.end(),cmp1);
                if (x==2) sort(c.begin()+1,c.end(),cmp2);
                if (x==3) sort(c.begin()+1,c.end(),cmp3);
                if (x==4) sort(c.begin()+1,c.end(),cmp4);
                if (x==5) sort(c.begin()+1,c.end(),cmp5);
                if (x==6) sort(c.begin()+1,c.end(),cmp6);
                if (x==7) sort(c.begin()+1,c.end(),cmp7);
                if (x==8) sort(c.begin()+1,c.end(),cmp8);
                if (x==9) sort(c.begin()+1,c.end(),cmp9);
                if (x==10) sort(c.begin()+1,c.end(),cmp10);
                if (x==11) sort(c.begin()+1,c.end(),cmp11);
                if (x==12) sort(c.begin()+1,c.end(),cmp12);
                if (x==13) sort(c.begin()+1,c.end(),cmp13);
                if (x==14) sort(c.begin()+1,c.end(),cmp14);
                if (x==15) sort(c.begin()+1,c.end(),cmp15);
                if (x==16) sort(c.begin()+1,c.end(),cmp16);
                if (x==17) sort(c.begin()+1,c.end(),cmp17);
                if (x==18) sort(c.begin()+1,c.end(),cmp18);
                if (x==19) sort(c.begin()+1,c.end(),cmp19);
                if (x==20) sort(c.begin()+1,c.end(),cmp20);
                        if (M[c]==1) continue;
                        M[c]=1;
                        t.push_back(x);
                        if (c==b)
                        {
                                cout<<t.size()<<"\n";
                                for (int i=0;i<t.size();++i)
                                        cout<<t[i]<<" ";
                                return;
                        }
                        q.push(II(c,t));
                }
        }
}
int main()
{
        freopen("SCTAB.inp","r",stdin);
        //freopen("SCTAB.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>k;
        a.resize(n+1);
        for (int i=1; i<=n; ++i)
                a[i].resize(m+1);
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        cin>>a[i][j];
        b=a;
        for (int i=1; i<=k; ++i)
        {
                int x;
                cin>>x;
                if (x==1) sort(b.begin()+1,b.end(),cmp1);
                if (x==2) sort(b.begin()+1,b.end(),cmp2);
                if (x==3) sort(b.begin()+1,b.end(),cmp3);
                if (x==4) sort(b.begin()+1,b.end(),cmp4);
                if (x==5) sort(b.begin()+1,b.end(),cmp5);
                if (x==6) sort(b.begin()+1,b.end(),cmp6);
                if (x==7) sort(b.begin()+1,b.end(),cmp7);
                if (x==8) sort(b.begin()+1,b.end(),cmp8);
                if (x==9) sort(b.begin()+1,b.end(),cmp9);
                if (x==10) sort(b.begin()+1,b.end(),cmp10);
                if (x==11) sort(b.begin()+1,b.end(),cmp11);
                if (x==12) sort(b.begin()+1,b.end(),cmp12);
                if (x==13) sort(b.begin()+1,b.end(),cmp13);
                if (x==14) sort(b.begin()+1,b.end(),cmp14);
                if (x==15) sort(b.begin()+1,b.end(),cmp15);
                if (x==16) sort(b.begin()+1,b.end(),cmp16);
                if (x==17) sort(b.begin()+1,b.end(),cmp17);
                if (x==18) sort(b.begin()+1,b.end(),cmp18);
                if (x==19) sort(b.begin()+1,b.end(),cmp19);
                if (x==20) sort(b.begin()+1,b.end(),cmp20);
        }
        if (a==b)
        {
                cout<<0;
                return 0;
        }
        bfs();
}
