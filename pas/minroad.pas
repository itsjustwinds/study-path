uses math;
const
        oo=trunc(10e9);
var
        a,b:array[0..300000] of longint;
        k:array[0..300000] of longint;
        i,j,n,tu,tr:longint;
        kq:int64;
procedure sort(l,r:longint);
var     u,v,x,t:longint;
begin
        u:=l;v:=r;x:=k[l+random(r-l+1)];
        repeat
                while k[u]<x do inc(u);
                while k[v]>x do dec(v);
                if u<=v then
                begin
                        t:=k[u];k[u]:=k[v];k[v]:=t;
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        t:=b[u];b[u]:=b[v];b[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(u,r);
        if l<v then sort(l,v);
end;
procedure nhap;
var     x,w:longint;
begin
        readln(n,tu,tr);
        for i:=1 to n do
        begin
                readln(x,w);
                k[i]:=x;
                a[i]:=0;b[i]:=0;
                if w=1 then inc(a[i])
                else inc(b[i]);
        end;
        sort(1,n);
        for i:=1 to n do
        begin
                a[i]:=a[i-1]+a[i];
                b[i]:=b[i-1]+b[i];
        end;
end;
procedure xuly;
var     x:longint;
begin
        x:=1;kq:=oo;
        for i:=tu+tr to n do
                for j:=x to i-tu-tr+1 do
                if (a[i]-a[j-1]>=tu) and (b[i]-b[j-1]>=tr) then
                begin
                        x:=j+1;
                        kq:=min(kq,k[i]-k[j]);
                end
                else break;
        if kq<>oo then writeln(kq)
        else writeln(-1);
end;
begin
        {assign(input,'minroad.inp');
        assign(output,'minroad.out');
        reset(input);
        rewrite(output);}
        nhap;
        xuly;
        {close(input);
        close(output);}
end.
