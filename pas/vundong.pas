const
        fi='vundong.inp';
        fo='vundong.out';
var
        a:array [1..100000] of longint;
        n,i,s,tam,t:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
procedure xoa(x,y:longint);
begin
        for i:=x to y-1 do
                a[i]:=a[i+1];
end;
procedure sort(l,r:longint);
var
        u,v,x:longint;
begin
        u:=l;v:=r;x:=a[(l+r) div 2];
        repeat
                while a[u]<x do inc(u);
                while a[v]>x do dec(v);
                if u<=v then
                begin
                        tam:=a[u];
                        a[u]:=a[v];
                        a[v]:=tam;
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
        s:=0;
        while n>1 do
        begin
                sort(1,n);
                t:=a[1]+a[2];
                s:=s+t;
                a[1]:=t;
                xoa(2,n);
                dec(n);
        end;
        write(f,s);
        close(f);
end;
begin
        nhap;
        xuly;
end.
