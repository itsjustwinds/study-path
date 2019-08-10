const
        fi='nprefix.inp';
        fo='nprefix.out';
var
        n,m,d,kq:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,m,n);
        close(f);
end;
function abc(n:longint):longint;
var     i,d:longint;
begin
        d:=0;
        while n<>0 do
        begin
                inc(d);
                n:=n div 10;
        end;
        abc:=1;
        for i:=1 to d do
        abc:=abc*10;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        kq:=n div abc(m);
        n:=n mod abc(m);
        kq:=kq+n div m;
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuly;
end.