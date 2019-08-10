const
        fi='race.inp';
        fo='race.out';
var
        t1,t2,v1,v2:int64;
        x,x1,x2:int64;
        kq1,kq2:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,t1,v1,t2,v2);
        read(f,x);
        close(f);
end;
procedure xuat;
begin
        assign(f,fO);
        rewrite(f);
        x1:=0;x2:=0;
        while x1<x do
        begin
                x1:=x1+t1*v1;
                kq1:=kq1+2*t1;
        end;
        while x2<x do
        begin
                x2:=x2+t2*v2;
                kq2:=kq2+x*t2;
        end;
        if kq1>kq2 then write(f,'first');
        if kq2>kq1 then write(f,'second');
        if kq1=kq2 then write(f,'draw');
        close(f);
end;
begin
        nhap;
        xuat;
end.

