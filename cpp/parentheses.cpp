#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
char s[maxn];
int d[3],n,dd[3][3][maxn];
int main()
{
    //freopen("parentheses.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        d[0]=0;
        d[1]=0;
        d[2]=0;
        cin>>(s+1);
        n=strlen(s+1);
        if (n%2==1) {
            cout<<"NO\n";
            continue;
        }
        for (int i=1;i<=n;i++)
        {
            if (s[i]=='(')
            {
                d[0]++;
                dd[1][0][d[0]]=d[1];
                dd[2][0][d[0]]=d[2];
            }
            if (s[i]==')')
            {
                if (d[1]!=dd[1][0][d[0]]||d[2]!=dd[2][0][d[0]])
                {
                    cout<<"NO\n";
                    break;
                }
                d[0]--;
            }
            if (s[i]=='[')
            {
                d[1]++;
                dd[0][1][d[1]]=d[0];
                dd[2][1][d[1]]=d[2];
            }
            if (s[i]==']')
            {
                if (d[0]!=dd[0][1][d[1]]||d[2]!=dd[2][1][d[1]])
                {
                    cout<<"NO\n";
                    break;
                }
                d[1]--;
            }
            if (s[i]=='{')
            {
                d[2]++;
                dd[0][2][d[2]]=d[0];
                dd[1][2][d[2]]=d[1];
            }
            if (s[i]=='}')
            {
                if (d[0]!=dd[0][2][d[2]]||d[1]!=dd[1][2][d[2]])
                {
                    cout<<"NO\n";
                    break;
                }
                d[2]--;
            }
        }
        if (d[0]==0&&d[1]==0&&d[2]==0)
        {
            cout<<"YES\n";
        }
    }
}
