{var
        i,j,n,h,k,res1,res2,count:longint;
        a:array[1..100000] of longint;
        x:array[1..100000] of longint;
        dd:array[1..100000] of boolean;
        kq:longint;
procedure nhap;
begin
        readln(n,h);
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
        if u<r then sort(u,r);
        if l<v then sort(l,r);
end;
procedure try(i:longint);
var     j:longint;
        kt:boolean;
begin
        for j:=1 to n+1 do
        if dd[j] then
        begin
                kt:=false;
                if i<>1 then
                if a[j]<a[x[i-1]] then
                begin
                        inc(count);
                        kt:=true;
                end;
                if count=2 then
                begin
                        dec(count);
                        exit;
                end;
                dd[j]:=false;
                x[i]:=j;
                if i=n+1 then inc(kq)
                else try(i+1);
                dd[j]:=true;
                if kt then dec(count);
        end;
end;
procedure xuly;
var     check:boolean;
begin
        kq:=0;
        for k:=0 to n do
        begin
                res1:=0;res2:=0;
                for i:=k downto 1 do
                if a[i]>h then
                begin
                        check:=false;
                        res1:=1;
                        for j:=i-1 downto 1 do
                                if a[j]>a[i] then
                                begin
                                        inc(res1);
                                        check:=true;
                                        break;
                                end;
                        if check then break;
                end;
                for i:=k+1 to n do
                if a[i]<h then
                begin
                        check:=false;
                        res2:=1;
                        for j:=i+1 to n do
                                if a[j]<a[i] then
                                begin
                                        inc(res2);
                                        check:=true;
                                        break;
                                end;
                        if check then break;
                end;
                if res1+res2<2 then inc(kq);
        end;

        writeln(kq);
        kq:=0;
        a[n+1]:=h;
        fillchar(dd,n+1,true);
        sort(1,n);
        count:=0;
        try(1);
        kq:=kq mod 1000000000;
        writeln(kq);
end;
begin
        assign(input,'treeline.inp');
        assign(output,'treeline.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
}
{kq:=n;
        check:=true;
        for i:=n downto 2 do
                if (a[i]<a[i-1]) then
                begin
                        kq:=kq-i+2;
                        check:=false;
                        break;
                end;
        if check then inc(kq);}
var
        a,s:array[1..100000] of longint;
        i,j,n,h:longint;
        res:longint;
procedure nhap;
begin
        readln(n,h);
        for i:=1 to n do
                read(a[i]);
end;
procedure xuly;
var     check:boolean;
begin
        res:=n;
        check:=true;
        for i:=n downto 2 do
                if a[i]<a[i-1] then
                begin
                        res:=res-i+2;
                        check:=false;
                        break;
                end;
        if check then inc(res);
        writeln(res);
        if n=0 then writeln(1)
        else if n=1 then writeln(2)
        else
        begin
                s[3]:=5;
                for i:=4 to n+1 do
                        s[i]:=s[i-1]*i;
                writeln(s[n+1] mod 1000000000);
        end;
end;
begin
        assign(input,'treeline.inp');
        assign(output,'treeline.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.