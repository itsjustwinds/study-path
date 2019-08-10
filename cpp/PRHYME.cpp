#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int n,cnt,res,trc[1000005];
struct trie
{
            int child[26];
            int cnt,con;
};
vector<int> k[1000005];
trie a[1000005];
string s[maxn];
bool cmp(string a,string b)
{
            int len=a.length();
            for (int i=0; i<len; i++)
                        if (a[i]!=b[i])
                        {
                                    return a[i]<b[i];
                        }
            return a.length()<b.length();
}
void insert(string s,int x)
{
            int now=1;
            int len=s.length();
            for (int i=len-1; i>=0; i--)
            {
                        k[now].push_back(x);
                        a[now].con=1;
                        int kx=s[i]-'a';
                        if (a[now].child[kx]==0) a[now].child[kx]=++cnt;
                        now=a[now].child[kx];
                        a[now].cnt++;
            }
            k[now].push_back(x);
}
void check(string sk)
{
            int now=1;
            int len=sk.length();
            for (int i=len-1; i>=0; i--)
            {
                        int kx=sk[i]-'a';
                        if (a[now].child[kx]==0)
                        {
                                    for (int i=0; i<(int)k[now].size(); i++)
                                    {
                                                if (s[k[now][i]]==sk) continue;
                                                res=k[now][i];
                                                return;
                                    }
                        }
                        trc[a[now].child[kx]]=now;
                        now=a[now].child[kx];
            }
            int xxx=0;
            if (a[now].con==0)
            {
                        now=trc[now];
                        xxx=1;
            }
            while (k[now].size()==1&&xxx) now=trc[now];
            for (int i=0; i<(int)k[now].size(); i++)
            {
                        if (s[k[now][i]]==sk) continue;
                        res=k[now][i];
                        return;
            }
}
int main()
{
            freopen("PRHYME.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            while(1)
            {
                        n++;
                        getline(cin,s[n]);
                        if (s[n]=="")
                        {
                                    n--;
                                    break;
                        }
            }
            cnt=1;
            sort(s+1,s+n+1,cmp);
            for (int i=1; i<=n; i++)
            {
                        insert(s[i],i);
            }
            while(1)
            {
                        string vtx;
                        getline(cin,vtx);
                        if (vtx=="")
                        {
                                    break;
                        }
                        check(vtx);
                        cout<<s[res]<<"\n";
            }
}
