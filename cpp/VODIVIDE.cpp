#include<bits/stdc++.h>
#define maxn 500005
#define fs first
#define sc second
using namespace std;
int n,dd[maxn],now;
long long res;
struct data
{
        int a,b,pos;
};
vector<data >ans;
data a[maxn];
bool cmp(data a,data b)
{
        return a.a<b.a;
}
typedef pair<int,int > II;
struct cmpx
{
        bool operator ()(II a,II b)
        {
                return a.fs<b.fs;
        }
};
stack<int > s;
priority_queue<II,vector<II>,cmpx > q;
int main()
{
        freopen("VODIVIDE.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i].a;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].b;
                a[i].pos=i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                q.push(II(a[i].b,i));
                if (i%2)
                {
                        int pos=q.top().sc;
                        int x=q.top().fs;
                        q.pop();
                        res+=x;
                        dd[pos]=1;
                        s.push(pos);
                }
        }
        cout<<res<<"\n";
        for (int i=n;i>=1;--i)
        if (!dd[i])
        {
                cout<<a[i].pos<<" "<<a[s.top()].pos<<"\n";
                s.pop();
        }
}
