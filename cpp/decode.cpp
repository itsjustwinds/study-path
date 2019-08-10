#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
char s[maxn],a[10][5],len[10],res[maxn];
int ok,dem;
int main()
{
    freopen("decode.inp","r",stdin);
    //freopen("decode.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    a[1][1]='a';
    len[1]=1;
    a[2][1]='b';
    len[2]=1;
    a[3][1]='c';
    a[3][2]='c';
    len[3]=2;
    a[4][1]='b';
    a[4][2]='b';
    a[4][3]='c';
    len[4]=3;
    a[5][1]='c';
    a[5][2]='b';
    a[5][3]='c';
    len[5]=3;
    a[6][1]='a';
    a[6][2]='b';
    a[6][3]='c';
    len[6]=3;
    a[7][1]='b';
    a[7][2]='a';
    a[7][3]='c';
    len[7]=3;
    a[8][1]='a';
    a[8][2]='a';
    a[8][3]='c';
    len[8]=3;
    a[9][1]='c';
    a[9][2]='a';
    a[9][3]='c';
    len[9]=3;
    cin>>(s+3);
    int n=strlen(s+3);
    s[1]='d';
    s[2]='e';
    int i=n+2;
    dem=maxn;
    while(i>=3)
    {
        ok=0;
        char tmp1[5],tmp2[5],tmp3[5];
        tmp1[1]=s[i];
        tmp2[2]=s[i];
        tmp2[1]=s[i-1];
        tmp3[3]=s[i];
        tmp3[2]=s[i-1];
        tmp3[1]=s[i-2];
        for (int j=1; j<=9; j++)
        {
            if (len[j]==1)
                for (int k=1; k<=1; k++)
                {
                    if (tmp1[k]!=a[j][k]) break;
                    if(k==1)
                    {
                        res[--dem]=char(j+48);
                        i--;
                        ok=1;
                    }
                }

            if (ok==1) break;
            if (len[j]==2)
                for (int k=1; k<=2; k++)
                {
                    if (tmp2[k]!=a[j][k]) break;
                    if(k==2)
                    {
                        res[--dem]=char(j+48);
                        i-=2;
                        ok=1;
                    }
                }

            if (ok==1) break;
            if (len[j]==3)
                for (int k=1; k<=3; k++)
                {
                    if (tmp3[k]!=a[j][k]) break;
                    if(k==3)
                    {
                        res[--dem]=char(j+48);
                        i-=3;
                        ok=1;
                    }
                }
            if (ok==1) break;
        }
        if (ok==0)
        {
            cout<<-1;
            return 0;
        }
    }
    for (int i=dem; i<=maxn-1; i++)
        cout<<res[i];
    return 0;
}
