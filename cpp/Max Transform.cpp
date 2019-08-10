#include<bits/stdc++.h>
#define maxn 200005
#define mod 1000000007
using namespace std;
int ttt[maxn],n,MAX[maxn];
long long res;
vector<int > a,le,ri;
deque<int > q;
int main()
{
    freopen("Max Transform.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>ttt[i];
    for (int k=0;k<n;++k)
        for (int i=0;i<n-k;++i)
    {
        int j=i+k;
        MAX[i]=max(MAX[i],ttt[j]);
        a.push_back(MAX[i]);
    }
    le.resize(a.size());
    ri.resize(a.size());
    q.push_back(-1);
    for (int i=0;i<a.size();++i)
    {
        while(q.size()>1&&a[i]>=a[q.back()]) q.pop_back();
        le[i]=q.back()+1;
        res=(res+1ll*(i-le[i]+1)*a[i])%mod;
        q.push_back(i);
    }
    while(!q.empty()) q.pop_back();
    q.push_back(a.size());
    for (int i=a.size()-1;i>=0;--i)
    {
        while(q.size()>1&&a[i]>a[q.back()]) q.pop_back();
        ri[i]=q.back()-1;
        res=(res+1ll*(i-le[i]+1)*(ri[i]-i)*a[i])%mod;
        q.push_back(i);
    }
    cout<<res;
}
