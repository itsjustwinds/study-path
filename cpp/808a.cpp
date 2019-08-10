#include<bits/stdc++.h>
using namespace std;
int n;
int dem(int x)
{
    int ans=0;
    while(x)
    {
        ans++;
        x/=10;
    }
    return ans;
}
int check(int x)
{
    int dem=1;
    while(x)
    {
        if (x%10)
            dem++;
            x/=10;
    }
    if (dem==1||dem==2) return 1;
    return 0;
}
int pow(int x,int mu)
{
    int res=1;
    for (int i=1;i<=mu;i++)
        res*=x;
    return res;
}
int main()
{
    //freopen("808a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if (check(n))
    {
        cout<<pow(10,dem(n)-1);
        return 0;
    }
    cout<<(n/(pow(10,dem(n)-1))+1)*pow(10,dem(n)-1)-n;
    return 0;
}
