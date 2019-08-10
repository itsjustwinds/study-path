var
        a,w,x:array[0..1000] of longint;
        n,d,c,kt,t,i,kq,j,min:longint;
        tg:array[1..1000] of real;
        dd:array[0..1000] of boolean;
procedure nhap;
begin
        readln(n,d,c,kt);
        for i:=1 to n do
                readln(a[i],w[i]);
        c:=c-d;
        kt:=kt-d;
        d:=0;
end;
procedure sort(l,r:longint);
var
        u,v,t:longint;
        x,t2:real;
begin
        u:=l;v:=r;x:=tg[(l+r) div 2];
        repeat
                while tg[u]>x do inc(u);
                while tg[v]<x do dec(v);
                if u<=v then
                begin
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        t:=w[u];w[u]:=w[v];w[v]:=t;
                        t2:=tg[u];tg[u]:=tg[v];tg[v]:=t2;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(u,r);
        if l<v then sort(l,v);
end;
{procedure xuly;
begin
        sort(1,n);
        for i:=1 to n do
                for j:=i to n do
                        if (a[i]>a[j]) and (w[i]=w[j]) then
                        begin
                                t:=a[i];a[i]:=a[j];a[j]:=t;
                                t:=w[i];w[i]:=w[j];w[j]:=t;
                        end;
        t:=0;
        kq:=0;
        for i:=1 to n do
        begin
                t:=t+a[i];
                kq:=kq+abs(t-kt)*w[i];
        end;
        write(kq);
end;}
procedure result;
var     t,kq,i,tg:longint;
begin
        t:=0;
        tg:=0;
        kq:=0;
        for i:=1 to n do
        begin
                tg:=tg+a[x[i]];
                t:=t+abs(tg-kt)*w[x[i]];
        end;
        if t<min then min:=t;
end;
procedure try(i:longint);
var     j:longint;
begin
        for j:=1 to n do
        if dd[j] then
        begin
                x[i]:=j;
                dd[j]:=false;
                if i<>n then
                begin
                try(i+1);
                dd[j]:=true;
                end
                else
                begin
                        result;
                        dd[j]:=true;
                end;
        end;
end;
procedure sub3;
var     kq:longint;
begin
        for i:=1 to n do
                tg[i]:=w[i]/a[i];
        sort(1,n);
        kq:=0;
        t:=0;
        for i:=1 to n do
        begin
                inc(t,a[i]);
                kq:=kq+abs(t-kt)*w[i];
        end;
        write(kq);
end;
procedure sub4;
var     kq,t:longint;
begin
        for i:=1 to n do
                tg[i]:=w[i]/a[i];
        sort(1,n);
        for i:=1 to n div 2 do
        begin
                t:=a[i];a[i]:=a[n-i+1];a[n-i+1]:=t;
                t:=w[i];w[i]:=w[n-i+1];w[n-i+1]:=t;
        end;
        kq:=0;t:=0;
        for i:=1 to n do
        begin
                inc(t,a[i]);
                kq:=kq+abs(t-kt)*w[i];
        end;
        write(kq);
end;
begin
        assign(input,'dbg.inp');
        assign(output,'dbg.out');
        reset(input);
        rewrite(output);
        nhap;
        fillchar(dd,sizeof(dd),true);
        min:=maxlongint;
       { xuly; }
        if n<=8 then
        begin
                try(1);
                write(min);
        end
        else
        begin
                if d=kt then sub3
                else sub4;
        end;
        close(input);
        close(output);
end.
