#include<bits/stdc++.h>
#define db double
#define maxn 1005
using namespace std;
int n,r;
db esp;
struct data{
    db x,y;
};
data a[maxn];
db dist(data a,data b){
    db X=a.x-b.x;
    db Y=a.y-b.y;
    return sqrt(X*X+Y*Y);
}
int main(){
    freopen("908C.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>r;
    esp=1e-7;
    for (int i=1;i<=n;++i)
        cin>>a[i].x;
    for (int i=1;i<=n;++i){
        a[i].y=r;
        for (int j=1;j<i;++j){
            if (abs(a[i].x-a[j].x)>2*r) continue;
            db tmp=a[j].y;
            db le=a[j].y;
            db ri=1e7;
            while(ri-le>esp){
                db m=(le+ri)/2;
                db d=dist(a[j],{a[i].x,m});
                if (d>2*r) {
                    tmp=m;
                    ri=m;
                }
                else le=m;
            }
            a[i].y=max(a[i].y,tmp);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<setprecision(7)<<fixed<<a[i].y<<" ";
}
