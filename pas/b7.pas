const
        fi='b7.inp';
        fo='b7.out';
var
        i,j,n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function nt(x:longint):boolean;
var i:longint;
begin
        nt:=false;
        if x=1 then exit;
        for i:=2 to trunc(sqrt(x)) do
                if n mod i=0 then exit;
        nt:=true;
end;
function sprime(m:longint):boolean;
var i:longint;
begin
        sprime:=true;
        while m<>0 do
        if nt(m) then m:=m div 10
        else
        begin
                sprime:=false;
                exit;
        end;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=2 to n do
                if sprime(i) then writeln(f,i,' ');
        close(f);
end;
begin
        nhap;
        xuat;
end.
