const
        fi='ddb.inp';
        fo='ddb.out';
var
        n,i,dem,p,j:longint;
        a:array [1..100] of longint;
       f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,a[i]);
        close(f);
end;
function nt(n:longint):boolean;
var i:longint;
begin   nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
        begin
                dem:=0;
                for j:=a[i]+1 to 2*a[i] do
                        if nt(j) then inc(dem);
                writeln(f,dem);
        end;
        close(f);
end;
begin
        nhap;
        xuat;
end.
