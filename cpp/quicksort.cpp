#include <bits/stdc++.h>
using namespace std;
int a[1000],n;
void qsort(int l,int r){
    int u=l;
    int v=r;
    //srand(time(NULL));
    int x = a[l+rand()%(r-l+1)];
    //int x=a[(l+r)/2];
    while (u<=v)
    {
        while (a[u]<x) u++;
        while (a[v]>x) v--;
        if (u<=v)
        {
            int t=a[u];
            a[u]=a[v];a[v]=t;
            u++;v--;
        }
    }
    if (l<v) qsort(l,v);
    if (u<r) qsort(u,r);
}
int main(){
    freopen("quicksort.inp","r",stdin);
    freopen("quicksort.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    qsort(1,n);
    for (int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}
