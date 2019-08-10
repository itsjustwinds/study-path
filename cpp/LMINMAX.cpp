#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn],n,d,res;
void go()
{
        deque<int > qmin;
        deque<int > qmax;
        while(!qmin.empty()) qmin.pop_back();
        while(!qmax.empty()) qmax.pop_back();
        int start=1;
        for (int i=1; i<=n; ++i)
        {
                while(!qmin.empty()&&a[qmin.back()]>a[i]) qmin.pop_back();
                while(!qmax.empty()&&a[qmax.back()]<a[i]) qmax.pop_back();
                qmin.push_back(i);
                qmax.push_back(i);
                while(a[qmax.front()]-a[qmin.front()]>d)
                {
                        ++start;
                        while(!qmax.empty()&&qmax.front()<start) qmax.pop_front();
                        while(!qmin.empty()&&qmin.front()<start) qmin.pop_front();
                }
                res=max(res,i-start+1);
        }
}
int main()
{
        freopen("LMINMAX.inp","r",stdin);
        scanf("%d%d",&n,&d);
        for (int i=1; i<=n; ++i)
                scanf("%d",&a[i]);
        go();
        printf("%d",res);
        return 0;
}
