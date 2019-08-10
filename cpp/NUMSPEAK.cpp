#include<bits/stdc++.h>
using namespace std;
string s,gt[105],res;
string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}

string sub(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    bool neg=false;
    if(a<b)
    {
        swap(a,b);
        neg=true;
    }
    int borrow=0;
    for(int i=a.length()-1; i>=0;i--)
    {
        int tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp%10 + 48) + res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    if(neg) res="-"+res;
    return res;
}

string mul(string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}
bool cmp(string a,string b)
{
        if (a.length()!=b.length()) return a.length()>b.length();
        for (int i=0;i<(int)a.length();i++)
                if (a[i]!=b[i]) return a[i]>b[i];
                return 1;
}
string to_str(int a)
{
        string tmp;
        while(a)
        {
                tmp=char(a%10+'0')+tmp;
                a/=10;
        }
        return tmp;
}
void process1()
{
        int len=0;
        for (int i=1;;i++)
        {
                //cout<<s<<" "<<gt[i]<<" "<<i<<"\n";
                if (!cmp(s,gt[i])) break;
                else ++len;
        }
        len++;
        for (int i=len;i>=1;i--)
        {
                int k=0;
                for (int j=1;j<=26;j++)
                {
                        //cout<<s<<" "<<gt[i-1]<<" "<<to_str(j)<<"\n";
                        if (!cmp(s,mul(gt[i-1],to_str(j)))) break;
                        k=j;
                }
                cout<<char(k+'a'-1);
                s=sub(s,mul(gt[i-1],to_str(k)));
        }
        cout<<"\n";
}
void process2()
{
        int now=s.length()-1;
        for (int i=0;i<s.length();i++)
        {
                int k=s[i]-'a'+1;
                string tmp=gt[now];
                for (int j=2;j<=k;j++)
                        tmp=add(tmp,gt[now]);
                --now;
                res=add(res,tmp);
        }
        string ans="";
        int dem=0;
        for (int i=res.length()-1;i>=0;--i)
        {
                ++dem;
                ans=res[i]+ans;
                if (dem==3)
                {
                        if (i==0) break;
                        dem=0;
                        ans="."+ans;
                }
        }
        cout<<ans<<"\n";
}
int main()
{
        freopen("NUMSPEAK.inp","r",stdin);
        freopen("NUMSPEAK.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        gt[0]="1";
        for (int i=1;i<=70;i++)
        {
                string tmp=to_str(26);
                //cout<<gt[i-1]<<" "<<tmp<<" "<<i<<"\n";
                gt[i]=mul(gt[i-1],tmp);
                //cout<<gt[i]<<" "<<i<<"\n";
        }
        while(1)
        {
                cin>>s;
                if (s[0]=='*') break;
                if (s[0]>='0'&&s[0]<='9')
                {
                        process1();
                }
                else
                {
                        res="0";
                        process2();
                }
        }
}
//30346075288844794133535331
//a`svqaaf`fwyvrfhsci
//zsvqaaezfwyvrfhsci
