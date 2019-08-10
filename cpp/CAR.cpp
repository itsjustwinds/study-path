#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
struct data
{
        int a,pos,b;
        double x;
};
data a[maxn];
int n;
long long res;
vector<int >ans;
bool cmp(data a,data b)
{
        if (a.x!=b.x)return a.x>b.x;
        return a.a<b.a;
}
int main()
{
      freopen("CAR.inp","r",stdin);
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      cin>>n;
      for (int i=1;i<=n;++i)
                cin>>a[i].a;
      for (int i=1;i<=n;++i)
                cin>>a[i].b;
      for (int i=1;i<=n;++i)
      {
        a[i].x=(double)a[i].a/a[i].b;
        a[i].pos=i;
      }
      sort(a+1,a+n+1,cmp);
      int now=0;
      for (int i=1;i<=n;++i)
      {
              now+=a[i].b;
              res+=1ll*a[i].a*now;
              ans.push_back(a[i].pos);
      }
      cout<<res<<"\n";
      for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
      return 0;
}
