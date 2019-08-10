const
        fi='trip.inp';
        fo='trip.out';
var     a:array [1..100000] of longint;
        n,i,j,d:longint;
        f,g:text;
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
var
        dem:longint;
begin
        sort(1,n);
        i:=1;j:=n;dem:=0;
        while i<=j do
        begin
                if a[i]+a[j]<=d then
                begin
                        inc(i);dec(j);inc(dem);
                end
                else
                begin
                        dec(j);inc(dem);
                end;
        end;
        if i=j then inc(dem);
        writeln(g,dem);
end;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        assign(g,fo);
        rewrite(g);
        while not (eof(f)) do
        begin
                readln(f,n,d);
                for i:=1 to n do
                        read(f,a[i]);
                xuat;
        end;
        close(g);
        close(f);
end;
begin
        nhap;
end.