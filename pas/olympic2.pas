const
        fi='olympic.inp';
        fo='olympic.out';
var
        a,b:array [1..100001] of longint;
        n,i,j,d:longint;
        t:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,t);
        for i:=1 to n do
                readln(f,a[i],b[i]);
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,t,x:longint;
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
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,n);
        d:=0;
        if t<a[1] then
        begin
                write(f,d);
                close(f);
                exit;
        end;
        for i:=1 to n do
                if t>=a[i] then
                begin
                        t:=t+b[i];
                        inc(d);
                end
                else begin
                        write(f,d);
                        break;
                end;
        close(f);
end;
begin
        nhap;
        xuly;
end.
