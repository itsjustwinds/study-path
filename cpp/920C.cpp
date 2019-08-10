#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,a[maxn],sum[maxn],bit[maxn],Min,allowed[maxn];
int get(int x){
    int res=0;
    while(x){
        res=max(res,bit[x]);
        x-=x&(-x);
    }
    return res;
}
void update(int x,int val){
    while(x<maxn){
        bit[x]=max(bit[x],val);
        x+=x&(-x);
    }
}
int main(){
    //freopen("920C.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i){
        char s;
        cin>>s;
        if (s=='1') allowed[i]=1;
    }
    for (int i=1;i<=n;++i){
        sum[i]=sum[i-1];
        if (allowed[i]) sum[i]++;
    }
    Min=a[n];
    update(a[n],n);
    for (int i=n-1;i>=1;--i){
        if (a[i]<=Min) {
                Min=a[i];
                update(a[i],i);
                continue;
        }
        int Last=get(a[i]-1);
        int tmp=sum[n]-sum[i-1]-(sum[n]-sum[Last-1]);
        if (tmp<Last-i){
            cout<<"NO";
            return 0;
        }
        update(a[i],i);
    }
    cout<<"YES";
    return 0;
}
