const
        fi='anasum.inp';
        fo='anasum.out';
var
        a:array [1..100000] of longint;
        i,n:longint;
        f:text;
        t:int64;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[(l+r) div 2];
        repeat
                while a[u]<x do inc(u);
                while a[v]>x do dec(v);
                if u<=v then
                begin
                        t:=a[u];
                        a[u]:=a[v];
                        a[v]:=t;
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
        t:=1;
        for i:=1 to n do
                if a[i]<=t then t:=t+a[i];
        write(f,t);
        close(f);
end;
begin
        nhap;
        xuat;
end.
