const
        fi='doben.inp';
        fo='doben.out';
var
        n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function tich(x:longint):longint;
begin   tich:=1;
        while x<>0 do
        begin
                tich:=tich*(x mod 10);
                x:=x div 10;
        end;
end;
function doben(x:longint):longint;
var dem:longint;
begin   dem:=0;
        while x>=10 do
        begin
                x:=tich(x);
                inc(dem);
        end;
        doben:=dem;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        write(f,doben(n));
        close(f);
end;
begin
        nhap;
        xuat;
end.
