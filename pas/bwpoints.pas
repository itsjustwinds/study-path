type
        arr=array[1..100000] of longint;
var
        a,b:array[1..100000] of longint;
        i,j,n,kq,trc:longint;
procedure sorta(l,r:longint);
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
        if l<v then sorta(l,v);
        if u<r then sorta(u,r);
end;
procedure sortb(l,r:longint);
var     u,v,x,t:longint;
begin
        u:=l;v:=r;x:=b[l+random(r-l+1)];
        repeat
                while b[u]<x do inc(u);
                while b[v]>x do dec(v);
                if u<=v then
                begin
                        t:=b[u];b[u]:=b[v];b[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if l<v then sortb(l,v);
        if u<r then sortb(u,r);
end;
procedure xuly(a,b:arr);
var     trcb:longint;
begin
        trc:=0;
        trcb:=-maxlongint;
        for i:=1 to n do
        if b[i]>trcb then
                for j:=trc+1 to n do
                        if (a[j]>trcb) then
                        begin
                                inc(kq);
                                if a[j]<b[i] then trcb:=b[i]
                                else trcb:=a[j];
                                trc:=j;
                                break;
                        end;
end;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
                read(a[i]);
        for i:=1 to n do
                read(b[i]);
        sorta(1,n);
        sortb(1,n);
        kq:=0;
        if a[1]<b[1] then xuly(a,b)
        else xuly(b,a);
        writeln(kq);
end;
begin
        {assign(input,'bwpoints.inp');
        assign(output,'bwpoints.out');
        reset(input);
        rewrite(output); }
        nhap;
        {close(input);
        close(output);  }
end.