#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;
int n,k,a[maxn],s[maxn],res[maxn],ok;
vector<int > e[maxn];
void back_tracking(int id,int mask,ll sum) {
    if (id==n+1) {
        if (mask==0) return;
        for (int i=1; i<=n; ++i)
            if (sum==s[i]) {
                e[i].push_back(mask);
            }
        return ;
    }
    back_tracking(id+1,mask,sum);
    back_tracking(id+1,mask|(1<<(id-1)),sum+a[id]);
}
void answer(int id,int mask) {
    if (id==k+1) {
        if (mask==(1<<n)-1)
            ok=1;
        return;
    }
    if (ok) return;
    for (int i=0; i<e[id].size(); ++i) {
        int MASK=e[id][i];
        if (mask&MASK) continue;
        answer(id+1,mask|MASK);
        if (ok) {
            for (int j=1; j<=n; ++j) {
                if (((MASK>>(j-1))&1)==0) continue;
                res[j]=id;
            }
            return;
        }
    }
}
int main() {
    freopen("KSUBSET2.inp","r",stdin);
    freopen("KSUBSET2.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=1; i<=k; ++i)
        cin>>s[i];
    back_tracking(1,0,0);
    answer(1,0);
    if (!ok) {
        cout<<"NO";
    } else {
        cout<<"YES\n";
        for (int i=1; i<=n; ++i)
            cout<<res[i]<<" ";
    }
}
