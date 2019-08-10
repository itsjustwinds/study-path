#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
int test,n;
string res,beg;
map <string,int > m1,m2;
map <string,int > ::iterator it;
typedef pair<string,int >II;
string change(string u,int i,int j,int k)
{
        string v;
        v.clear();
        for (int h=i; h<=j; ++h)
                v=v+u[h];
        for (int h=k; h>=0; --h)
        {
                if (h>=i&&h<=j)continue;
                v=u[h]+v;
        }
        for (int h=k+1; h<n; ++h)
        {
                if (h>=i&&h<=j) continue;
                v=v+u[h];
        }
        return v;
}
void bfs()
{
        m1.clear();
        m2.clear();
        int ans=10;
        queue<II> q1,q2;
        while(!q1.empty())q1.pop();
        while(!q2.empty())q2.pop();
        if (beg==res)
        {
                cout<<"0\n";
                return;
        }
        m2[res]=0;
        q2.push(II(res,0));
        while(!q2.empty())
        {
                string u=q2.front().fs;
                int dtmp=q2.front().sc;
                q2.pop();
                if (dtmp>=2) break;
                for (int i=1; i<=n; ++i)
                        for (int j=i; j<=n; ++j)
                                for (int k=1; k<=n; ++k)
                                {
                                        if (k>=i&&k<=j) continue;
                                        string v=change(u,i-1,j-1,k-1);
                                        //cout<<u<<" "<<v<<" "<<dtmp<<"\n";
                                        it=m2.find(v);
                                        if (it!=m2.end()) continue;
                                        m2[v]=dtmp+1;
                                        q2.push(II(v,dtmp+1));
                                }
        }
        m1[beg]=0;
        q1.push(II(beg,0));
        while(!q1.empty())
        {
                string u=q1.front().fs;
                int dtmp=q1.front().sc;
                q1.pop();
                if (dtmp>=2) break;
                it=m2.find(u);
                if (it!=m2.end())
                {
                        int x=it->sc;
                        ans=min(ans,dtmp+x);
                }
                for (int i=1; i<=n; ++i)
                        for (int j=i; j<=n; ++j)
                                for (int k=1; k<=n; ++k)
                                {
                                        if (k>=i&&k<=j) continue;
                                        string v=change(u,i-1,j-1,k-1);
                                        it=m1.find(v);
                                        if (it!=m1.end()) continue;
                                        m1[v]=dtmp+1;
                                        q1.push(II(v,dtmp+1));
                                        it=m2.find(v);
                                        if (it!=m2.end())
                                        {
                                                int x=it->sc;
                                                ans=min(ans,dtmp+1+x);
                                        }
                                }
        }
        if (ans!=10)cout<<ans<<"\n";
        else cout<<"5 or more\n";
}
int main()
{
        freopen("VO17SORT.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>test;
        while(test--)
        {
                cin>>n;
                res.clear();
                beg.clear();
                for (int i=1; i<=n; ++i)
                {
                        int x;
                        cin>>x;
                        beg=beg+(char)(x+'A'-1);
                }
                for (int i=1; i<=n; ++i)
                        res=res+(char)(i+'A'-1);
                bfs();
        }
}
