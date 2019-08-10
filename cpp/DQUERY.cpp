#include<bits/stdc++.h>
#define maxn 30005
using namespace std;
bitset<maxn> st[4*maxn],zero;
int a[maxn],n,pos[maxn];
vector<int > AC;
void build(int id,int l,int r){
        if (l==r){
                st[id].set(a[l]);
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=st[id*2]|st[id*2+1];
}
bitset<maxn> get(int id,int l,int r,int i,int j){
        if (l>j||r<i) return zero;
        if (l>=i&&r<=j){
                return st[id];
        }
        int m=(l+r)>>1;
        return get(id*2,l,m,i,j)|get(id*2+1,m+1,r,i,j);
}
int main(){
        freopen("DQUERY.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i) {
                cin>>a[i];
                AC.push_back(a[i]);
        }
        sort(AC.begin(),AC.end());
        unique(AC.begin(),AC.end());
        for (int i=1;i<=n;++i)
                a[i]=lower_bound(AC.begin(),AC.end(),a[i])-AC.begin()+1;
        build(1,1,n);
        int test;
        cin>>test;
        while(test--){
                int u,v;
                cin>>u>>v;
                bitset<maxn> tmp=get(1,1,n,u,v);
                cout<<tmp.count()<<"\n";
        }
}