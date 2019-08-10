const
        fi='tongnt.inp';
        fo='tongnt.out';
var
        n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
end;
function nt(n:longint):boolean;
var     i:longint;
begin
        nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure xuly;
var     a,b,c:longint;
begin
        assign(f,fo);
        rewrite(f);
        for a:=2 to n do
                for b:=a to n do
                        for c:=b to n do
                                if (a+b+c=n) and(nt(a)) and (nt(b)) and (nt(c)) then
                                        writeln(f,a,' ',b,' ',c);
        close(f);
end;
begin
                nhap;
                xuly;
end.

