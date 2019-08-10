const
        fi='coins.inp';
        fo='coins.out';
var
        n,i,j:longint;
        m:int64;
        a:array [1..100001] of longint;
        b:array [1..100001] of longint;
        c:array [1..100001] of longint;
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
        for i:=1 to n do
                c[i]:=b[i]-a[i];
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;
        v:=r;
        x:=c[(l+r) div 2];
        repeat
                if c[u]<x then inc(u);
                if c[v]>x then dec(v);
                if u<=v then
                begin
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        t:=c[u];c[u]:=c[v];c[v]:=t;
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
        for i:=1 to n do
                if m>=c[i] then m:=m+a[i]
                else break;
        write(f,m);
        close(f);
end;
begin
        nhap;
        xuly;
end.