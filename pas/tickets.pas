const
        fi='tickets.inp';
        fo='tickets.out';
var
        n,k,p1,p2:int64;
        kq:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,n,k,p1,p2);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        kq:=(n div k)*p2;
        n:=n mod k;
        kq:=kq+n*p1;
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuat;
end.