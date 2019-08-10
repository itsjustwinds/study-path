#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
unordered_map<int,int > m[3];
int n,k,down,top;
vector<int > A,B,C,D,E;
int main()
{
        freopen("RECOGNIZE.inp","r",stdin);
        freopen("RECOGNIZE.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        down=1,top=n;
        for (int i=1;i<=k;++i)
        {
                int x,y;
                cin>>x>>y;
                if (x==down&&(y==1||(m[1][x]!=0))) A.push_back(i);
                if (x==down&&(y==2||(m[2][x]!=0))) B.push_back(i);
                if (x==top&&(y==1||(m[1][x]!=0))) C.push_back(i);
                if (x==top&&(y==2||(m[2][x]!=0))) D.push_back(i);
                m[y][x]=1;
                while(m[1][top]==1&&m[2][top]==1) --top;
                while(m[1][down]==1&&m[2][down]==1) ++down;
                E.push_back(i);
        }
        cout<<A.size()<<" ";
        for (int i=0;i<A.size();++i)
                cout<<A[i]<<" ";
        cout<<"\n";
        cout<<B.size()<<" ";
        for (int i=0;i<B.size();++i)
                cout<<B[i]<<" ";
        cout<<"\n";
        cout<<C.size()<<" ";
        for (int i=0;i<C.size();++i)
                cout<<C[i]<<" ";
        cout<<"\n";
        cout<<D.size()<<" ";
        for (int i=0;i<D.size();++i)
                cout<<D[i]<<" ";
        cout<<"\n";
        cout<<E.size()<<" ";
        for (int i=0;i<E.size();++i)
                cout<<E[i]<<" ";
}
