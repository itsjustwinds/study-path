uses math;
var
        a:array[1..100000] of longint;
        i,n:longint;
        res:int64;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
                read(a[i]);
end;
procedure sort(l,r:longint);
var     u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[l+random(r-l+1)];
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
procedure swap(u,v:longint);
var     t:longint;
begin
        t:=a[u];a[u]:=a[v];a[v]:=t;
end;
procedure xuly;
begin
        res:=0;
        sort(1,n);
        for i:=1 to (n div 2) do
                res:=res+2*a[n-i+1];
        if n mod 2=1 then
                inc(res,a[(n+1) div 2]+max(0,a[(n+1) div 2]-a[n div 2+2]));
        writeln(res);
end;
begin
        assign(input,'insul.inp');
        assign(output,'insul.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        {close(input);
        close(output);}
end.
