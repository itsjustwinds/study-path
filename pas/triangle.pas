type
        arr=array[1..1000] of longint;
var
        a,b,c:array[1..1000] of longint;
        q,n,i,j,w:longint;

procedure sorta(l,r:longint);
var     u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[(l+r)div 2];
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
        u:=l;v:=r;x:=b[(l+r)div 2];
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

procedure sortc(l,r:longint);
var     u,v,x,t:longint;
begin
        u:=l;v:=r;x:=c[(l+r)div 2];
        repeat
                while c[u]<x do inc(u);
                while c[v]>x do dec(v);
                if u<=v then
                begin
                        t:=c[u];c[u]:=c[v];c[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if l<v then sortc(l,v);
        if u<r then sortc(u,r);
end;

function find(a:arr;l,r,x,t:longint):longint;
var     tmp:longint;
begin
        if l>r then exit(t);
        tmp:=a[(l+r) div 2];
        if x>tmp then exit(find(a,(l+r) div 2+1,r,x,t));
        if x<tmp then exit(find(a,l,(l+r) div 2-1,x,t));
        if x=tmp then exit(t+1+find(a,l,(l+r) div 2-1,x,0)+find(a,(l+r) div 2+1,r,x,0));
end;
procedure xuly1;
var     t1,t2,t3,i:longint;
        kq:int64;
begin
        kq:=0;
        for i:=1 to n do
        begin
                t1:=a[i];
                t2:=find(b,1,n,t1,0);
                t3:=find(c,1,n,t1,0);
                inc(kq,t2*t3);
        end;
        writeln(kq);
end;

procedure xuly2;
var
        t1,t2,t3,i,d:longint;
        kq:int64;
begin
        kq:=0;
        for i:=1 to n do
        begin
                t1:=a[i];
                t2:=find(b,1,n,t1,0);
                t3:=find(c,1,n,t1,0);
                if t2>0 then
                begin
                        d:=0;
                        for j:=1 to n do
                                if c[j]<(2*t1) then inc(d)
                                else break;
                        if d>0 then inc(kq,t2*d);
                end;
                if t3>0 then
                begin
                        d:=0;
                        for j:=1 to n do
                                if b[j]<(2*t1) then inc(d)
                                else break;
                        if d>0 then inc(kq,t3*(d-t2));
                end;
        end;
        for i:=1 to n do
        begin
                t2:=b[i];
                t3:=find(c,1,n,t2,0);
                t1:=find(a,1,n,t2,0);
                if t3>0 then
                begin
                        d:=0;
                        for j:=1 to n do
                                if a[j]<(2*t2) then inc(d)
                                else break;
                        if d>0 then inc(kq,t3*(d-t1));
                end;
        end;
        writeln(kq);
end;

function check(a,b,c:longint):boolean;
begin
        check:=false;
        if a+c<=b then exit;
        if b+c<=a then exit;
        exit(true);
end;

procedure xuly3;
var     i,j,k,d:longint;
        kq:int64;
        kt:boolean;
begin
        kq:=0;
        for i:=1 to n do
        begin
                d:=0;
                kt:=false;
                for j:=1 to n do
                begin
                        for k:=1 to n do
                                if a[i]+b[j]>c[k] then
                                begin
                                        if check(a[i],b[j],c[k]) then inc(d)
                                end
                                else break;
                end;
                inc(kq,d);
        end;
        writeln(kq);
end;

procedure nhap;
begin
        readln(q);
        while q>0 do
        begin
        dec(q);
        readln(n,w);
        for i:=1 to n do
                read(a[i]);
        for i:=1 to n do
                read(b[i]);
        for i:=1 to n do
                read(c[i]);
        sorta(1,n);
        sortb(1,n);
        sortc(1,n);
        if w=1 then xuly1;
        if w=2 then xuly2;
        if w=3 then xuly3;
        end;
end;
begin
        assign(input,'triangle.inp');
        assign(output,'triangle.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
