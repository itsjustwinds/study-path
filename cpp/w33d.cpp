#include<bits/stdc++.h>
using namespace std;
struct data
{
    int val[10];
};
vector< vector<data> > a,f;
vector<int> e[100005];
vector<data> vec;
int n,m,res,xi,yi,xj,yj;
data operator +(data a,data b)
{
    data c;
    for (int i=0;i<=9;i++)
        c.val[i]=a.val[i]+b.val[i];
    return c;
}
data operator -(data a,data b)
{
    data c;
    for (int i=0;i<=9;i++)
        c.val[i]=a.val[i]-b.val[i];
    return c;
}
data tinh(int i,int j)
{
    data c;
    if (i!=0&&j!=0)
    {
        data tmp1=f[i-1][j];
        data tmp2=vec[j-1];
        data tmp3=f[i-1][j-1];
        for (int k=0;k<=9;k++)
            c.val[k]=tmp1.val[k]+tmp2.val[k]-tmp3.val[k];
        return c;
    }
    if (i==0&&j==0)
    {
        for (int k=0;k<=9;k++)
            c.val[k]=0;
        return c;
    }
    if (i==0)
    {
        data tmp=vec[j-1];
        for (int k=0;k<=9;k++)
            c.val[k]=tmp.val[k];
        return c;
    }
    if (j==0)
    {
        data tmp=f[i-1][j];
        for (int k=0;k<=9;k++)
            c.val[k]=tmp.val[k];
        return c;
    }
    return c;
}
bool check(data a)
{
    int len=0;
    int ok=0;
    int ok2=0;
    int ok3=0;
    for (int i=0;i<=9;i++)
    {
        len+=a.val[i];
        if (a.val[i]%2==1)
        {
            if (a.val[i]>=3) ok3=1;
            if (!ok) ok=1;
            else return false;
        }
        if (a.val[i]!=0&&a.val[i]%2==0&&i!=0) ok2=1;
    }
    if (len==1) return true;
    if (len==a.val[0]) return false;
    if (ok2) return true;
    if (ok3) return true;
    return false;
}
data get(int xi,int yi,int xj,int yj)
{
    if (xi!=0&&yi!=0) return f[xj][yj]-f[xi-1][yj]-f[xj][yi-1]+f[xi-1][yi-1];
    if (xi==0&&yi==0)
    {
        return f[xj][yj];
    }
    if (xi==0)
    {
        return f[xj][yj]-f[xj][yi-1];
    }
    if (yi==0)
    {
        return f[xj][yj]-f[xi-1][yj];
    }
    data c;
    return c;
}
int main()
{
    freopen("w33d.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int tmp=n*m;
    for (int i=1;i*i<=tmp;i++)
    {
        e[i*i].push_back(i);
        for (int j=i+1;j<=tmp/i;j++)
            e[i*j].push_back(i);
    }
    for (int i=0;i<n;i++)
    {
        vec.clear();
        for (int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            if (x==0&&res==0)
            {
                res=1;
                xi=i;yi=j;
                xj=i;yj=j;
            }
            data tmp=tinh(i,j);
            tmp.val[x]++;
            vec.push_back(tmp);
        }
        f.push_back(vec);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            tmp=(i+1)*(j+1);
            for (int k=tmp;k>=res+1;k--)
            {
                int ok=0;
                for (int s=0;s<(int)e[k].size();s++)
                {
                    int l=e[k][s];
                    int r=k/l;
                    if (l<=i+1&&r<=j+1)
                    {
                        data dm=get(i-l+1,j-r+1,i,j);
                        if (check(dm))
                        {
                            res=k;
                            xi=i-l+1;yi=j-r+1;
                            xj=i;yj=j;
                            ok=1;
                            break;
                        }
                    }
                    swap(l,r);
                    if (l<=i+1&&r<=j+1)
                    {
                        data dm=get(i-l+1,j-r+1,i,j);
                        if (check(dm))
                        {
                            res=k;
                            xi=i-l+1;yi=j-r+1;
                            xj=i;yj=j;
                            ok=1;
                            break;
                        }
                    }
                }
                if (ok) break;
            }
        }
    }
    cout<<res<<"\n";
    cout<<xi<<" "<<yi<<" "<<xj<<" "<<yj;
    return 0;
}
