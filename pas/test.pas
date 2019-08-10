type    arr=array[1..1000] of longint;
var     a,x,res,vt:array[1..1000] of longint;
        dd:array[1..1000] of boolean;
        kt:boolean;
        i,j,n,t,max:longint;
procedure result(x:arr);
var     i,j,k,kq:longint;
        tmp:array[1..1000,1..1000] of longint;
begin
        for i:=1 to n-2 do
                for j:=3 to n do
                        tmp[i,j]:=a[x[i]]+a[x[j]];
        kq:=0;
        for k:=2 to n-1 do
        begin
                for i:=1 to k-1 do
                        for j:=k+1 to n do
                                if tmp[i,j]=2*a[x[k]] then inc(kq);
        end;
        if kq<max then
        begin
                max:=kq;
                for i:=1 to n do
                        res[i]:=x[i];
                if max=0 then kt:=true;
        end;
end;
procedure try(i:longint);
var
        j:longint;
begin
        if kt then exit;
        for j:=1 to n do
                if dd[j] then
                begin
                        x[i]:=j;
                        dd[j]:=false;
                        if i=n then result(x)
                        else try(i+1);
                        dd[j]:=true;
                end;
end;
procedure nhap;
begin
        readln(t);
        for i:=1 to t do
        begin
                kt:=false;
                readln(n);
                fillchar(dd,n,true);
                max:=maxlongint;
                for j:=1 to n do
                begin
                        read(a[j]);
                        res[j]:=j;
                end;
                result(res);
                try(1);
                for j:=1 to n do
                        write(res[j],' ');
                writeln;
        end;
end;
begin
        assign(input,'test.inp');
        assign(output,'test.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.