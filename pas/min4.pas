const
        fi='min4.inp';
        fo='min4.out';
var
        a,b,c,d:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,a,b,c,d);
        close(f);
end;
function bn(a,b:longint):longint;
begin
        bn:=a;
        if b<bn then bn:=b;

end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        write(f,bn(bn(bn(a,b),c),d));
        close(f);
end;
begin
        nhap;
        xuly;
end.