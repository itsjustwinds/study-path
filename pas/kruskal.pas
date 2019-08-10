uses math;
const
        maxn=trunc(1e5);
        maxm=5*trunc(1e6);

type    canh=record u,v,w:longint; end;

var     f,g:text;
        e:array[1..maxm] of canh;
        n,m,kq:longint;
        h,p:array[1..maxn] of longint;

procedure nhap;
var i:longint;
begin
    readln(n,m);
    for i:=1 to m do readln(e[i].u,e[i].v,e[i].w);
end;

procedure sort(l,r:longint);
var u,x,v:longint;
    t:canh;
begin
    u:=l;   v:=r;   x:=e[l+random(r-l+1)].w;
    repeat
        while e[u].w<x do inc(u);
        while e[v].w>x do dec(v);
        if u<=v then
        begin
            t:=e[u];    e[u]:=e[v];     e[v]:=t;
            inc(U);     dec(v);
        end;
    until u>v;
    if l<v then sort(l,v);
    if u<r then sort(u,r);
end;

function findroot(u:longint):longint;
begin
    while p[u]<>u do u:=p[u];
    exit(u);
end;

procedure union(ru,rv:longint);
begin
    if h[ru]>h[rv] then p[rv]:=ru
    else
    begin
        p[ru]:=rv;
        h[rv]:=max(h[rv],h[ru]+1);
    end;
end;

procedure xuly;
var i,j,ru,rv:longint;
begin
    for i:=1 to n do
    begin
        h[i]:=0;
        p[i]:=i;
    end;
    //randomize;
    sort(1,m);
    i:=1;   j:=0;  kq:=0;
    while j<n-1 do
    begin
        ru:=findroot(e[i].u);
        rv:=findroot(e[i].v);
        if ru<>rv then
        begin
            inc(j);
            kq:=kq+e[i].w;
            writeln(e[i].u,' ',e[i].v,' ',e[i].w);
            union(ru,rv);
        end;
        inc(i);
    end;
    writeln(kq);
end;
begin
        assign(input,'kruskal.inp');
        assign(output,'kruskal.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
