#include<bits/stdc++.h>
using namespace std;
int a,b;
char s[10];
int main()
{
    freopen("816a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    int ngca=0;
    for (int i=1; i<=2; i++)
    {
        a=a*10+(s[i]-'0');
    }
    for (int i=4; i<=5; i++)
    {
        b=b*10+(s[i]-'0');
    }
    if (a==23)
    {
        int ngc=0;
        int tmp=a;
        for (int i=1; i<=2; i++)
        {
            ngc=ngc*10+tmp%10;
            tmp/=10;
        }
        if (ngc>b)
        {
            cout<<ngc-b;
            return 0;
        }
        else
        {
            cout<<60-b;
            return 0;
        }
    }
    if (a<=4||a>=10)
    {
        int ngc=0;
        int tmp=a;
        for (int i=1; i<=2; i++)
        {
            ngc=ngc*10+tmp%10;
            tmp/=10;
        }
        if (ngc>=b)
        {
            cout<<ngc-b;
            return 0;
        }
        else
        {
            a+=1;
            ngc=0;
            for (int i=1; i<=2; i++)
            {
                ngc=ngc*10+a%10;
                a/=10;
            }
            cout<<60-a+ngc;
            return 0;
        }
    }
    if (a>4&&a<=9)
    {
        int ngc=0;
        int tmp=a;
        for (int i=1; i<=2; i++)
        {
            ngc=ngc*10+tmp%10;
            tmp/=10;
        }
        if (ngc>b)
        {
            cout<<ngc-b;
            return 0;
        }
        tmp=60*(10-a);
        if (b)
        {
            tmp-=60;
            tmp+=60-b;
        }
        cout<<tmp+1;
        return 0;
    }
    return 0;
}
