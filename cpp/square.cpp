#include<bits/stdc++.h>
using namespace std;
int a[5][3],dd[5],ok;
void tryy(int i,int tong,int canh)
{
    if (ok==1) return ;
    for (int j=1;j<=3;j++)
        for (int k=1;k<=2;k++)
        if (dd[i]==0)
    {
        dd[j]=1;
        if (i==1) tryy(i+1,a[j][k],a[j][k]);
        if (i==2)
        {
            if (canh==a[j][k]) tryy(i+1,tong+a[j][k],a[j][k]);
        }
        if (i==3)
        {
            if (canh==a[j][k])
            {
                cout<<"YES";
                ok=1;
                return;
            }
            if (tong==a[j][k])
            {
                cout<<"yes";
                ok=1;
                return;
            }
        }
        dd[j]=0;
    }
}
int main()
{
    freopen("square.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a[1][1]>>a[1][2];
    cin>>a[2][1]>>a[2][2];
    cin>>a[3][1]>>a[3][2];
    tryy(1,0,0);
    if (ok==0) cout<<"NO";
    return 0;
}
