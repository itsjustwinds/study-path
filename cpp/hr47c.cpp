#include<bits/stdc++.h>
using namespace std;
double xc,yc,xh,yh,x[10],y[10],s[10],sc,timec,times;
int main()
{
    freopen("hr47c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test)
    {
        test--;
        cin>>xh>>yh;
        cin>>xc>>yc>>sc;
        for (int i=1;i<=5;i++)
            cin>>x[i]>>y[i]>>s[i];
        if (xc!=xh&&yc!=yh)
        {
        timec=double(0);
        double tmp1=(sc/abs(xh-xc));
        double tmp2=(sc/abs(yh-yc));
        timec=double(tmp1*tmp1+tmp2*tmp2);
        }
        else{
                if (xc==xh&&yc==yh) timec=0;
        else
            if (xc==xh)
            {
                timec=sc/abs(yh-yc);
            }
            else if (yc==yh) timec=sc/abs(xh-xc);
        }
        times=double(1000000000);
        for (int i=1;i<=5;i++)
        {
            if (xc!=xh&&yc!=yh)
        {
        timec=double(0);
        double tmp1=(s[i]/abs(xh-x[i]));
        double tmp2=(s[i]/abs(yh-y[i]));
        times=double(tmp1*tmp1+tmp2*tmp2);
        }
        else{
                if (x[i]==xh&&y[i]==yh) times=0;
        else
            if (x[i]==xh)
            {
                times=s[i]/abs(yh-y[i]);
            }
            else if (y[i]==yh) times=s[i]/abs(xh-x[i]);
        }
        }
            if (timec>=times) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
    }
    return 0;
}
