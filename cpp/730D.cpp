#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int n;
ll res,r,l[maxn],t[maxn],Tnow;
vector<int >ans;
int main() {
    freopen("730D.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>r;
    for (int i=1; i<=n; ++i)
        cin>>l[i];
    for (int i=1; i<=n; ++i) {
        cin>>t[i];
        if (t[i]<l[i]) {
            cout<<-1;
            return 0;
        }
    }
    ll Left=0;
    int D=0;
    for (int i=1; i<=n; ++i) {
        ll tmp=min(l[i],Left);
        l[i]-=tmp;
        Left-=tmp;
        t[i]-=tmp;
        Tnow+=tmp;
        if (l[i]==0) continue;
        tmp=2*l[i];
        if (tmp<=t[i]) {
            Tnow+=tmp;
            continue;
        }
        tmp=tmp-t[i];
        ll Time;
        if(tmp%r) Time=tmp/r+1;
        else Time=tmp/r;
        int ok=0;
        ll TMP=tmp;
        if (D+Time<=1e5) {
            ok=1;
            while(tmp>0) {
                ans.push_back(Tnow);
                Tnow+=r;
                tmp-=r;
            }
            Tnow+=tmp;
            D+=Time;
        }
        if (!ok) {
            if (tmp%r)Tnow+=r*(Time-1)+tmp%r;
            else Tnow+=r*Time;
        }
        res+=Time;
        Left=r-TMP%r;
        Tnow+=t[i];
    }
    cout<<res<<"\n";
    for (int i=0; i<ans.size(); ++i)
        cout<<ans[i]<<" ";
}
