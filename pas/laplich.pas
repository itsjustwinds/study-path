const
        fi='laplich.inp';
        fo='laplich.out';
var
        a,b:array [1..100] of integer;
        n,i,t,s:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,a[i],b[i]);
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,x:longint;
        t:longint;
begin
        u:=l;v:=r;x:=b[(l+r) div 2];
        repeat
                while b[u]>x do inc(u);
                while b[v]<x do dec(v);
                if u<=v then
                begin
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        t:=b[u];b[u]:=b[v];b[v]:=t;
                        inc(u); dec (v);
                end;
        until u>v;
        if l<v then sort(l,v);
        if u<r then sort(u,r);
end;
function max(a,b:longint):longint;
begin
        if a>b then max:=a else max :=b;
end;
procedure xuat;
var
        i:longint;

begin
        assign(f,fo);
        rewrite(f);
        t:=0;s:=0;
        for i:=1 to n do
        begin   s:=s+a[i];
                t:=max(t,s+b[i]);
        end;
        write(f,t);
       { for i:=1 to n do
                writeln(f,a[i],' ',b[i]);}
        close(f);
end;
begin
        nhap;
        sort(1,n);
        xuat;
end.
