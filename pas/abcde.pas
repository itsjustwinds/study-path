const
fi='abcde.inp';
fo='abcde.out';
var
        n,i,j:longint;
        a:array[1..100] of int64;
        kq:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
end;
function nt(n:longint):boolean;
var
        i:longint;
begin
        nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure us(n:longint);
var i:longint;
begin
        if nt(n) then inc(a[n])
        else
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then
                begin
                        inc(a[i]);
                        inc(a[n div i]);
                end;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        kq:=1;
        for i:=2 to n do
                us(i);
        for i:=2 to n do
                kq:=kq*(a[i]+1);
        dec(kq);
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuly;
end.
