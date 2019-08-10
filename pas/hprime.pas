const
        fi='hprime.inp';
        fo='hprime.out';
var     n,h:longint;
        f:text;
procedure       nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,h);
        close(f);
end;
function        nt(n:longint):boolean;
var     i:longint;
begin   nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
function        tong(n:longint):longint;
begin

        tong:=0;
        while n<>0 do
        begin
                tong:=tong+(n mod 10);
                n:=n div 10;
        end;
end;
procedure       xuly;
var     dem,i:longint;
begin
        assign(f,fo);
        rewrite(f);
        dem:=0;
        for i:=2 to n do
                if nt(i) then
                        if tong(i)=h then inc(dem);
        writeln(f,dem);
        for i:=2 to n do
                if nt(i) then
                        if tong(i)=h then writeln(f,i);
        close(f);
end;
begin
        nhap;
        xuly;
end.