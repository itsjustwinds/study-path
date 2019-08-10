const
        fi='numpos.inp';
        fo='numpos.out';
var
        i,k:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,k);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        if k>=4 then k:=k+(k-3)*2;
        write(f,k);
        close(f);
end;
begin
        nhap;
        xuat;
end.
