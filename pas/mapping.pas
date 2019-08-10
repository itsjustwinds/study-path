const
        fi='mapping.inp';
        fo='mapping.out';
var
        n,i,j,x,y,d:longint;
        kq:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,x,y);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        d:=1;
        kq:=0;
        for i:=1 to y do
        begin
             kq:=kq+d;
             inc(d);
        end;
        d:=y;
        for i:=2 to x do
        begin
                kq:=kq+d;
                inc(d);
        end;
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuly;
end.