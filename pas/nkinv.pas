var
        a,vt:array[1..60000] of longint;
        n,i,j,res:longint;
procedure sort(l,r:longint);
var u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[l+random(r-l+1)];
        repeat
                while a[u]>x do inc(u);
                while a[v]<x do dec(v);
                if u<=v then
                begin
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        t:=vt[u];vt[u]:=vt[v];vt[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(u,r);
        if l<v then sort(l,v);
end;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(a[i]);
                vt[i]:=i;
        end;
        //sort(1,n);
end;
procedure xuly;
var     u:longint;
begin
        {for i:=1 to n-1 do
        begin
                u:=i;
                while a[u]=a[u+1] do inc(u);
                for j:=u+1 to n do
                        if vt[u]<vt[j] then inc(res);
        end; }
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if a[i]>a[j] then inc(res);
        writeln(res);
end;
begin
        {assign(input,'nkinv.inp');
        assign(output,'nkinv.out');
        reset(input);
        rewrite(output);}
        nhap;
        xuly;
        {close(input);
        close(output);}
end.
