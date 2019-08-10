#include<bits/stdc++.h>
#define maxn 10005
#define ll long long
using namespace std;
int b[maxn],n,k,a[maxn];
ll f[maxn],summax,summin;
struct cmp1
{
        bool operator ()(int a,int b)
        {
                return a>b;
        }
};

struct cmp2
{
        bool operator ()(int a,int b)
        {
                return a<b;
        }
};
priority_queue<int,vector<int>,cmp1 > qmin;
priority_queue<int,vector<int>,cmp2 > qmax;
void push(int x)
{
        if (qmin.size()==0)
        {
                qmin.push(x);
                summin+=x;
                return;
        }
        if (qmax.size()<qmin.size())
        {
                if (x<=qmin.top())
                {
                        qmax.push(x);
                        summax+=x;
                }
                else
                {
                        int tmp=qmin.top();
                        qmin.pop();
                        qmin.push(x);
                        qmax.push(tmp);
                        summin-=tmp;
                        summin+=x;
                        summax+=tmp;
                }
                return;
        }
        if (x<qmax.top())
        {
                int tmp=qmax.top();
                qmax.pop();
                qmax.push(x);
                qmin.push(tmp);
                summin+=tmp;
                summax-=tmp;
                summax+=x;
        }
        else
        {
                qmin.push(x);
                summin+=x;
        }
}
int getM()
{
        return qmin.top();
}
int main()
{
        freopen("KKDD.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1; i<=n; ++i)
        {
                cin>>a[i];
                b[i]=a[i];
        }
        sort(b+1,b+n+1);
        for (int i=1; i<=n; ++i)
                f[i]=1e18;
        for (int i=k; i<=n; ++i)
        {
                while(!qmin.empty()) qmin.pop();
                while(!qmax.empty()) qmax.pop();
                summax=0;
                summin=0;
                for (int j=1; j<=2*k; ++j)
                {
                        if (j>i) break;
                        push(a[i-j+1]);
                        int X=getM();
                        if (j<k) continue;
                        if (i-j>0&&i-j<k) continue;
                        ll tmp=1ll*qmax.size()*X-summax;
                        tmp+=summin-1ll*qmin.size()*X;
                        f[i]=min(f[i],f[i-j]+tmp);
                }
        }
        cout<<f[n];
        return 0;
}
