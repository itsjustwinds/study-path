#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct data
{
        int x,y;
};
data X[5];
int n,tops,topn,bots,botn;
bool cmp(data a,data b)
{
        if (a.x!=b.x)return a.x<b.x;
        return a.y<b.y;
}
long long tinh(int k,int i,int j)
{
        i+=k;
        j+=k;
        if (i<0)i=i/2;
        else  i=(i+1)/2;
        j=j/2;
        return max(0,j-i+1);
}
int main()
{
        freopen("PINS.inp","r",stdin);
        //freopen("PINS.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        tops=2e9;
        bots=-2e9;
        topn=2e9;
        botn=-2e9;
        for (int i=1;i<=n;++i)
        {
                for (int j=1;j<=4;++j) cin>>X[j].x>>X[j].y;
                sort(X+1,X+4+1,cmp);
                if (X[2].y>X[3].y) swap(X[2],X[3]);
                swap(X[3],X[4]);
                //x-y=C
                int C1=X[1].x-X[1].y;
                int C2=X[3].x-X[3].y;
                topn=min(topn,max(C1,C2));
                botn=max(botn,min(C1,C2));

                //X+y=C
                C1=X[1].x+X[1].y;
                C2=X[3].x+X[3].y;
                tops=min(tops,max(C1,C2));
                bots=max(bots,min(C1,C2));
        }
        botn++;topn--;
        bots++;tops--;
        //botn<=x-y<=topn
        //bots<=x+y<=tops
        long long res=0;
        for (int i=-1e3;i<=1e3;++i)
                for (int j=-1e3;j<=1e3;++j)
                if (i+j<=tops&&i+j>=bots&&i-j<=topn&&i-j>=botn) ++res;
        cout<<res;
        return 0;
        for (int k=botn;k<=topn;++k)
        {
                res+=tinh(k,bots,tops);
        }
        cout<<res;
}
