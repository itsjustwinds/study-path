#include<bits/stdc++.h>
#define maxn 17005
using namespace std;
int a[maxn],n,k;
deque<int >q;
int main()
{
        freopen("MINK.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n>>k;\
                for (int i=1;i<=n;++i)
                        cin>>a[i];
                while(!q.empty()) q.pop_back();
                for (int i=1;i<=n;++i)
                {
                        while(!q.empty()&&q.front()<i-k+1) q.pop_front();
                        while(!q.empty()&&a[q.back()]>a[i]) q.pop_back();
                        q.push_back(i);
                        if (i>=k)
                        {
                                cout<<a[q.front()]<<" ";
                        }
                }
                cout<<"\n";
        }
        return 0;
}
