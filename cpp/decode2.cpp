#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
string res;
string a[10];
char s[maxn];
int n;
int main()
{
    freopen("decode.inp","r",stdin);
    //freopen("decode.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    a[1]="a";
    a[2]="b";
    a[3]="cc";
    a[4]="bbc";
    a[5]="cbc";
    a[6]="abc";
    a[7]="bac";
    a[8]="aac";
    a[9]="cac";
    s[1]='d';
    s[2]='e';
    cin>>(s+3);
    n=strlen(s+1);
    int i=n;
    while(i>=3)
    {
        string tmp1=""+s[i];
        string tmp2=""+s[i-1]+s[i];
        string tmp3=""+s[i-2]+s[i-1]+s[i-2];
        int ok2=0;
            for (int h=1; h<=9; h++)
            {
                if (tmp1==a[h])
                {
                    res=char(h+48)+res;
                    i-=1;
                    ok2=1;
                    break;
                }
                if (tmp2==a[h])
                {
                    res=char(h+48)+res;
                    i-=2;
                    ok2=1;
                    break;
                }
                if (tmp3==a[h])
                {
                    res=char(h+48)+res;
                    i-=3;
                    ok2=1;
                    break;
                }
            }
            if (ok2==0)
            {
                cout<<-1;
                return 0;
            }
    }
        cout<<res;
    return 0;
}
