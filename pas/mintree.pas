uses math;
type
        td=record
                x,y,w:longint;
        end;
var
        f:array[1..1000000] of td;
        n,i,j,m:longint;
        root,h:array[1..100] of longint;
procedure sort(l,r:longint);
var     u,v,x:longint;
        t:td;
begin
        u:=l;v:=r;x:=f[l+random(r-l+1)].w;
        repeat
                while f[u].w<x do inc(u);
                while f[v].w>x do dec(v);
                if u<=v then
                begin
                        t:=f[u];f[u]:=f[v];f[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(u,r);
        if l<v then sort(l,v);
end;
procedure nhap;
var     u,v,c:longint;
begin
        readln(n,m);
        for i:=1 to m do
        begin
                readln(u,v,c);
                f[i].x:=u;
                f[i].y:=v;
                f[i].w:=c;
        end;
        sort(1,m);
end;

function find(ru:longint):longint;
begin
        while ru<>root[ru] do ru:=root[ru];
        exit(ru);
end;
procedure union(ru,rv:longint);
begin
        if h[ru]>h[rv] then root[rv]:=ru
        else
        begin
                root[ru]:=rv;
                h[rv]:=max(h[rv],h[ru]+1);
        end;
end;
procedure xuly;
var     ru,rv:longint;
        kq:int64;
begin
        kq:=0;
        for i:=1 to n do
        begin
                h[i]:=0;
                root[i]:=i;
        end;
        i:=1;j:=0;
        while j<n-1 do
        begin
                ru:=find(f[i].x);
                rv:=find(f[i].y);
                if ru<>rv then
                begin
                        inc(j);
                        writeln(f[i].x,' ',f[i].y);
                        inc(kq,f[i].w);
                        union(ru,rv);
                end;
                inc(i);
        end;
        writeln(kq);
end;
begin
        assign(input,'mintree.inp');
        assign(output,'mintree.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.