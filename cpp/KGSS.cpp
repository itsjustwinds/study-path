#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n;
struct data
{
            int m1,m2;
};
data st[4*maxn],res;
void build(int id,int l,int r)
{
            if (l==r)
            {
                        st[id].m1=a[l];
                        st[id].m2=0;
                        return;
            }
            int m=(l+r)>>1;
            build(id*2,l,m);
            build(id*2+1,m+1,r);
            int m1=st[id*2].m1;
            int m2=st[id*2].m2;
            int m3=st[id*2+1].m1;
            int m4=st[id*2+1].m2;
            if (m1>m3)
            {
                        st[id].m1=m1;
                        st[id].m2=max(m2,max(m3,m4));
                        return;
            }
            st[id].m1=m3;
            st[id].m2=max(m1,max(m2,m4));
}
void update(int id,int l,int r,int i,int x)
{
            if (l>i||r<i) return;
            if (l==i&&r==i)
            {
                        st[id].m1=x;
                        return;
            }
            int m=(l+r)>>1;
            update(id*2,l,m,i,x);
            update(id*2+1,m+1,r,i,x);
            int m1=st[id*2].m1;
            int m2=st[id*2].m2;
            int m3=st[id*2+1].m1;
            int m4=st[id*2+1].m2;
            if (m1>m3)
            {
                        st[id].m1=m1;
                        st[id].m2=max(m2,max(m3,m4));
                        return;
            }
            st[id].m1=m3;
            st[id].m2=max(m1,max(m2,m4));
}
data get(int id,int l,int r,int i,int j)
{
            if (l>j||r<i)
            {
                        return {0,0};
            }
            if (l>=i&&r<=j)
            {
                        return st[id];
            }
            int m=(l+r)>>1;
            data tmp1=get(id*2,l,m,i,j);
            data tmp2=get(id*2+1,m+1,r,i,j);
            int m1=tmp1.m1;
            int m2=tmp1.m2;
            int m3=tmp2.m1;
            int m4=tmp2.m2;
            data tmp;
            if (m1>m3)
            {
                        tmp.m1=m1;
                        tmp.m2=max(m2,max(m3,m4));
                        return tmp;
            }
            tmp.m1=m3;
            tmp.m2=max(m1,max(m2,m4));
            return tmp;
}
int main()
{
            freopen("KGSS.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n;
            for (int i=1;i<=n;++i) cin>>a[i];
            build(1,1,n);
            int test;
            cin>>test;
            while(test--)
            {
                        char c;
                        int x,y;
                        cin>>c>>x>>y;
                        if (c=='U')
                        {
                                    update(1,1,n,x,y);
                                    continue;
                        }
                        res=get(1,1,n,x,y);
                        cout<<res.m2+res.m1<<"\n";
            }
            return 0;
}
