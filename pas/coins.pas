const
        fi='coins.inp';
        fo='coins.out';
var
        a,b:array [1..100000] of int64;
        i:longint;
        m,n:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
                read(f,a[i]);
        readln(f);
        for i:=1 to n do
                read(f,b[i]);
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;v:=r;x:=b[(l+r) div 2];
        repeat
                while b[u]<x do inc(u);
                while b[v]>x do dec(v);
                if u<=v then
                begin
                        t:=b[u];b[u]:=b[v];b[v]:=t;
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if l<v then sort(l,v);
        if u<r then sort(u,r);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,n);
        for i:=1 to n do
                if b[i]-a[i]<=m then m:=m+a[i]
                else break;
        write(f,m);
        close(f);
end;
begin
        nhap;
        xuat;
end.
