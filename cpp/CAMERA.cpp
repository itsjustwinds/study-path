#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,le[maxn],ri[maxn];
char S[maxn];
stack<int > s;
int main()
{
    freopen("CAMERA.inp","r",stdin);
    freopen("CAMERA.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        le[i]=s.size();
        while(!s.empty()&&a[s.top()]<a[i]) s.pop();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for (int i=n;i>=1;--i)
    {
        ri[i]=s.size();
        while(!s.empty()&&a[s.top()]<a[i]) s.pop();
        s.push(i);
    }
    cin>>(S+1);
    for (int i=1;i<=n;++i)
    {
        if (S[i]=='E') cout<<ri[i]<<" ";
        else cout<<le[i]<<" ";
    }
    return 0;
}
