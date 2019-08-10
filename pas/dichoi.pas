const
        fi='dichoi.inp';
        fo='dichoi.out';
var
        n,q,h,d,p,t,kq,x,i,j:longint;
        f:text;
function tien(p,t:longint):longint;
var     i:longint;
begin
        tien:=maxlongint;
        if t>=n then tien:=n*p;
end;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,q,h,d);
        kq:=maxlongint;
        for i:=1 to h do
        begin
                readln(f,p);
                for j:=1 to d do
                begin
                        read(f,x);
                        if tien(p,x)<kq then kq:=tien(p,x);
                        break;
                end;
                readln(f);
        end;
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        if kq<=q then
        write(f,kq)
        else write(f,'O NHA');
        close(f);
end;
begin
        nhap;
        xuly;
end.

