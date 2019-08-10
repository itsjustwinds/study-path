#include<bits/stdc++.h>
#define maxn 10005
#define oo 1023
using namespace std;
int dd[maxn],xox[maxn],an[maxn],ror[maxn];
int a[500005];
char S[500005];
vector<int > xxor,andd,ord;
struct data
{
        int x;
        char s;
};
vector<data >res[maxn];
int n;
int main()
{
        //freopen("879C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                char s;
                int x;
                cin>>s>>x;
                a[i]=x;
                S[i]=s;
                if (s=='|')
                {
                        if (ror[x]) continue;
                        ror[x]=1;
                        ord.push_back(x);
                        continue;
                }
                if (s=='^')
                {
                        if (xox[x]) continue;
                        xox[x]=1;
                        xxor.push_back(x);
                        continue;
                }
                if (an[x]) continue;
                an[x]=1;
                andd.push_back(x);
        }
        for (int i=0;i<ord.size();++i)
        {
                dd[ord[i]]=1;
                res[ord[i]].push_back({ord[i],'|'});
        }
        if (dd[1])
        {
                cout<<1<<"\n";
                cout<<"| 1";
                return 0;
        }
        if (an[1]==1)
        {
                cout<<1<<"\n";
                cout<<"& 1";
                return 0;
        }
        for (int i=0;i<andd.size();++i)
        {
                int x=andd[i];
                for (int j=1;j<=oo;++j)
                if (dd[j])
                {
                        if (dd[j&x]) continue;
                        dd[j&x]=1;
                        res[j&x]=res[j];
                        res[j&x].push_back({x,'&'});
                        if ((j&x)==1)
                        {
                                cout<<"2\n";
                                cout<<"| "<<j<<"\n";
                                cout<<"& "<<x;
                                return 0;
                        }
                }
        }
        for (int i=0;i<xxor.size();++i)
        {
                int x=xxor[i];
                for (int j=1;j<=oo;j++)
                if (dd[j])
                {
                        if (dd[j^x]) continue;
                        dd[j^x]=1;
                        res[j^x]=res[j];
                        res[j^x].push_back({x,'^'});
                        if ((j^x)==1)
                        {
                                int tt=res[j^x].size();
                                cout<<tt<<"\n";
                                for (int i=0;i<res[j^x].size();++i)
                                {
                                        data tmp=res[j^x][i];
                                        cout<<tmp.s<<" "<<tmp.x<<"\n";
                                        return 0;
                                }
                        }
                }
        }
        cout<<0;
        return 0;
}
