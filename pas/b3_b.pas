const
        fi='b3_b.inp';
        fo='b3_b.out';
var
        n,i:longint;
        a:array [1..100] of longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
function nt(n:longint):boolean;
var i:longint;
begin
        nt:=false;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
                if nt(a[i]) then write(f,a[i],' ');
        close(f);
end;
begin
        nhap;
        xuat;
end.



