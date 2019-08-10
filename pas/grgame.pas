var
        a,b:array[1..100] of longint;
        dd:array[1..100] of boolean;
        t,i,j,n,max:longint;
        kq:int64;
function ucln(a,b:longint):longint;
begin
        if a mod b=0 then exit(b)
        else exit(ucln(b,a mod b));
end;
procedure try(i:longint);
var     j:longint;
        tmp:longint;
begin
        for j:=1 to n do
                if dd[j] then
                begin
                        tmp:=kq;
                        kq:=ucln(tmp,a[i]*100+b[j]);
                        if kq<=max then
                        begin
                                kq:=tmp;
                                exit;
                        end;
                        dd[j]:=false;
                        if i=n then
                        begin
                                if kq>max then max:=kq
                        end
                        else try(i+1);
                        dd[j]:=true;
                        kq:=tmp;
                end;
end;
procedure nhap;
begin
        readln(t);
        for i:=1 to t do
        begin
                kq:=1;
                max:=1;
                readln(n);
                fillchar(dd,n,true);
                for j:=1 to n do
                        read(a[j]);
                for j:=1 to n do
                        read(b[j]);
                for j:=1 to n do
                begin
                        kq:=a[1]*100+b[j];
                        dd[j]:=false;
                        try(2);
                        dd[j]:=true;
                end;
                writeln(max);
        end;
end;
begin
        assign(input,'grgame.inp');
        assign(output,'grgame.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
