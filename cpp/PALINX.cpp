#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
struct data
{
        int base[2];
};
vector<data > F,B,power;
data base;
typedef map<data,ll> MAP;
vector<MAP > F1,F2,B1,B2;
vector<string >s;
ll res;
int maxx,sz,n;
bool operator <(const data &a,const data &b)
{
        if (a.base[0]!=b.base[0]) return a.base[0]<b.base[0];
        return a.base[1]<b.base[1];
}
data getF(int i,int j)
{
        data c;
        data a;
        if (i>0) a=F[i-1];
        else a={0,0};
        data b=F[j];
        data d=power[j-i+1];
        c.base[0]=(F[j].base[0]-((ll)a.base[0]*power[j-i+1].base[0])%mod+mod)%mod;
        c.base[1]=(F[j].base[1]-((ll)a.base[1]*power[j-i+1].base[1])%mod+mod)%mod;
        return c;
}
data getB(int i,int j)
{
        data c;
        data a;
        if (i>0) a=B[i-1];
        else a={0,0};
        c.base[0]=(B[j].base[0]-((ll)a.base[0]*power[j-i+1].base[0])%mod+mod)%mod;
        c.base[1]=(B[j].base[1]-((ll)a.base[1]*power[j-i+1].base[1])%mod+mod)%mod;
        return c;
}
bool operator ==(const data a,const data &b)
{
        return a.base[0]==b.base[0]&&a.base[1]==b.base[1];
}
bool pal(int i,int j)
{
        return (getF(i,j)==getB(sz-j-1,sz-i-1));
}
void go()
{
        F1[sz][getF(0,sz-1)]++;
        B1[sz][getB(0,sz-1)]++;
        for (int i=0;i<sz-1;++i)
        {
                //from F2 to B1
                if (pal(i+1,sz-1))
                {
                        res+=B1[i+1][getF(0,i)];
                        F2[i+1][getF(0,i)]++;
                }
                //from B2 to F1
                if (pal(0,i))
                {
                        res+=F1[sz-i-1][getB(0,sz-i-2)];
                        B2[sz-i-1][getB(0,sz-i-2)]++;
                }
        }
        //from F1 to B1
        res+=B1[sz][getF(0,sz-1)];
        //from F1 to B2
        res+=B2[sz][getF(0,sz-1)];
        //from B1 to F1
        res+=F1[sz][getB(0,sz-1)];
        //from B1 to F2
        res+=F2[sz][getB(0,sz-1)];
        if (pal(0,sz-1)) res--;
}
int main()
{
        freopen("D:\\c++\\PALINX.inp","r",stdin);
        freopen("D:\\c++\\PALINX.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        s.resize(n);
        for (int i=0;i<n;++i)
        {
                int x;
                cin>>x;
                cin>>s[i];
                maxx=max(maxx,x);
        }
        F1.resize(maxx+1);
        F2.resize(maxx+1);
        B1.resize(maxx+1);
        B2.resize(maxx+1);
        F.resize(maxx+1);
        B.resize(maxx+1);
        power.resize(maxx+1);
        base.base[0]=147;
        base.base[1]=97;
        power[0].base[0]=1;
        power[0].base[1]=1;
        for (int i=1;i<=maxx;++i)
        {
                power[i].base[0]=((ll)power[i-1].base[0]*base.base[0])%mod;
                power[i].base[1]=((ll)power[i-1].base[1]*base.base[1])%mod;
        }
        for (int i=0;i<n;++i)
        {
                sz=s[i].length();
                F[0].base[0]=s[i][0]-'a';
                F[0].base[1]=s[i][0]-'a';
                for (int j=1;j<sz;++j)
                {
                        F[j].base[0]=(((ll)F[j-1].base[0]*base.base[0])%mod+s[i][j]-'a')%mod;
                        F[j].base[1]=(((ll)F[j-1].base[1]*base.base[1])%mod+s[i][j]-'a')%mod;
                }
                B[0].base[0]=s[i][sz-1]-'a';
                B[0].base[1]=s[i][sz-1]-'a';
                for (int j=1;j<sz;++j)
                {
                        B[j].base[0]=(((ll)B[j-1].base[0]*base.base[0])%mod+s[i][sz-j-1]-'a')%mod;
                        B[j].base[1]=(((ll)B[j-1].base[1]*base.base[1])%mod+s[i][sz-j-1]-'a')%mod;
                }
                go();
        }
        cout<<res;
        return 0;
}
