#include<bits/stdc++.h>
using namespace std;
int n,m;
set<int> a,b,res1,res2;
int main()
{
    //freopen("oop.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        cout<<x<<" ";
        a.insert(x);
    }
    cout<<"\n";
    cin>>m;
    for (int j=1; j<=m; j++)
    {
        int x;
        cin>>x;
        cout<<x<<" ";
        b.insert(x);
    }
    cout<<"\n";
    for (int i=1; i<=n; i++)
    {
        int k=*a.begin();
        a.erase(k);
        int tmp=b.size();
        b.erase(k);
        if (int(b.size())!=tmp) res1.insert(k);
        res2.insert(k);
    }
    while(!b.empty())
    {
        int k=*b.begin();
        b.erase(k);
        res2.insert(k);
    }
    if (res1.empty()) cout<<"0"<<"\n";
    else
    {
        while(!res1.empty())
        {
            int k=*res1.begin();
            res1.erase(k);
            cout<<k<<" ";
        }
        cout<<"\n";
    }
    if (res2.empty()) cout<<"0"<<"\n";
    else
        while(!res2.empty())
        {
            int k=*res2.begin();
            res2.erase(k);
            cout<<k<<" ";
        }
    return 0;
}
