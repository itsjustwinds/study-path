#include<bits/stdc++.h>
using namespace std;
int n,k,res,cnt;
struct trie
{
            int child[256],fi;
};
trie a[1000005];
string s;
void insert(string s)
{
            int now=1;
            int len=s.length();
            for (int i=0; i<len; ++i)
            {
                        int k=s[i];
                        if (a[now].child[k]==0) a[now].child[k]=++cnt;
                        now=a[now].child[k];
            }
            if (a[now].fi==0) ++res;
            a[now].fi=1;
}
int main()
{
            freopen("VMSORT.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>k;
            cnt=1;
            while(k--)
            {
                        cin>>n;
                        for (int i=1; i<=n; ++i)
                        {
                                    cin>>s;
                                    insert(s);
                        }
            }
            cout<<res;
            return 0;
}
