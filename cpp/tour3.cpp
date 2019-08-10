#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxN 401
#define inf 1000000000

int n, m, g[maxN][maxN];

void ReadData() {
    for (int i = 0; i < maxN; i++)
        for (int j = 0; j < maxN; j++)
            if (i == j) g[i][j] = 0;
            else g[i][j] = inf;

    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int x, y, r;
        cin>>x>>y>>r;
        g[x][y] = r;
    }
}

void Floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
}

void Queries() {
    int q, x, y;
    cin>>q;
    for (int i = 0; i < q; i++) {
        cin>>x>>y;
        if (g[x][y] == inf)
            cout<<"-1"<<endl;
        else cout<<g[x][y]<<endl;
    }
}

int main() {
    ReadData();
    Floyd();
    Queries();
    return 0;
}
