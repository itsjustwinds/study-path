#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;
int Hy,Ay,Dy,Hm,Am,Dm,Ch,Ca,Cd,res;
bool check(int i,int j,int k)
{
        if (j-Dm<=0) return 0;;
        if (Am-k<=0) return 1;
        int t2=Hm/max(0,j-Dm)+(Hm%max(0,j-Dm)!=0);
        int t1=i/max(0,Am-k)+(i%max(0,Am-k)!=0);
        return t1>t2;
}
int main()
{
        freopen("488C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>Hy>>Ay>>Dy;
        cin>>Hm>>Am>>Dm;
        cin>>Ch>>Ca>>Cd;
        res=1e9+7;
        for (int i=Hy; i<=2005; ++i)
                for (int j=Ay; j<=205; ++j)
                        for (int k=Dy; k<=205; ++k)
                                if (check(i,j,k))
                                {
                                        res=min(res,(i-Hy)*Ch+(j-Ay)*Ca+(k-Dy)*Cd);
                                }
        cout<<res;
}
