void dijkstra(int x, int y){
    priority_queue <ii, vector<ii>, greater<ii> > q;
    q.push(ii(0, x));
    For(i, 1, n) d[i]=oo;
    d[x]=0;
    while (!q.empty()){
        int u=q.top().se, du=q.top().fi; q.pop();
        if (du != d[u]) continue;

        if (u == y) break;
        For(i, 0, a[u].size()-1){
            int v=a[u][i].se, dv = a[u][i].fi;
            if (d[v] > d[u] + dv){
                d[v] = d[u] + dv;
                t[v]=u;
                q.push(ii(d[v], v));
            }
        }
    }
}
