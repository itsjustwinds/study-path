const
        fi='olympic.inp';
        fo='olympic.out';
var
        a,b:array [1..100000] of longint;
        n,i,kq,dem:longint;
        c:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,c);
        for i:=1 to n do
                readln(f,a[i],b[i]);
        close(f);
end;
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
        dem:=0;
        if c<a[1] then
        begin
                write(f,dem);
                close(f);
                exit;
        end;
        for i:=1 to n do
        begin
                if c>=a[i] then
                begin
                        c:=c+b[i];
                        inc(dem);
                end
                else break;
        end;
        write(f,dem);
        close(f);
end;
begin
        nhap;
        xuat;
end.
