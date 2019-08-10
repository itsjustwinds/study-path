#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int a[maxn],n,dd[maxn],dd2[maxn];
typedef pair<int,int> II;
int main()
{
    //freopen("POWERFULARRAY.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>n>>test;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    while(test)
    {
        int x,y;
        ll res=0;
        cin>>x>>y;
        vector<int> q;
        q.clear();
        for (int i=x; i<=y; i++)
        {
            if (dd2[a[i]]==test)
            {
                dd[a[i]]++;
            }
            else
            {
                dd2[a[i]]=test;
                q.push_back(a[i]);
                dd[a[i]]=1;
            }
        }
        for (int i=0; i<(int)q.size(); i++)
        {
            res+=(ll)dd[q[i]]*dd[q[i]]*q[i];
        }
        cout<<res<<"\n";
        test--;
    }
}
