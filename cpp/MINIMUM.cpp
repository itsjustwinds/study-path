#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn],n,k;
deque<int > q;
int main()
{
        freopen("MINIMUM.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        int start=-k+1;
        for (int i=1;i<=n;++i)
        {
                while(!q.empty()&&a[q.back()]>a[i]) q.pop_back();
                q.push_back(i);
                ++start;
                if (start>=1)
                {
                        while(!q.empty()&&q.front()<start) q.pop_front();
                        cout<<a[q.front()]<<"\n";
                }
        }
        return 0;
}
