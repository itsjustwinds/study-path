#include<bits/stdc++.h>
using namespace std;
struct trie
{
    int child[60];
    int pre;
    char str;
};
trie a[1000005];
char res[50];
string s;
int ans,cnt;
int add(int now)
{
    cnt++;
    for (int i=0;i<=60;i++)
        a[cnt].child[i]=0;
    a[cnt].pre=now;
    return cnt;
}
void insert(string s)
{
    int now=0;
    for (int i=0;i<(int)s.length();i++)
    {
        int k=s[i]-'A';
        if (a[now].child[k]==0) a[now].child[k]=add(now);
        now=a[now].child[k];
        a[now].str=s[i];
    }
    ans=ans^now;
}
int main()
{
    freopen("LTPMSEQ.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i_love_u;
    cin>>i_love_u;
    while(i_love_u--)
    {
        cin>>s;
        insert(s);
    }
    int dem=0;
    while(ans)
    {
        res[++dem]=a[ans].str;
        ans=a[ans].pre;
    }
    for (int i=dem;i>=1;i--)
        cout<<res[i];
    return 0;
}
