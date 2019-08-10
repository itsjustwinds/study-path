var
        a:array[1..100000] of longint;
        n,m,i,j:longint;
        res:int64;
procedure sort(l,r:longint);
var     u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[l+random(r-l+1)];
        repeat
                while a[u]<x do inc(u);
                while a[v]>x do dec(v);
                if u<=v then
                begin
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(u,r);
        if l<v then sort(l,v);
end;
function find(x,u,v:longint):longint;
var     i,j,t,tmp:longint;
begin
        if u>v then exit(0);
        tmp:=(u+v) div 2;
        t:=a[(u+v)div 2];
        if x<t then exit(find(x,u,tmp-1));
        if x>t then exit(find(x,tmp+1,v));
        if x=t then exit(1+find(x,tmp+1,v));
end;
procedure nhap;
begin
        readln(n,m);
        for i:=1 to n do
        read(a[i]);
        sort(1,n);
end;
procedure xuly;
var     tmp:longint;
begin
        res:=0;
        for i:=1 to m do
                for j:=1 to n do
                        if a[j]<=i div 2 then
                        inc(res,find(i-a[j],j+1,n))
                        else break;
        writeln(res);
end;
begin
        assign(input,'fm.inp');
        assign(output,'fm.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
