const
        fi='b7.inp';
        fo='b7.out';
var
        i,j,n:longint;
        f:text;

function nt(x:longint):boolean;
var i:longint;
begin
        nt:=false;
        if x<2 then exit; {x < 2 then exit;}
        for i:=2 to trunc(sqrt(x)) do
                if x mod i=0 then exit; {XU LY TREN X KO PHAI TREN N}
        nt:=true;
end;
function sprime(m:longint):boolean;
var i: longint;  {khong can thiet}
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
        for i:=1 to 10000 do {tim trong pham vi 10000}
                if sprime(i) then writeln(f,i,' ');
        close(f);
end;
begin
        xuat;
end.
