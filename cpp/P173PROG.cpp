#include<bits/stdc++.h>
using namespace std;
char s[1005];
int n,ok;
int main()
{
    freopen("P173PROG.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ok=0;
        cin>>(s+1);
        int m=strlen(s+1);
        if (m==1) cout<<"BIGGEST"<<"\n";
        else
        {
            for (int i=m; i>1; i--)
            {
                for (int k=i-1; k>=1; k--)
                    if (s[i]>s[k])
                    {
                        swap(s[i],s[k]);
                        string res="";
                        for (int j=1;j<=i;j++)
                            res=res+s[j];
                            char a[1000];
                        int dem=0;
                        for (int j=i+1;j<=m;j++)
                        a[++dem]=s[j];
                        sort(a+1,a+dem+1);
                        for (int j=1;j<=dem;j++)
                            res=res+a[j];
                        cout<<res;
                        cout<<"\n";
                        ok=1;
                    }
                if (ok==1) break;
            }
            if (ok==0) cout<<"BIGGEST"<<"\n";
        }
    }
    return 0;
}
