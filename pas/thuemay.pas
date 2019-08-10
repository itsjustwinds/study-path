const
        fi='thuemay.inp';
        fo='thuemay.out';
var
        a,b:array [1..100000] of longint;
        n,i,l,r,t:longint;
        f:text;
procedure sort(l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[l+random(r div 2)];
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
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,a[i],b[i]);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,n);
        t:=0;
        l:=0;r:=0;
        for i:=2 to n do
        begin
                if a[i]-b[i-1]>t then
                begin
                        l:=b[i-1]+1;
                        r:=a[i]-1;
                        t:=a[i]-b[i-1];
                end;
        end;
        if t=0 then write(f,'khong co')
        else write(f,l,' ',r);
        close(f);
end;
begin
        nhap;
        xuat;
end.
