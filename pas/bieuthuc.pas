const
        fi='bieuthuc.inp';
        fo='bieuthuc.out';
var
        a:array [1..100001] of longint;
        t:int64;
        i,n,m,k:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[l+random(r-l+1)];
        repeat
                while a[u]>x do inc(u);
                while a[v]<x do dec(v);
                if u<=v then
                begin
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(u,r);
        if l<v then sort(l,v);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        sort(2,n);
        k:=n-m-1;
        t:=a[1];
        i:=2;
        while k<>0 do
        begin
                t:=t-a[i];
                inc(i);
                dec(k);
        end;
        while m<>0 do
        begin
                t:=t+a[i];
                inc(i);
                dec(m);
        end;
        write(f,t);
       { for i:=1 to n do
                write(f,a[i],' ');  }
        close(f);
end;
begin
        nhap;
        xuly;
end.
