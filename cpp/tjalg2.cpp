#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
const int oo = 0x3c3c3c3c;

int n, m, Num[N], Low[N], cnt=0;
vector<int> a[N];
stack<int> st;
int Count=0;

void visit(int u) {
    Low[u]=Num[u]=++cnt;
    st.push(u);

    for (int i=0; int v=a[u][i]; i++)
    if (Num[v])
        Low[u]=min(Low[u], Num[v]);
    else {
        visit(v);
        Low[u]=min(Low[u], Low[v]);
    }

    if (Num[u]==Low[u]) { // found one
        Count++;
        int v;
        while(!st.empty())
        {
            int k=st.top();
            st.pop();
            Num[u]=Low[u]=oo;
            cout<<k<<" ";
        }
        cout<<"\n";
    }
}

main(){
    freopen("tjalg.inp","r",stdin);
    ios::sync_with_stdio(0);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }
    for (int i=1; i<=n; i++)
    a[i].push_back(0);

    for (int i=1; i<=n; i++)
    if (!Num[i]) visit(i);

    cout << Count << endl;
}
