const
        fi='ddb.inp';
        fo='ddb.out';
var
        k,n,d,x1,x2,i:longint;
        a:array [1..2000000] of longint;
        f,g:text;
function nt(n:longint):boolean;
var  i:longint;
begin
        nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure xuat;
begin
        x1:=0;x2:=0;
        for i:=2 to n do
                if nt(i) then inc(x1);
        for i:=2 to 2*n do
                if nt(i) then inc(x2);
        x2:=x2-x1;
        writeln(g,x2);
end;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        assign(g,fo);
        rewrite(g);
        readln(f,k);
        for i:=1 to k do
        begin
                readln(f,n);
                xuat;
        end;
        close(f);
        close(g);
end;
begin
        nhap;
end.