const
        fi='equation.inp';
        fo='equation.out';
var
        n,a,b,c,d:longint;
        f,g:text;
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
procedure xuat;
begin
        d:=0;
        for a:=2 to n div 3 do
        if nt(a) then
                for b:=a to (n-a) div 2 do
                if nt(b) then
                        if nt(n-a-b) then inc(d);
        writeln(g,d);
end;
procedure  nhap;
begin
        assign(f,fi);
        reset(f);
        assign(g,fo);
        rewrite(g);
        while not (eof(f)) do
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