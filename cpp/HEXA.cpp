#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,c[50][50],gt[50],sm[50];
int len,res[50],dd[20];
char s[20];
int get(int n)
{
        int d=0;
        for (int i=1;i<=16;i++)
        {
                if (!dd[i]) ++d;
                if (d==n)
                {
                        return i;
                }
        }
}
int main()
{
        freopen("HEXA.inp","r",stdin);
        freopen("HEXA.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        c[0][0]=1;
        for (int i=1;i<=30;i++)
        {
                c[0][i]=1;
        }
        gt[0]=1;
        for (int i=1;i<=10;i++)
                gt[i]=gt[i-1]*i;
        for (int i=1;i<=30;i++)
                for (int j=1;j<=30;j++)
                c[i][j]=c[i-1][j-1]+c[i][j-1];
        len=8;
        //ll sum=0;
        for (int i=8;i>=1;i--)
        {
                ll tmp=15*c[i-1][15]*gt[i-1];
                if (n<tmp) break;
                len--;
                n-=tmp;
        }
        s[1]='F';s[2]='E';s[3]='D';s[4]='C';s[5]='B';s[6]='A';
        s[7]='9';s[8]='8';s[9]='7';s[10]='6';s[11]='5';s[12]='4';
        s[13]='3';s[14]='2';s[15]='1';s[16]='0';
        sm[0]=1;
        for (int i=1;i<len;i++)
        {
                sm[i]=(8+i)*c[i-1][7+i]*gt[i-1];
        }
        for (int i=len;i>=1;i--)
        {
                int x=max(0LL,((n-1)/sm[i-1]))+1;
                n=(n)%sm[i-1];
                res[len-i+1]=get(x);
                dd[res[len-i+1]]=1;
        }
        for (int i=1;i<=len;i++)
                cout<<s[res[i]];
        return 0;
}
