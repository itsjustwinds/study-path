const
        fi='tvshow.inp';
        fo='tvshow.out';
var
        a,b:array [1..50001] of longint;
        i,j,d,n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
        begin
                read(f,a[i],b[i]);
        end;
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[l+random(l div 2)];
        repeat
        while a[u]<x do inc(u);
        while a[v]>x do dec(v);
        if u<=v then
        begin
                t:=a[u];a[u]:=a[v];a[v]:=t;
                t:=b[u];b[u]:=b[v];b[v]:=t;
                inc(u);dec(v);
        end;
        until u>v;
        if l<v then sort(l,v);
        if u<r then sort(u,r);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,n);
        for j:=1 to n-1 do
                for i:=j+1 to n do
                        if b[j]>a[i] then
                        inc(d)
                        else break;
        write(f,d);
        close(f);
end;
begin
        nhap;
        xuly;
end.
